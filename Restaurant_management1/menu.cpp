#include "menu.h"
#include<limits>
using namespace std;

list<Dish>menu;

void handleInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mainMenu(Database& database) {
    bool exit_program = false;
    int choice;

    do {
        system("cls");

        cout << "\t\t\t--------------------------------" << endl;
        cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t--------------------------------" << endl;
        cout << "\t\t\t 1. Manager" << endl;
        cout << "\t\t\t 2. Staff" << endl;
        cout << "\t\t\t 3. Exit program" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";

        cin >> choice;

        if (cin.fail()) {
            handleInvalidInput();
        }
        else {
            switch (choice) {
            case 1:
                menuManager(database);
                break;

            case 2:
                menuStaff(database);
                break;

            case 3:
                exit_program = true;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (!exit_program);
}

void menuManager(Database& database) {
    int choice;
    bool exit_program = false;

    do {
        system("cls");

        cout << "\t\t\t-----------" << endl;
        cout << "\t\t\t| MANAGER |" << endl;
        cout << "\t\t\t-----------" << endl;
        cout << "\t\t\t 1. Setup Table Number" << endl;
        cout << "\t\t\t 2. New Dish" << endl;
        cout << "\t\t\t 3. Edit Dish" << endl;
        cout << "\t\t\t 4. Delete Dish" << endl;
        cout << "\t\t\t 5. Dish List" << endl;
        cout << "\t\t\t 0. Back to Main Menu" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            handleInvalidInput();
        }
        else {
            switch (choice) {
            case 1: {
                bool ContinueSetup = false;
                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------- Set up table ------------------------------------------------" << endl;
                    cout << "\t\t\tEnter quantity of table you want to set up: ";
                    cin >> database.numTable;
                    if (cin.fail() || database.numTable <= 0) {
                        handleInvalidInput();
                        return;
                    }
                    database.managerData.SetTableNumber(database.numTable);
                    database.staffaData.getNumTable(database.numTable);

                    cout << "1. Back to Set up Table" << endl;
                    cout << "0. Back to Menu" << endl;
                    cout << "Enter The Choice: ";
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueSetup = true;
                    }
                    else if (choice == 0) {
                        ContinueSetup = false;
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                        ContinueSetup = false;
                    }
                } while (ContinueSetup);

                break;
            }

            case 2: {
                bool ContinueAdd = false;

                do
                {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------- Adding The New Dish -------------------------------------------" << endl;
                    database.managerData.NewDish();
                    cout << "1. Back to Set up Table" << endl;
                    cout << "0. Back to Menu" << endl;
                    cout << "Enter The Choice: ";
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueAdd = true;
                    }
                    else if (choice == 0) {
                        ContinueAdd = false;
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                        ContinueAdd = false;
                    }
                } while (ContinueAdd);

                break;
            }

            case 5: {
                bool ValidInput = false;
                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ------------------------------------------------------" << endl;
                    database.managerData.showMenu();
                    cout << endl;

                    cout << "0. Back to Main Menu" << endl;
                    cout << "Enter Your Choice: ";
                    cin >> choice;

                    if (cin.fail() || (choice != 0)) {
                        cout << "Invalid input. Please enter a valid choice (0 to return to the Main Menu)." << endl;
                        handleInvalidInput();
                    }
                    else {
                        ValidInput = true;
                    }

                } while (!ValidInput);

                break;
            }

            case 0:
                exit_program = true;
                break;

            default:
                break;
            }
        }
    } while (!exit_program);
}


void menuStaff(Database& database) {

}