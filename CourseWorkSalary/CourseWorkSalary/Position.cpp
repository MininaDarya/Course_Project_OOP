#include "Position.h"
#include "Employee.h"

//конструктор с параметрами
Position::Position(int ID, string pos,
	float sal, float rew)
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

void Position::Initialization() 
{
	cout << "Введите ID: ";
	try 
	{
		if (!(cin >> id) ||  id < 0) 
		{
			throw 2;
		}
	}
	catch (int a) 
	{
		if (a == 2) 
		{
			while (!(cin >> id) || id < 0) 
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
	cout << "Введите должность: ";
	cin.ignore();
	getline(cin, position);
	cout << "Введите зарплату: ";
	try 
	{
		if (!(cin >> salary) || salary <= 0)
		{
			throw 4.1;
		}
	}
	catch (double a) 
	{
		if (a == 4.1)
		{
			while (!(cin >> salary) || salary <= 0)
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
	cout << "Введите премию: ";
	cin.ignore();
	try 
	{
		if (!(cin >> reward) || reward <= 0)
		{
			throw 3;
		}
	}
	catch (int a)
	{
		if (a == 3) 
		{
			while (!(cin >> reward) || reward <= 0) 
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

int Position::getID() const
{
	return id;
}
string  Position::getPosition() const
{
	return position;
}
float  Position::getSalary() const
{
	return salary;
}
float Position::getReward() const
{
	return reward;
}

void Position::setPosition(string setPos)
{
	position = setPos;
}
void Position::setSalary(float setSal)
{
	salary = setSal;
}
void Position::setReward(float setRew)
{
	reward = setRew;
}

//методы для редактирования
void Position::editSalary()
{
	float data = 0;
	cout << "Оклад: ";
	try
	{
		if (!(cin >> data) || data <= 0) 
		{
			throw 5;
		}
	}
	catch (int a) 
	{
		if (a == 5) 
		{
			while (!(cin >> data) || data <= 0) 
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
	float data = 0;
	cout << "Премия: ";
	try 
	{
		if (!(cin >> data) || data <= 0) 
		{
			throw 6;
		}
	}
	catch (int a) 
	{
		if (a == 6)
		{
			while (!(cin >> data) || data <= 0)
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