#include "menu.h"
#include<limits>
using namespace std;

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
    
    do
    {
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
        
    } while (choice < 0 || choice >5);

}


void menuStaff(Database& database) {

}

