#pragma once
#include "Account.h"
#include "ID.h"

/*Класс Employee
*
* определяет роль и информацию о сотруднике,
* содержит меню возможных для него функций,
* методы для редактирования
*
* производный класс, наследован от Account
*/

using namespace std;

class Employee : public Account {
	ID<string> id; //идентификационный номер
	string fio; //ФИО
	int age; //возраст

	string position; //должность
	int experience; //стаж

	int numberOfWorkingDays; //количество отработанных дней
	int numberOfVacationDays; //количество отпускных (календарных) дней
	int numberOfDaysOnSickLeave; //больничный

	int dependents; //иждивенцы

public:
	//конструктор с параметрами
	Employee(string, string, string, ID<string>&, string, int, int, int, int, int, int);
	//конструктор копирования
	Employee(const Employee&);

	ID<string> getID() const;
	string getFIO() const;
	int getAge() const;
	string getPosition() const;
	int getExperience() const;
	int getNumberOfWorkingDays() const;
	int getNumberOfVacationDays() const;
	int getNumberOfDaysOnSickLeave() const;
	int getDependents() const;

	//реализация виртуального метода
	string getRole() const
	{
		return "\nВаша роль - сотрудник.\n";
	}

	void setFIO(string);
	void setAge(int);
	void setPosition(string);
	void setExperience(int);
	void setNumberOfWorkingDays(int);
	void setNumberOfVacationDays(int);
	void setNumberOfDaysOnSickLeave(int);
	void setDependents(int);

	//методы для редактирования
	void editFIO();
	void editAge();
	void editPosition();
	void editExperience();
	void editNumberOfWorkingDays();
	void editNumberOfVacationDays();
	void editNumberOfDaysOnSickLeave();
	void editDependents();

	//меню редактирования
	void editMenu();
	//редактирование
	void editData();

	//меню действий сотрудника
	void menu();

	static bool isNumber(string tmp)
	{
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] < 48 || tmp[i] > 57)
			{
				return false;
			}
		}
		if (tmp.size() == 0)
			return false;
		return true;
	}
	//ввод числа
	static int inputNumber()
	{
		unsigned int num;
		string number;
		while (true)
		{
			getline(cin, number);
			if (!Employee::isNumber(number))
			{
				cout << "Должно быть введено целое число.\n";
			}
			else break;
		}
		num = stoi(number);
		return num;
	}

	//перегрузка оператора вывода
	friend ostream& operator<< (ostream&, const Employee&);
	//перегрузка оператора сравнения
	friend bool operator==(const Employee&, const Employee&);
	//перегрузка оператора присваивания
	Employee& operator= (const Employee&);
};