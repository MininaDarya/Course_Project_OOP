#pragma once
#include "Position.h"
#include "Employee.h"
#include "Object.h"

using namespace std;

/* ����� Salary
*
* �������� ���������� � ���������� �����
* ����� ��� ��������
*/

//������������� ������������ ����������� ����
namespace salary_
{
	class Salary : public Object
	{
		int numberOfCalendarDays; //���������� ������� ���� � ������
		string month; //�������� ������

	public:
		//����������� � �����������
		Salary(string, int);
		//����������� �����������
		Salary(const Salary&);

		void Initialization();

		int getNumberOfCalendarDays() const;
		string getMonth() const;

		void setNumberOfCalendarDays(int);
		void setMonth(string);

		double calculateSalary(typename Employee, Position);
	};
}