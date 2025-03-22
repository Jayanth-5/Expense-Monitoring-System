#include "ExpenseManager.h"
#include <iostream>
#include <limits>

int main() {
    ExpenseManager manager;
    manager.loadFromFile("expenses.csv"); // Load existing expenses at startup
    int choice;

    do {
        std::cout << "\nExpense Monitoring System\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Set Budget\n";
        std::cout << "4. Check Budget\n";
        std::cout << "5. Generate Report\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string date, category, description;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter description: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);
            Expense exp(date, amount, category, description);
            manager.addExpense(exp);
            std::cout << "Expense added successfully!\n";
        } 
        else if (choice == 2) {
            manager.viewExpenses();
        } 
        else if (choice == 3) {
            std::string category;
            double amount;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter budget amount: ";
            std::cin >> amount;
            manager.setBudget(category, amount);
            std::cout << "Budget set for " << category << "!\n";
        } 
        else if (choice == 4) {
            std::string category;
            std::cout << "Enter category: ";
            std::cin >> category;
            if (manager.isOverBudget(category)) {
                std::cout << "Over budget for " << category << "\n";
            } else {
                std::cout << "Within budget for " << category << "\n";
            }
        } 
        else if (choice == 5) {
            std::cout << "Total spent: $" << manager.getTotalSpent() << "\n";
        } 
        else if (choice == 6) {
            std::cout << "Saving and exiting...\n";
        } 
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    manager.saveToFile("expenses.csv"); // Save expenses before exiting
    return 0;
}