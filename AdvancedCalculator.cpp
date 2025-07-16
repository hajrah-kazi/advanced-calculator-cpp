#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class AdvancedCalculator {
public:
    // Function to convert binary to decimal
    int binaryToDecimal(const string& binary) {
        int decimal = 0;
        int base = 1;  // 2^0

        // Start from the rightmost digit
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += base;
            }
            base *= 2;  // Move to the next power of 2
        }
        return decimal;
    }

    // Function to convert decimal to binary
    string decimalToBinary(int decimal) {
        if (decimal == 0) return "0";
        
        string binary = "";
        while (decimal > 0) {
            binary = to_string(decimal % 2) + binary;  // Prepend binary digit
            decimal /= 2;  // Divide by 2
        }
        return binary;
    }

    // Function to add two numbers
    double add(double a, double b) {
        return a + b;
    }

    // Function to subtract two numbers
    double subtract(double a, double b) {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Function to divide two numbers
    double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    // Function to convert hexadecimal to decimal
    int hexToDecimal(const string& hex) {
        int decimal;
        stringstream ss;
        ss << hex;
        ss >> std::hex >> decimal;  // Correctly use std::hex for hexadecimal input
        return decimal;
    }

    // Function to convert decimal to hexadecimal
    string decimalToHex(int decimal) {
        stringstream ss;
        ss << std::hex << decimal;
        return ss.str();
    }
};

int main() {
    AdvancedCalculator calc;
    int choice;

    do {
        cout << "Advanced Calculator Menu:\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Decimal to Binary\n";
        cout << "3. Hexadecimal to Decimal\n";
        cout << "4. Decimal to Hexadecimal\n";
        cout << "5. Addition\n";
        cout << "6. Subtraction\n";
        cout << "7. Multiplication\n";
        cout << "8. Division\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 0 || choice > 8) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        double a, b;
        string hexValue, binaryValue;

        switch (choice) {
            case 1:  // Binary to Decimal
                cout << "Enter a binary number: ";
                cin >> binaryValue;
                cout << "Decimal: " << calc.binaryToDecimal(binaryValue) << endl;
                break;
            case 2:  // Decimal to Binary
                cout << "Enter a decimal number: ";
                cin >> a;  // Here, using double but can convert to int before passing
                cout << "Binary: " << calc.decimalToBinary(static_cast<int>(a)) << endl;
                break;
            case 3:  // Hexadecimal to Decimal
                cout << "Enter a hexadecimal number: ";
                cin >> hexValue;
                try {
                    cout << "Decimal: " << calc.hexToDecimal(hexValue) << endl;
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 4:  // Decimal to Hexadecimal
                cout << "Enter a decimal number: ";
                cin >> a;
                cout << "Hexadecimal: " << calc.decimalToHex(static_cast<int>(a)) << endl;
                break;
            case 5:  // Addition
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.add(a, b) << endl;
                break;
            case 6:  // Subtraction
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.subtract(a, b) << endl;
                break;
            case 7:  // Multiplication
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.multiply(a, b) << endl;
                break;
            case 8:  // Division
                cout << "Enter two numbers: ";
                cin >> a >> b;
                try {
                    cout << "Result: " << calc.divide(a, b) << endl;
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 0:  // Exit
                cout << "Exiting the calculator." << endl;
                break;
        }

        cout << endl; // For better output formatting
    } while (choice != 0);

    return 0;
}
