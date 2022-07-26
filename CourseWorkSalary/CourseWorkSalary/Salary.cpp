#include "Salary.h"

using namespace salary_;

//����������� � �����������
Salary::Salary(string mon, int calendarDays)
{
	month = mon;
	numberOfCalendarDays = calendarDays;
}
//����������� �����������
Salary::Salary(const Salary& S)
{
	month = S.month;
	numberOfCalendarDays = S.numberOfCalendarDays;
}

void Salary::Initialization() 
{
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, month);
	cout << "������� ���������� ����: ";
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
					cout << "�������� cin.fail()" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������! ��������� ����!" << endl
					<< "����: ";
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
	//����� �������
	salary += P.getSalary() * E.getNumberOfWorkingDays() / getNumberOfCalendarDays();
	//������
	salary += P.getReward();
	double averageDailyIncome = 0.0;
	//������������� ���������
	averageDailyIncome = P.getSalary() / 29.7;
	//���������
	salary += averageDailyIncome * E.getNumberOfVacationDays();
	//����������
	salary += averageDailyIncome * E.getNumberOfDaysOnSickLeave() * 0.8;
	salary += averageDailyIncome * ((E.getNumberOfDaysOnSickLeave() > 12) ? E.getNumberOfDaysOnSickLeave() - 12 : 0);
	double experienceCoef = 0.0;
	//�� ����
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
	//��������� �����
	double taxDeduction = 0.0;
	if (salary < 817) 
	{
		taxDeduction = 126;
	}
	//�� ����������
	if (E.getDependents() == 1)
		taxDeduction += 37;
	if (E.getDependents() >= 2)
		taxDeduction += 70 * E.getDependents();
	//���������� �����
	salary = 0.87 * (salary - taxDeduction);
	//� ��������� ����
	salary *= 0.99;
	return salary;
}

//���������� ��������� ������
ostream& operator<< (ostream& os, const Salary& S) 
{
	return os << "\n�����: " << S.getMonth()
		<< "\n���������� ����������� ����: "
		<< S.getNumberOfCalendarDays();
}