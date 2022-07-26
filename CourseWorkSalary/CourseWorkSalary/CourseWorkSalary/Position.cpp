#include "Position.h"
#include "Employee.h"

//����������� � �����������
Position::Position(int ID, string pos,
	int sal, int rew)
{
	id = ID;
	position = pos;
	salary = sal;
	reward = rew;
}
//����������� �����������
Position::Position(const Position& P)
{
	id = P.id;
	position = P.position;
	salary = P.salary;
	reward = P.reward;
}

int Position::getID() const
{
	return id;
}
string  Position::getPosition() const
{
	return position;
}
int  Position::getSalary() const
{
	return salary;
}
int Position::getReward() const
{
	return reward;
}

void Position::setPosition(string setPos)
{
	position = setPos;
}
void Position::setSalary(int setSal)
{
	salary = setSal;
}
void Position::setReward(int setRew)
{
	reward = setRew;
}

//������ ��� ��������������
void Position::editSalary()
{
	int data = 0;
	cout << "�����: ";
	data = Employee::inputNumber();
	setSalary(data);
}
void Position::editPosition()
{
	string data;
	cout << "���������: ";
	getline(cin, data);
	setPosition(data);
}
void Position::editReward()
{
	int data = 0;
	cout << "������: ";
	data = Employee::inputNumber();
	setReward(data);
}

//�������������� ������ ���������
void Position::editData()
{
	int edit = 0;
	editMenu();
	bool done = false;
	while (!done)
	{
		cout << "�������� ���� ��� ��������������\n";
		edit = Employee::inputNumber();
		switch (edit)
		{
		case 0:
			return;
		case 1:
		{
			editPosition();
			done = true;
			break;
		}
		case 2:
		{
			editSalary();
			done = true;
			break;
		}
		case 3: {
			editReward();
			done = true;
			break;
		}
		default:
		{
			cout << "������ ������ ���� ���. ��������� ����.";
			break;
		}
		}
	}
}
//���� ��� ��������������
void Position::editMenu()
{
	cout << "1. ���������\n";
	cout << "2. �����\n";
	cout << "3. ������\n";
	cout << "\n0. ����� �� ������ ��������������\n";
}

//���������� ��������� ������
ostream& operator<< (ostream& os, const Position& P)
{
	return os << "\nID: " << P.getID()
		<< "\n���������: " << P.getPosition()
		<< "\n�����: " << P.getSalary()
		<< "\n������: " << P.getReward() << '\n';
}
//���������� ��������� ���������
bool operator== (const Position& P1, const Position& P2)
{
	return (P1.getID() == P2.getID());
}
//���������� ��������� ������������
Position& Position::operator=(const Position& P)
{
	if (this != &P)
	{
		id = P.id;
		position = P.position;
		salary = P.salary;
		reward = P.reward;
	}
	return *this;
}