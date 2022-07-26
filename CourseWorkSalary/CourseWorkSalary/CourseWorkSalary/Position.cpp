#include "Position.h"
#include "Employee.h"

//конструктор с параметрами
Position::Position(int ID, string pos,
	int sal, int rew)
{
	id = ID;
	position = pos;
	salary = sal;
	reward = rew;
}
//конструктор копирования
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

//методы для редактирования
void Position::editSalary()
{
	int data = 0;
	cout << "Оклад: ";
	data = Employee::inputNumber();
	setSalary(data);
}
void Position::editPosition()
{
	string data;
	cout << "Должность: ";
	getline(cin, data);
	setPosition(data);
}
void Position::editReward()
{
	int data = 0;
	cout << "Премия: ";
	data = Employee::inputNumber();
	setReward(data);
}

//редактирование данных должности
void Position::editData()
{
	int edit = 0;
	editMenu();
	bool done = false;
	while (!done)
	{
		cout << "Выберите поле для редактирования\n";
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
			cout << "Такого пункта меню нет. Повторите ввод.";
			break;
		}
		}
	}
}
//меню для редактирования
void Position::editMenu()
{
	cout << "1. Должность\n";
	cout << "2. Оклад\n";
	cout << "3. Премии\n";
	cout << "\n0. Выход из режима редактирования\n";
}

//перегрузка оператора вывода
ostream& operator<< (ostream& os, const Position& P)
{
	return os << "\nID: " << P.getID()
		<< "\nДолжность: " << P.getPosition()
		<< "\nОклад: " << P.getSalary()
		<< "\nПремии: " << P.getReward() << '\n';
}
//перегрузка оператора сравнения
bool operator== (const Position& P1, const Position& P2)
{
	return (P1.getID() == P2.getID());
}
//перегрузка оператора присваивания
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