// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

// Returns true and sets result if the division succeeds.
// Returns false if b is zero (division not performed).
bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Returns true and sets result if the modulus succeeds.
// Returns false if b is zero (modulus not performed).
bool computeModulus(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponentiation(double base, double exponent) {
    return pow(base, exponent);
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;
        cout << endl;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 6) {
            cout << "Error: Invalid choice. Please select a number from 1 to 7." << endl;
            cout << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        cout << fixed << setprecision(2);

        if (choice == 1) {
            cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
        } else if (choice == 2) {
            cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
        } else if (choice == 3) {
            cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
        } else if (choice == 4) {
            double result;
            if (divide(a, b, result)) {
                cout << "Result: " << a << " / " << b << " = " << result << endl;
            } else {
                cout << "Error: Cannot divide by zero." << endl;
            }
        } else if (choice == 5) {
            double result;
            if (computeModulus(a, b, result)) {
                cout << "Result: " << a << " % " << b << " = " << result << endl;
            } else {
                cout << "Error: Cannot compute modulus with zero." << endl;
            }
        } else if (choice == 6) {
            cout << "Result: " << a << " ^ " << b << " = " << exponentiation(a, b) << endl;
        }

        cout << endl;
    }

    return 0;
}
