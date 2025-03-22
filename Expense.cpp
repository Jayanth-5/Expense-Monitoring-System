#include "Expense.h"

// Constructor to initialize an Expense object
Expense::Expense(std::string d, double a, std::string c, std::string desc)
    : date(d), amount(a), category(c), description(desc) {}