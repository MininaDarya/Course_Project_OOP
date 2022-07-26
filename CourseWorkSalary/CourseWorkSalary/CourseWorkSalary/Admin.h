#pragma once
#include "Account.h"
#include "ID.h"

using namespace std;

/*Класс Admin
*
* определяет роль и идентификационный номер администратора
* содержит меню возможных для администратора функций
*
* производный класс, наследован от Account
*/

class Admin : public Account {
	ID<int> id; //идентификационный номер
public:
	//конструктор с параметрами
	Admin(string, string, ID<int>);
	//конструктор копирования
	Admin(const Admin&);

	//определение роли
	string getRole() const;

	//меню администратора
	void menu();
};