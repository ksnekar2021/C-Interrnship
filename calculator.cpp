#include <iostream>

int main() {
    double n1, n2;
    char oper;

    std::cout << "Welcome to the Calculator!\n";
    std::cout << "Enter the first number: ";
    std::cin >> n1;
    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> oper;
    std::cout << "Enter the second number: ";
    std::cin >> n2;

    switch (oper) {
        case '+':
            std::cout << "Result: " << n1 << " + " << n2 << " = " << n1 + n2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << n1 << " - " << n2 << " = " << n1 - n2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << n1 << " * " << n2 << " = " << n1 * n2 << "\n";
            break;
        case '/':
            if (n2 != 0) {
                std::cout << "Result: " << n1 << " / " << n2 << " = " << n1 / n2 << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation. Please enter one of the following: +, -, *, /\n";
    }

    return 0;
}
