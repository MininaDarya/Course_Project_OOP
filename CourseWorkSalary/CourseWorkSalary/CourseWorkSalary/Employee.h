#pragma once
#include "Account.h"
#include "ID.h"

/*����� Employee
*
* ���������� ���� � ���������� � ����������,
* �������� ���� ��������� ��� ���� �������,
* ������ ��� ��������������
*
* ����������� �����, ���������� �� Account
*/

using namespace std;

class Employee : public Account {
	ID<string> id; //����������������� �����
	string fio; //���
	int age; //�������

	string position; //���������
	int experience; //����

	int numberOfWorkingDays; //���������� ������������ ����
	int numberOfVacationDays; //���������� ��������� (�����������) ����
	int numberOfDaysOnSickLeave; //����������

	int dependents; //���������
public:
	//����������� � �����������
	Employee(string, string, string, ID<string>&, string, int, int, int, int, int, int);
	//����������� �����������
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

	//���������� ������������ ������
	string getRole() const
	{
		return "\n���� ���� - ���������.\n";
	}

	void setFIO(string);
	void setAge(int);
	void setPosition(string);
	void setExperience(int);
	void setNumberOfWorkingDays(int);
	void setNumberOfVacationDays(int);
	void setNumberOfDaysOnSickLeave(int);
	void setDependents(int);

	//������ ��� ��������������
	void editFIO();
	void editAge();
	void editPosition();
	void editExperience();
	void editNumberOfWorkingDays();
	void editNumberOfVacationDays();
	void editNumberOfDaysOnSickLeave();
	void editDependents();

	//���� ��������������
	void editMenu();
	//��������������
	void editData();

	//���� �������� ����������
	void menu();

	static bool isNumber(string tmp) {
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] < 48 || tmp[i] > 57) {
				return false;
			}
		}
		if (tmp.size() == 0)
			return false;
		return true;
	}
	//���� �����
	static int inputNumber() {
		unsigned int num;
		string number;
		while (true) {
			getline(cin, number);
			if (!Employee::isNumber(number)) {
				cout << "������ ���� ������� ����� �����.\n";
			}
			else break;
		}
		num = stoi(number);
		return num;
	}
	//���������� ��������� ������
	friend ostream& operator<< (ostream&, const Employee&);
	//���������� ��������� ���������
	friend bool operator==(const Employee&, const Employee&);
	//���������� ��������� ������������
	Employee& operator= (const Employee&);

};