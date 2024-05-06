/*
* File: manager.cpp
* Author: Hau Than Diep
* Date: 04/26/2024
* Description: This file contains all the functions/methods to store manager's information
*/

#include"Manager.h"
#include<iomanip>

/*
* Function: SetTable
* Description: This function is used for setting the table
* Input:   number
* Output:  return: none
*/
void Manager::SetTableNumber(int number) {
    number_table = number;
}

/*
* Function: NewDish
* Description: This function is used for creating a new dish
* Input:   dish
* Output:  return: none
*/
void Manager::NewDish(Dish dish) {
    cout << "\t\t\tEnter the new dish name: ";
    cin.ignore();
    string name_;
    cin >> name_;
    dish.SetName(name_);

    int price_;
    bool ValidInput = false;
    do
    {
        cout << "\t\t\tEnter the new price: ";
        cin >> price_;
        if (cin.fail()) {
            cout << "Invalid input! Please enter again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (price_ < 0 || price_ > 100000000) {
            cout << "Invalid choice! Price must be between 0 and 100000000." << endl;
        }
        else {
            ValidInput = true;
        }
    } while (!ValidInput);
    dish.SetPrice(price_);

    menu.push_back(dish);
}

/*
* Function: DeleteDish
* Description: This function is used for Delete a dish
* Input:   dish
* Output:  return: none
*/
void Manager::DeleteDish(list<Dish>& menu) {
    int ID_input;
    cout << "Enter the ID of the dish you want to delete: ";
    cin >> ID_input;

    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->getDishID() == ID_input) {
            it = menu.erase(it);
            cout << "Dish ID: " << ID_input << " has been deleted sucessfully" << endl;
            return;
        }
    }

    cout << "No Dish with ID " << ID_input << " found in the database" << endl;
}

/*
* Function: DishList
* Description: This function is used for Display list of dishes
* Input:	menu
* Output:	none
*/
void Manager::DishList(list<Dish> menu) {
    if (menu.empty()) {
        cout << "The menu is empty." << endl;
        return;
    }
    cout << "List of The Dish" << endl;
    cout << "Ordinals| ID\t\t| Dish Name\t\t| Price\t\t" << endl;

    int stt = 1;
    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        cout << setw(3) << left << stt++ << "\t|  ";
        cout << setw(5) << left << it->getDishID() << "\t|  ";
        cout << setw(15) << left << it->GetName() << "\t|  ";
        cout << setw(5) << left << it->GetPrice() << "\t|  ";
        cout << endl;
    }
}

/*
* Function: EditDish
* Description: This function is used for Edit a dish
* Input:   dish
* Output:  return: none
*/
void Manager::EditDish(list<Dish>& menu) {
    DishList(menu);
    int ID_Input;
    cout << "Enter the ID of the dish you want to modify: ";
    cin >> ID_Input;

    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->getDishID() == ID_Input) {
            cout << " Dish found.Current information : " << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << it->getDishID() << "\t\t\t" << it->GetName() << "\t\t\t" << it->GetPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "Enter the new price: " << endl;
            int NewPrice;
            cin >> NewPrice;
            while (NewPrice < 0 || NewPrice > 100000000) {
                cout << "Invalid choice! Please try again: ";
                cin >> NewPrice;
            }

            it->SetPrice(NewPrice);
            cout << "The price updated successfully!" << endl;
            cout << endl;
            return;
        }
    }

}