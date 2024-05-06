﻿/*
* File: Manager.h
* Author: Hau Than Diep
* Date: 04/26/2024
* Description: This file is a manager header file that program is used for storing manager's information
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include<list>
#include<string>
#include"dish.h"

using namespace std;

/*
* Class: Manager
* Description: This class contains basic properties and methods of a Manager object
*/
class Manager {
private:
	int number_table;
	list<Dish> menu;

public:
	Manager() : number_table(0) {}

	Manager(int& number_table, list<Dish>& menu) : number_table(number_table), menu(menu) {}

	void SetTableNumber(int number); // số bàn nhà hàng có thể phục vụ

	void NewDish(Dish dish); // thêm món mới

	void EditDish(list<Dish>& menu);

	void DeleteDish(list<Dish>& menu);

	void DishList(list<Dish> menu);
};

#endif // !_MANAGER_Hh> menu);