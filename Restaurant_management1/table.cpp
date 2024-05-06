#include"table.h"
#include<iomanip>

void Table::ResetTable() {
    OrderList.clear();
    cout << "Table reset successful." << endl;
}

void Table::SetStatusTable(Status _status) {
	status = _status;
}

Status Table::GetStatusTable() {
	return status;
}

void Table::SetTableID(int _tableID) {
	TableID = _tableID;
}

int Table::GetTableID() {
	return TableID;
}

void Table::OrderDish(list <Dish> menu) {
    Order neworder;
    bool Found = false;

    int ID_Input;
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;

    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->getDishID() == ID_Input) {
            cout << "Dish Found." << endl;
            neworder.dish = *it;
            cout << "Enter quantity of dish you want: ";
            int quantity;
            cin >> quantity;
            neworder.num = quantity;

            OrderList.push_back(neworder);
            Found = true; 
            break;
        }
    }

    if (!Found) {
        cout << "No Dish Found. Please try again." << endl;
    }
}

void Table::CancelDish() {
    int ID_Input;
    int quantity;
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;

    bool found = false;
    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end(); ++it) {
        if (it->dish.getDishID() == ID_Input) {
            found = true;
            cout << "Dish Found." << endl;
            cout << "Enter quantity of dish you want to cancel: ";
            cin >> quantity;

            if (quantity >= it->num) {
                cout << "Cancelled all " << it->dish.GetName() << " from the order." << endl;
                OrderList.erase(it);
            }
            else {
                it->num -= quantity;
                cout << "Cancelled " << quantity << " " << it->dish.GetName() << " from the order." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "No Dish Found. Please try again." << endl;
    }
}

void Table::EditDish() {
    int ID_Input;
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;

    bool found = false;

    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end(); ++it) {
        if (it->dish.getDishID() == ID_Input) {
            found = true;
            cout << "Dish Found." << endl;

            cout << "Cancelled all " << it->dish.GetName() << " from the order." << endl;
            OrderList.erase(it);
            return;
        }
    }

    if (!found) {
        cout << "No Dish Found in the current order." << endl;
    }

    list<Dish> menu; 
    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->getDishID() == ID_Input) {
            cout << "Dish Found." << endl;
            Order neworder;
            neworder.dish = *it;
            cout << "Enter quantity of dish you want: ";
            int quantity;
            cin >> quantity;
            neworder.num = quantity;

            OrderList.push_back(neworder);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No Dish Found in the menu. Please try again." << endl;
    }
}

void Table::GetOrderList(){
    if (OrderList.empty()) {
        cout << "The list order is empty." << endl;
        return;
    }
    cout << "List order of The Dish" << endl;
    cout << "Ordinals| ID\t\t| Dish Name\t\t| Price\t\t| Quantity\t\t" << endl;
    int stt = 1;
    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end(); ++it) {
        cout << setw(3) << left << stt++ << "\t|  ";
        cout << setw(5) << left << it->dish.getDishID() << "\t|  ";
        cout << setw(15) << left << it->dish.GetName() << "\t|  ";
        cout << setw(5) << left << it->dish.GetPrice() << "\t|  ";
        cout << setw(5) << left << it->num << "\t|  ";
        cout << endl;
    }
}

void Table::GetBill() { 
    int _TotalBill = 0;
    for (auto i : OrderList) {
        _TotalBill += i.dish.GetPrice() * i.num;
    }

    GetOrderList();
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << _TotalBill << endl;
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 1.1 * _TotalBill << endl; 
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    int ans = 0;
    do {
        cout << "\n\n\t\t\t1. Pay away" << endl;
        cout << "\t\t\t2. Turn back" << endl;
        cout << "\t\t\tPlease Enter Your Choice: " << endl;
        cin >> ans;
    } while (ans != 1);

    ResetTable();
}