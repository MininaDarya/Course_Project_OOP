#include "Employee.h"
#include "ID.h"

//конструктор с параметрами
Employee::Employee(string log, string pass,
	string pos, ID<string>& i, string fi, int ag, int exp,
	int workingDays, int vacationDays, int daysOnSickLeave, int dep) :
	Account(log, pass), id(i)
{
	fio = fi;
	age = ag;
	position = pos;
	experience = exp;
	numberOfWorkingDays = workingDays;
	numberOfVacationDays = vacationDays;
	numberOfDaysOnSickLeave = daysOnSickLeave;
	dependents = dep;
}
//конструктор копирования
Employee::Employee(const Employee& E) :Account((Account&)E), id(E.id)
{
	fio = E.fio;
	age = E.age;
	position = E.position;
	experience = E.experience;
	numberOfWorkingDays = E.numberOfWorkingDays;
	numberOfVacationDays = E.numberOfVacationDays;
	numberOfDaysOnSickLeave = E.numberOfDaysOnSickLeave;
	dependents = E.dependents;
}

ID<string> Employee::getID() const
{
	return id;
}
string Employee::getFIO() const
{
	return fio;
}
int Employee::getAge() const
{
	return age;
}
string Employee::getPosition() const
{
	return position;
}
int Employee::getExperience() const
{
	return experience;
}
int Employee::getNumberOfWorkingDays() const
{
	return numberOfWorkingDays;
}
int Employee::getNumberOfVacationDays() const
{
	return numberOfVacationDays;
}
int Employee::getNumberOfDaysOnSickLeave() const
{
	return numberOfDaysOnSickLeave;
}
int Employee::getDependents() const
{
	return dependents;
}

void Employee::setFIO(string setFi)
{
	fio = setFi;
}
void Employee::setAge(int setAg)
{
	age = setAg;
}
void Employee::setPosition(string setPos)
{
	position = setPos;
}
void Employee::setExperience(int setExp)
{
	experience = setExp;
}
void Employee::setNumberOfWorkingDays(int setWorkingDays)
{
	numberOfWorkingDays = setWorkingDays;
}
void Employee::setNumberOfVacationDays(int setVacationDays)
{
	numberOfVacationDays = setVacationDays;
}
void Employee::setNumberOfDaysOnSickLeave(int setDayOnSickLeave)
{
	numberOfDaysOnSickLeave = setDayOnSickLeave;
}
void Employee::setDependents(int setDep)
{
	dependents = setDep;
}

//методы для редактирования
void Employee::editFIO()
{
	string data;
	cout << "ФИО: ";
	getline(cin, data);
	setFIO(data);
}
void Employee::editAge()
{
	int data;
	cout << "Возраст: ";
	data = Employee::inputNumber();
	setAge(data);
}
void Employee::editExperience()
{
	int data;
	cout << "Стаж: ";
	data = Employee::inputNumber();
	setExperience(data);
}
void Employee::editPosition()
{
	string data;
	cout << "Должность: ";
	getline(cin, data);
	setPosition(data);
}

void Employee::editNumberOfWorkingDays()
{
	int data;
	cout << "Количество отработанных дней: ";
	data = Employee::inputNumber();
	setNumberOfWorkingDays(data);
}
void Employee::editNumberOfVacationDays()
{
	int data;
	cout << "Количество календарных отпускных дней: ";
	data = Employee::inputNumber();
	setNumberOfVacationDays(data);
}
void Employee::editNumberOfDaysOnSickLeave()
{
	int data;
	cout << "Количество календарных дней больничного отпуска: ";
	data = Employee::inputNumber();
	setNumberOfDaysOnSickLeave(data);
}
void Employee::editDependents()
{
	int data;
	cout << "Количество иждивенцев в семье: ";
	data = Employee::inputNumber();
	setDependents(data);
}

//меню для выбора поля редактирования
void Employee::editMenu()
{
	cout << "1. ФИО\n";
	cout << "2. Возраст\n";
	cout << "3. Должность\n";
	cout << "4. Стаж\n";
	cout << "5. Количество отработанных дней\n";
	cout << "6. Количество календарных отпускных дней\n";
	cout << "7. Количество календарных дней больничного отпуска\n";
	cout << "8. Количество иждивенцев в семье\n";
	cout << "\n0. Выйти из режима редактирования\n";
}
//редактирование
void Employee::editData()
{
	int edit = 0;
	bool done = false;
	editMenu();
	while (!done)
	{
		cout << "Выберите поле для редактирования\n";
		edit = Employee::inputNumber();
		//обраотка выбора
		switch (edit)
		{
		case 0:
			return;
		case 1:
		{
			editFIO();
			done = true;
			break;
		}
		case 2:
		{
			editAge();
			done = true;
			break;
		}
		case 3:
		{
			editPosition();
			done = true;
			break;
		}
		case 4:
		{
			editExperience();
			done = true;
			break;
		}
		case 5:
		{
			editNumberOfWorkingDays();
			done = true;
			break;
		}
		case 6:
		{
			editNumberOfVacationDays();
			done = true;
			break;
		}
		case 7:
		{
			editNumberOfDaysOnSickLeave();
			done = true;
			break;
		}
		case 8:
		{
			editDependents();
			done = true;
			break;
		}

		default:
		{
			cout << "Такого поля нет. Повторите ввод.";
			break;
		}
		}
	}
}

//меню действий сотрудника
void Employee::menu()
{
	cout << "1. Посмотреть свои данные\n";
	cout << "2. Изменить свои данные\n";
	cout << "3. Рассчитать свою заработную плату\n";
	cout << "4. Посмотреть данные о должностях\n";
	cout << "5. Выйти из аккаунта сотрудника\n";
	cout << "6. Выйти из программы\n";
}

//перегрузка оператора вывода
ostream& operator<< (ostream& os, const Employee& E)
{
	return os << "\nID: " << E.getID()
		<< "\nФИО: " << E.getFIO()
		<< "\nВозраст: " << E.getAge()
		<< "\nДолжность: " << E.getPosition()
		<< "\nСтаж: " << E.getExperience()
		<< "\nКоличество отработанных дней: " << E.getNumberOfWorkingDays()
		<< "\nКоличество отпускных календарных дней: " << E.getNumberOfVacationDays()
		<< "\nКоличество календарных дней больничного отпуска: " << E.getNumberOfDaysOnSickLeave()
		<< "\nКоличество иждивенцев в семье: " << E.getDependents() << '\n';
}
//перегрузка оператора сравнения
bool operator== (const Employee& E1, const Employee& E2)
{
	return (E1.getID() == E2.getID());
}
//перегрузка оператора присваивания
Employee& Employee::operator=(const Employee& E)
{
	if (this != &E) //проверка на самоприсваивание
	{
		Account::operator=(E);
		id = E.id;
		fio = E.fio;
		age = E.age;
		position = E.position;
		experience = E.experience;
		numberOfWorkingDays = E.numberOfWorkingDays;
		numberOfVacationDays = E.numberOfVacationDays;
		numberOfDaysOnSickLeave = E.numberOfDaysOnSickLeave;
		dependents = E.dependents;
	}
	return *this;
}