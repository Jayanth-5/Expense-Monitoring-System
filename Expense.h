#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

// Expense class to hold data for a single expense
class Expense {
public:
    std::string date;        // Date of the expense (e.g., YYYY-MM-DD)
    double amount;           // Amount spent
    std::string category;    // Category (e.g., Food, Transport)
    std::string description; // Brief description of the expense
    Expense(std::string d, double a, std::string c, std::string desc);
};

#endif