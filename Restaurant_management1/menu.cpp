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
                    cout << "0. Back to Manager Menu" << endl;
                    cout << "Enter The Choice: ";
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "Invalid choice. Please try again." << endl;
                        cout << "Enter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueSetup = true;
                    }
                    else if (choice == 0) {
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
                    cout << "1. Back to Adding The New Dish" << endl;
                    cout << "0. Back to Manager Menu" << endl;
                    cout << "Enter The Choice: ";
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "Invalid choice. Please try again." << endl;
                        cout << "Enter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueAdd = true;
                    }
                    else if (choice == 0) {
                        ContinueAdd = false;
                    }
                } while (ContinueAdd);

                break;
            }
            
            case 3:
            {
                bool ContinueEdit = false;

                do
                {
                    database.managerData.editDish();
                    cout << endl;
                    cout << "1. Back to Edit Dish" << endl;
                    cout << "0. Back to Manager Menu" << endl;
                    cin >> choice;
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "Invalid choice. Please try again." << endl;
                        cout << "Enter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueEdit = true;
                    }
                    else if (choice == 0) {
                        ContinueEdit = false;
                    }
                } while (ContinueEdit);
                break;
            }


            case 5: {
                bool ValidInput = false;
                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ------------------------------------------------------" << endl;
                    database.managerData.showMenu();
                    cout << endl;

                    cout << "0. Back to Manager Menu" << endl;
                    cout << "Enter Your Choice: ";
                    cin >> choice;
                    while (!(cin >> choice) || choice != 0) {
                        cout << endl;
                        cout << "Invalid choice. Please try again." << endl;
                        cout << "Enter Your Choice: ";
                        handleInvalidInput();
                    }
                    if (choice == 0) {
                        ValidInput = false;
                    }
                } while (ValidInput);
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