#pragma once
#include "Position.h"
#include "Employee.h"

using namespace std;

/* ����� Salary
*
* �������� ���������� � ���������� �����
* ����� ��� ��������
*/

class Salary {
	int numberOfCalendarDays; //���������� ������� ���� � ������
	string month; //�������� ������
public:
	//����������� � �����������
	Salary(string, int);
	//����������� �����������
	Salary(const Salary&);

	int getNumberOfCalendarDays() const;
	string getMonth() const;

	void setNumberOfCalendarDays(int);
	void setMonth(string);

	double calculateSalary(typename Employee, Position);
};