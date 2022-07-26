#pragma once
#include "Position.h"
#include "Employee.h"
#include "Object.h"

using namespace std;

/* Класс Salary
*
* содержит информацию о заработной плате
* метод для рассчета
*/

//использование собственного пространска имен
namespace salary_
{
	class Salary : public Object
	{
		int numberOfCalendarDays; //количество рабочих дней в месяце
		string month; //название месяца

	public:
		//конструктор с параметрами
		Salary(string, int);
		//кноструктор копирования
		Salary(const Salary&);

		void Initialization();

		int getNumberOfCalendarDays() const;
		string getMonth() const;

		void setNumberOfCalendarDays(int);
		void setMonth(string);

		double calculateSalary(typename Employee, Position);
	};
}