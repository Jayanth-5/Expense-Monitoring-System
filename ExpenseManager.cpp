#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Add an expense to the list
void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

// Display all expenses
void ExpenseManager::viewExpenses() {
    if (expenses.empty()) {
        std::cout << "No expenses recorded yet.\n";
        return;
    }
    for (const auto& exp : expenses) {
        std::cout << "Date: " << exp.date << ", Amount: " << exp.amount
                  << ", Category: " << exp.category << ", Description: " << exp.description << "\n";
    }
}

// Save expenses to a CSV file
void ExpenseManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not save to file " << filename << "\n";
        return;
    }
    for (const auto& exp : expenses) {
        file << exp.date << "," << exp.amount << "," << exp.category << "," << exp.description << "\n";
    }
    file.close();
}

// Load expenses from a CSV file
void ExpenseManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return; // File doesn't exist yet, start with empty list
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, amountStr, category, description;
        std::getline(ss, date, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, category, ',');
        std::getline(ss, description);
        double amount = std::stod(amountStr);
        Expense exp(date, amount, category, description);
        expenses.push_back(exp);
    }
    file.close();
}

// Set a budget for a specific category
void ExpenseManager::setBudget(const std::string& category, double amount) {
    budgets[category] = amount;
}

// Check if spending in a category exceeds the budget
bool ExpenseManager::isOverBudget(const std::string& category) {
    double total = 0;
    for (const auto& exp : expenses) {
        if (exp.category == category) {
            total += exp.amount;
        }
    }
    // If no budget is set, assume unlimited (return false)
    if (budgets.find(category) == budgets.end()) return false;
    return total > budgets[category];
}

// Calculate total spending across all expenses
double ExpenseManager::getTotalSpent() {
    double total = 0;
    for (const auto& exp : expenses) {
        total += exp.amount;
    }
    return total;
}

// Calculate total spending for a specific category
double ExpenseManager::getTotalSpentByCategory(const std::string& category) {
    double total = 0;
    for (const auto& exp : expenses) {
        if (exp.category == category) {
            total += exp.amount;
        }
    }
    return total;
}