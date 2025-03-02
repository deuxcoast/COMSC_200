#include <cmath>
#include <iostream>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {
    /* Complete the function and update the return statement */
    if (wages < 0) {
        wages *= -1;
    }
    if (interest < 0) {
        interest *= -1;
    }
    if (unemployment < 0) {
        unemployment *= -1;
    }
    int agi{wages + interest + unemployment};
    return agi;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
    int deduction{};
    /* Complete the function and update the return statement */
    switch (status) {
        case 0:
            deduction = 6000;
            break;
        case 1:
            deduction = 12000;
            break;
        case 2:
            deduction = 24000;
            break;
        default:
            deduction = 6000;
    }
    return deduction;
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
    /* Complete the function and update the return statement */
    int taxable{agi - deduction};
    if (taxable < 0)
        taxable = 0;

    return taxable;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {
    /* Complete the function and update the return statement */
    double tax_percent{}, flat_tax{};
    double income{static_cast<double>(taxable)};
    if (status == 0 || status == 1) {
        if (taxable < 10001) {
            tax_percent = income * 0.10;
        } else if (taxable < 40001) {
            flat_tax = 1000;
            tax_percent = (income - 10000) * 0.12;
        } else if (taxable < 85001) {
            flat_tax = 4600;
            tax_percent = (income - 40000) * 0.22;
        } else {
            flat_tax = 14500;
            tax_percent = (income - 85000) * 0.24;
        }

    } else if (status == 2) {
        if (taxable < 20001) {
            tax_percent = income * 0.10;
        } else if (taxable < 80001) {
            flat_tax = 2000;
            tax_percent = (income - 20000) * 0.12;
        } else {
            flat_tax = 9200;
            tax_percent = (income - 80000) * 0.22;
        }
    }

    double total_tax{tax_percent + flat_tax};
    total_tax = round(total_tax);

    return static_cast<int>(total_tax);
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
    /* Complete the function and update the return statement */
    if (withheld < 0)
        withheld *= -1;

    return tax - withheld;
}

int main() {
    int wages, interest, unemployment, status, withheld;
    int tax, agi, due, deduction, taxable;

    // Step #1: Input information
    cin >> wages;
    cin >> interest;
    cin >> unemployment;
    cin >> status;
    cin >> withheld;

    // Step #2: Calculate AGI
    agi = CalcAGI(wages, interest, unemployment);
    cout << "AGI: $" << agi << endl;
    deduction = GetDeduction(status);
    cout << "Deduction: $" << deduction << endl;
    taxable = CalcTaxable(agi, deduction);
    cout << "Taxable income: $" << taxable << endl;
    tax = CalcTax(status, taxable);
    cout << "Federal tax: $" << tax << endl;
    due = CalcTaxDue(tax, withheld);
    cout << "Tax due: $" << due << endl;

    return 0;
}
