#include <iostream>
using namespace std;

class Distance {
   public:
    // The no argument constructor initializes a Distance to 0'0".
    Distance();

    // Initialize a Distance to the specified value.
    Distance(int m, double cm);
    Distance(int ft, double in, int mt, double cm);

    // Setters
    void SetFeet(int ft);
    void SetInches(double inches);
    void SetMeters(int m);
    void SetCentimeters(double cm);

    // Getters
    int GetFeet();
    int GetMeters();
    double GetInches();
    double GetCentimeters();

    // Define + that operates on Distance + Distance.
    Distance operator+(const Distance& rhs) const;

    // Define + that operates on Distance + int which means add inches.
    Distance operator+(int rhs);

    // Define + that operates on Distance + double which means add
    // centimeters.
    Distance operator+(double rhs);

    // Define + that operates on int + Distance which means add meters.
    friend Distance operator+(int lhs, Distance& rhs);

    // Define + that operates on double + Distance which means add
    // centimeters.
    friend Distance operator+(double lhs, Distance& rhs);

    // Define stream insertion operator for Distances.
    friend ostream& operator<<(ostream& str, Distance& d);

    // Define stream extraction operator for Distances.
    friend istream& operator>>(istream& str, Distance& d);

   private:
    int feet;
    double inches;
    int meters;
    double centimeters;
};
