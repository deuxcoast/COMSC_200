#include "Distance.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

// Added
const double FEET_IN_ONE_METER = 3.280839895;
const double INCHES_IN_CENTIMETER = 0.393701;
const double INCHES_IN_FEET = 12.0;
const double EPSILON = 0.00001;

std::pair<int, double> convert_metric_to_imperial(int m, double cm);

// The no argument constructor initializes a Distance to 0'0".

Distance::Distance() {
    feet = 0;
    inches = 0.0;
    meters = 0;
    centimeters = 0.0;
}

// Added
// Initialize a Distance to the specified value
Distance::Distance(int m, double cm) {
    meters = m;
    centimeters = cm;

    std::pair<int, double> imperial = convert_metric_to_imperial(m, cm);

    feet = imperial.first;
    inches = imperial.second;
}

// Added
Distance::Distance(int ft, double in, int mt, double cm) {
    feet = ft;
    inches = in;
    pair<int, double> metric = convert_metric_to_imperial(ft, mt);

    if (!(metric.first >= ft - EPSILON && metric.first <= ft + EPSILON) ||
        !(metric.second >= in - EPSILON && metric.second <= in + EPSILON)) {
        // throw an exception if the supplied values for ft and inches do not
        // correspond to the correct converted metric values
        throw "the values supplied do not correspond to the conversion between metric and imperial";
    }

    meters = mt;
    centimeters = cm;
}

// Setters
void Distance::SetFeet(int ft) {
    feet = ft;
}
void Distance::SetInches(double in) {
    inches = in;
}
void Distance::SetMeters(int m) {
    meters = m;
}
void Distance::SetCentimeters(double cm) {
    centimeters = cm;
}

// Getters
int Distance::GetFeet() {
    return feet;
}

int Distance::GetMeters() {
    return meters;
}

double Distance::GetInches() {
    return inches;
}

double Distance::GetCentimeters() {
    return centimeters;
}

// Added
// Define + that operates on Distance + Distance.
Distance Distance::operator+(const Distance& rhs) const {
    int sum_feet;
    double sum_inches;

    sum_feet = feet + rhs.feet;
    sum_inches = inches + rhs.inches;
    if (sum_inches >= 12.0) {
        sum_inches -= 12.0;
        ++sum_feet;
    }

    int sum_meters;
    double sum_centimeters;

    sum_meters = meters + rhs.meters;
    sum_centimeters = centimeters + rhs.centimeters;
    if (sum_centimeters >= 100) {
        sum_centimeters -= 100.0;
        ++sum_meters;
    }
    return Distance(sum_feet, sum_inches, sum_meters, sum_centimeters);
}

// Define + that operates on Distance + int which means add meters.
Distance Distance::operator+(int rhs) {
    return *this + Distance(rhs, 0.0);
}

// Define + that operates on Distance + double which means add centimeters.
Distance Distance::operator+(double rhs) {
    return *this + Distance(0, rhs);
}

// Define + that operates on int + Distance which means add meters.
Distance operator+(int lhs, Distance& rhs) {
    int sum_meters;
    double sum_centimeters;

    sum_meters = lhs + rhs.meters;
    sum_centimeters = rhs.centimeters;
    return Distance(sum_meters, sum_centimeters);
}

// Define + that operates on double + Distance which means add centimeters.
Distance operator+(double lhs, Distance& rhs) {
    return rhs + lhs;
}

// Added
// Define stream insertion operator for Distances.
ostream& operator<<(ostream& str, Distance& d) {
    str << fixed << setprecision(2) << d.feet << "' " << d.inches << "\""
        << "   " << d.meters << "m " << d.centimeters << "cm" << endl;
    return str;
}

// Define stream extraction operator for Distances.
istream& operator>>(istream& str, Distance& d) {
    cout << "Enter a distance in feet: ";
    str >> d.feet;
    cout << "Enter a distance in inches: ";
    str >> d.inches;
    cout << "Enter a distance in meters: ";
    str >> d.meters;
    cout << "Enter a distance in centimeters: ";
    str >> d.centimeters;

    return str;
}

// ADDED
std::pair<int, double> convert_metric_to_imperial(int m, double cm) {
    // Convert meters and centimeters into feet and inches
    double temp_feet = m * FEET_IN_ONE_METER;
    // Calculate the decimal in the meters to feet conversion and store it in
    // temp_inches
    double inches = temp_feet - floor(temp_feet);
    // store the number of feet as feet member in class. round down to closest
    // integer
    int feet = static_cast<int>(floor(temp_feet));
    // Turn this decimal into an inches quantity
    inches = inches * INCHES_IN_FEET;
    // Increment temp_inches to include the cm argument, using the cm to inches
    // conversion
    inches = inches + (cm * INCHES_IN_CENTIMETER);

    // handle case where number of inches exceeds 12
    // use an epsilon to compare floating point numbers
    if (inches >= INCHES_IN_FEET - EPSILON &&
        inches <= INCHES_IN_FEET + EPSILON) {
        // if there is more than 12 inches, then increase the number of feet
        // by the appropriate amount
        int extra_feet = static_cast<int>(inches) / 12;
        feet = feet + extra_feet;

        // decrease temp_inches to mod 12. The number of inches left over
        inches = fmod(inches, INCHES_IN_FEET);
    }

    std::pair<int, double> imperial(feet, inches);
    return imperial;
}
