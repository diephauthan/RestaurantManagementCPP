/*
* File: staff.cpp
* Author: Hau Than Diep
* Date: 04/26/2024
* Description: This file contains all the functions/methods to store staff's information
*/
#include "staff.h"
using namespace std;

void Staff::getNumTable(int _numTable) {
    for (int i = 0; i < (_numTable); i++) {
        Table newTable;
        tableList.push_back(newTable);
    }
}

void Staff::displayTable() {
    cout << "Table ID" << "\t\t";
    for (int i = 0; i < tableList.size(); i++) {
        cout << i + 1 << "\t";
    }

    cout << "\n Status " << "\t\t";
    for (auto it : tableList) {
        if (it.GetStatusTable() == Free) cout << "O" << "\t";
        else cout << "X" << "\t";
    }

    cout << "\n\nX means booked";
    cout << "\nO means free";
}

bool Staff::isFull() {
    for (auto it : tableList) {
        if (it.GetStatusTable() == Free) return false;
    }
    return false;
}

void Staff::chooseTable(int _tableID) {
    for (auto& i : tableList) {
        if (i.GetTableID() == _tableID) {
            i.SetStatusTable(Booked);
        }
    }
}

void Staff::getTableInfo(int _tableID, int type, list <Dish> menu) {
    for (auto& it : tableList) {
        if (it.GetTableID() == _tableID) {
            switch (type) {
            case 1: // gọi
                it.OrderDish(menu);
                break;
            case 2: // hủy
                it.CancelDish();
                break;
            case 3: // thay đổi
                it.EditDish();
                break;
            case 4: // in ra danh sách 
                it.GetOrderList();
                break;
            case 5:
                it.GetBill();
                break;
            default:
                break;
            }
        }
    }
}
