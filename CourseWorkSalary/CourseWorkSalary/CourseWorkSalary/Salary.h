#pragma once
#include "Position.h"
#include "Employee.h"

using namespace std;

/* Класс Salary
*
* содержит информацию о заработной плате
* метод для рассчета
*/

class Salary {
	int numberOfCalendarDays; //количество рабочих дней в месяце
	string month; //название месяца
public:
	//конструктор с параметрами
	Salary(string, int);
	//кноструктор копирования
	Salary(const Salary&);

	int getNumberOfCalendarDays() const;
	string getMonth() const;

	void setNumberOfCalendarDays(int);
	void setMonth(string);

	double calculateSalary(typename Employee, Position);
};