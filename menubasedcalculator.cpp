#include <iostream>
#include <string>
#include <algorithm> // For __gcd
using namespace std;

int userChoice;

// Function to display the menu and get the user's choice
void displayMenu() {
    cout << "Select an operation:\n";
    cout << "1. Calculate Sum of Numbers\n";
    cout << "2. Calculate Difference of Numbers\n";
    cout << "3. Calculate Product of Numbers\n";
    cout << "4. Calculate Division of Numbers\n";
    cout << "5. Calculate HCF (GCD) of Numbers\n";
    cout << "6. Calculate LCM of Numbers\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> userChoice;
}

// Function to validate if the input is a numeric string
bool isValidNumber(const string& str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

// Function to perform the calculation and display the result based on user's choice
void performCalculation(long long num1, long long num2) {
    switch (userChoice) {
        case 1:
            cout << "Sum: " << (num1 + num2) << "\n";
            break;
        case 2:
            cout << "Difference: " << (num1 - num2) << "\n";
            break;
        case 3:
            cout << "Product: " << (num1 * num2) << "\n";
            break;
        case 4:
            if (num2 != 0)
                cout << "Division: " << (num1 / num2) << "\n";
            else
                cout << "Error: Division by zero is not allowed.\n";
            break;
        case 5:
            cout << "HCF (GCD): " << __gcd(num1, num2) << "\n";
            break;
        case 6:
            cout << "LCM: " << (num1 * num2) / __gcd(num1, num2) << "\n";
            break;
        case 7:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    string input1, input2;

    // Get the two numbers from the user
    cout << "Enter two numbers: ";
    cin >> input1 >> input2;

    // Validate the inputs
    if (isValidNumber(input1) && isValidNumber(input2)) {
        long long num1 = stoll(input1);
        long long num2 = stoll(input2);

        // Display the menu and perform the selected operation
        displayMenu();
        performCalculation(num1, num2);
    } else {
        cout << "Invalid input! Please enter numerical values only.\n";
    }

    return 0;
}
