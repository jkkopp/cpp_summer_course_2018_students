#include "Database.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int display_menu();
void do_hire( Database& db );
void do_fire( Database& db );
void do_promote( Database& db );
void do_demote( Database& db );
void print_all_employees( Database& db );
void print_all_current_employees( Database& db );
void print_all_fomer_employees( Database& db );

int main() {
    Database employeeDB;
    bool done = false;

    while ( !done ) {
        int selection = display_menu();
        switch ( selection ) {
        case 0:
            done = true;
            break;
        case 1:
            do_hire( employeeDB );
            break;
        case 2:
            do_fire( employeeDB );
            break;
        case 3:
            do_promote( employeeDB );
            break;
        case 4:
            do_demote( employeeDB );
            break;
        case 5:
            print_all_employees( employeeDB );
            break;
        case 6:
            print_all_current_employees( employeeDB );
            break;
        case 7:
            print_all_fomer_employees( employeeDB );
            break;
        default:
            cerr << "unknown command" << endl;
            break;
        }
    }
}

int display_menu() {
    int selection = 0;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) Demote an employee" << endl;
    cout << "5) List all employees" << endl;
    cout << "6) List all current employees" << endl;
    cout << "7) List all former employees" << endl;
    cout << "0) Quit " << endl;
    cout << endl;
    cout << "-> ";
    cin >> selection;
    return selection;
}

void do_hire( Database& db ) {
    string first_name;
    cout << "First name? ";
    cin >> first_name;

    string last_name;
    cout << "Last name? ";
    cin >> last_name;

    int salary = -1;
    cout << "Salary? ";
    cin >> salary;
    try {
        db.add_employee( first_name, last_name, salary );
        cout << "Employee hired" << endl;
    }
    catch ( const std::exception& exception ) {
        cerr << "Unable to add new employee: " << exception.what() << endl;
    }
}

void do_fire( Database& db ) {
    int employee_number = -1;
    cout << "Employee number ";
    cin >> employee_number;
    try {
        Employee& employee = db.get_employee( employee_number );
        employee.fire();
        cout << "Employee " << employee_number << " terminated." << endl;
    }
    catch ( const std::exception& exception ) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void do_promote( Database& db ) {
    int employee_number = -1;
    cout << "Employee number ";
    cin >> employee_number;

    int raise_amount = 0;
    cout << "How much of a raise? ";
    cin >> raise_amount;
    try {
        Employee& employee = db.get_employee( employee_number );
        employee.promote( raise_amount );
    }
    catch ( const std::exception& exception ) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}

void do_demote( Database& db ) {
    int employee_number = -1;
    cout << "Employee number ";
    cin >> employee_number;

    int demerit_amount = 0;
    cout << "How much of a demerit? ";
    cin >> demerit_amount;
    try {
        Employee& employee = db.get_employee( employee_number );
        employee.demote( demerit_amount );
    }
    catch ( const std::exception& exception ) {
        cerr << "Unable to demote employee: " << exception.what() << endl;
    }
}

void print_all_employees( Database& db ) {
    cout << "All employees -----" << endl;
    db.display();
}

void print_all_current_employees( Database& db ) {
    cout << "Current employees -----" << endl;
    for( Employee e : db.get_hired_employees() ) {
        e.display();
    }
}

void print_all_fomer_employees( Database& db ) {
cout << "Former employees -----" << endl;
    for( Employee e : db.get_fired_employees() ) {
        e.display();
    }
}
