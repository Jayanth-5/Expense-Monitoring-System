#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include <vector>
#include <map>
#include "Expense.h"

// ExpenseManager class to handle expense tracking and budget management
class ExpenseManager {
private:
    std::vector<Expense> expenses;         // List of all expenses
    std::map<std::string, double> budgets; // Budgets per category
public:
    void addExpense(const Expense& expense);               // Add a new expense
    void viewExpenses();                                   // Display all expenses
    void saveToFile(const std::string& filename);          // Save expenses to a CSV file
    void loadFromFile(const std::string& filename);        // Load expenses from a CSV file
    void setBudget(const std::string& category, double amount); // Set budget for a category
    bool isOverBudget(const std::string& category);        // Check if category exceeds budget
    double getTotalSpent();                                // Calculate total spending
    double getTotalSpentByCategory(const std::string& category); // Calculate spending by category
};

#endif