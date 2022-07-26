#include "Salary.h"

using namespace salary_;

//конструктор с параметрами
Salary::Salary(string mon, int calendarDays)
{
	month = mon;
	numberOfCalendarDays = calendarDays;
}
//конструктор копирования
Salary::Salary(const Salary& S)
{
	month = S.month;
	numberOfCalendarDays = S.numberOfCalendarDays;
}

void Salary::Initialization() 
{
	cout << "Введите месяц: ";
	cin.ignore();
	getline(cin, month);
	cout << "Введите количество дней: ";
	try 
	{
		if (!(cin >> numberOfCalendarDays) || numberOfCalendarDays <= 0 || numberOfCalendarDays > 31) 
		{
			throw 1;
		}
	}
	catch (int a) 
	{
		if (a == 1) 
		{
			while (!(cin >> numberOfCalendarDays) || numberOfCalendarDays <= 0 || numberOfCalendarDays > 31) 
			{
				if (cin.fail())
					cout << "Работает cin.fail()" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка! Повторите ввод!" << endl
					<< "Ввод: ";
			}
		}
	}
}

int Salary::getNumberOfCalendarDays() const
{
	return numberOfCalendarDays;
}
string Salary::getMonth() const
{
	return month;
}

void  Salary::setNumberOfCalendarDays(int setCalend)
{
	numberOfCalendarDays = setCalend;
}
void  Salary::setMonth(string setMon)
{
	month = setMon;
}

double Salary::calculateSalary(Employee E, Position P) 
{
	double salary = 0.0;
	//общий рассчет
	salary += P.getSalary() * E.getNumberOfWorkingDays() / getNumberOfCalendarDays();
	//премии
	salary += P.getReward();
	double averageDailyIncome = 0.0;
	//среднедневной заработок
	averageDailyIncome = P.getSalary() / 29.7;
	//отпускные
	salary += averageDailyIncome * E.getNumberOfVacationDays();
	//больничный
	salary += averageDailyIncome * E.getNumberOfDaysOnSickLeave() * 0.8;
	salary += averageDailyIncome * ((E.getNumberOfDaysOnSickLeave() > 12) ? E.getNumberOfDaysOnSickLeave() - 12 : 0);
	double experienceCoef = 0.0;
	//за стаж
	if (E.getExperience() < 5)
		experienceCoef = 0.1;
	else
	{
		if (E.getExperience() >= 5 && E.getExperience() < 10)
			experienceCoef = 0.15;
		else
		{
			if (E.getExperience() >= 10 && E.getExperience() < 15)
				experienceCoef = 0.2;
			else
				experienceCoef = 0.3;
		}
	}
	salary += experienceCoef * P.getSalary();
	//налоговый вычет
	double taxDeduction = 0.0;
	if (salary < 817) 
	{
		taxDeduction = 126;
	}
	//за иждивенцев
	if (E.getDependents() == 1)
		taxDeduction += 37;
	if (E.getDependents() >= 2)
		taxDeduction += 70 * E.getDependents();
	//подоходный налог
	salary = 0.87 * (salary - taxDeduction);
	//в страховой фонд
	salary *= 0.99;
	return salary;
}

//перегрузка оператора вывода
ostream& operator<< (ostream& os, const Salary& S) 
{
	return os << "\nМесяц: " << S.getMonth()
		<< "\nКоличество календарных дней: "
		<< S.getNumberOfCalendarDays();
}