#include "Employee.h"
#include "ID.h"

//����������� � �����������
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
//����������� �����������
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

//������ ��� ��������������
void Employee::editFIO()
{
	string data;
	cout << "���: ";
	getline(cin, data);
	setFIO(data);
}
void Employee::editAge()
{
	int data;
	cout << "�������: ";
	data = Employee::inputNumber();
	setAge(data);
}
void Employee::editExperience()
{
	int data;
	cout << "����: ";
	data = Employee::inputNumber();
	setExperience(data);
}
void Employee::editPosition()
{
	string data;
	cout << "���������: ";
	getline(cin, data);
	setPosition(data);
}

void Employee::editNumberOfWorkingDays()
{
	int data;
	cout << "���������� ������������ ����: ";
	data = Employee::inputNumber();
	setNumberOfWorkingDays(data);
}
void Employee::editNumberOfVacationDays()
{
	int data;
	cout << "���������� ����������� ��������� ����: ";
	data = Employee::inputNumber();
	setNumberOfVacationDays(data);
}
void Employee::editNumberOfDaysOnSickLeave()
{
	int data;
	cout << "���������� ����������� ���� ����������� �������: ";
	data = Employee::inputNumber();
	setNumberOfDaysOnSickLeave(data);
}
void Employee::editDependents()
{
	int data;
	cout << "���������� ���������� � �����: ";
	data = Employee::inputNumber();
	setDependents(data);
}

//���� ��� ������ ���� ��������������
void Employee::editMenu()
{
	cout << "1. ���\n";
	cout << "2. �������\n";
	cout << "3. ���������\n";
	cout << "4. ����\n";
	cout << "5. ���������� ������������ ����\n";
	cout << "6. ���������� ����������� ��������� ����\n";
	cout << "7. ���������� ����������� ���� ����������� �������\n";
	cout << "8. ���������� ���������� � �����\n";
	cout << "\n0. ����� �� ������ ��������������\n";
}
//��������������
void Employee::editData()
{
	int edit = 0;
	bool done = false;
	editMenu();
	while (!done)
	{
		cout << "�������� ���� ��� ��������������\n";
		edit = Employee::inputNumber();
		//�������� ������
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
			cout << "������ ���� ���. ��������� ����.";
			break;
		}
		}
	}
}

//���� �������� ����������
void Employee::menu()
{
	cout << "1. ���������� ���� ������\n";
	cout << "2. �������� ���� ������\n";
	cout << "3. ���������� ���� ���������� �����\n";
	cout << "4. ���������� ������ � ����������\n";
	cout << "5. ����� �� �������� ����������\n";
	cout << "6. ����� �� ���������\n";
}

//���������� ��������� ������
ostream& operator<< (ostream& os, const Employee& E)
{
	return os << "\nID: " << E.getID()
		<< "\n���: " << E.getFIO()
		<< "\n�������: " << E.getAge()
		<< "\n���������: " << E.getPosition()
		<< "\n����: " << E.getExperience()
		<< "\n���������� ������������ ����: " << E.getNumberOfWorkingDays()
		<< "\n���������� ��������� ����������� ����: " << E.getNumberOfVacationDays()
		<< "\n���������� ����������� ���� ����������� �������: " << E.getNumberOfDaysOnSickLeave()
		<< "\n���������� ���������� � �����: " << E.getDependents() << '\n';
}
//���������� ��������� ���������
bool operator== (const Employee& E1, const Employee& E2)
{
	return (E1.getID() == E2.getID());
}
//���������� ��������� ������������
Employee& Employee::operator=(const Employee& E)
{
	if (this != &E) //�������� �� ����������������
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