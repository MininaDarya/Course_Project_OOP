#include "Company.h"
#include "ID.h"
#include <fstream>
#include <vector>
#include <algorithm>

//����������� � �����������
Company::Company(string empFile, string posFile, string repFile)
{
	//�������������� ����
	employeeFile = empFile;
	positionsFile = posFile;
	reportFile = repFile;
	//��������� ������ �� ������
	positionsFromFile();
	employeeFromFile();
}
//����������� �����������
Company::Company(const Company& C)
{
	employeeFile = C.employeeFile;
	positionsFile = C.positionsFile;
	reportFile = C.reportFile;
	employee = C.employee;
	positions = C.positions;
}

Company::~Company()
{
	employee.clear();
	positions.clear();
}

vector<Employee> Company::getEmployee() const
{
	return employee;
}
vector<Position> Company::getPositions() const
{
	return positions;
}
string Company::getEmployeeFile() const
{
	return employeeFile;
}
string Company::getPositionsFile() const
{
	return positionsFile;
}
string Company::getReportFile() const
{
	return reportFile;
}


void Company::setEmployee(vector<Employee> setEmpl)
{
	employee = setEmpl;
}
void Company::setPositions(vector<Position> setPos)
{
	positions = setPos;
}
void Company::setEmployeeFile(string setEmpFile)
{
	employeeFile = setEmpFile;
}
void Company::setPositionsFile(string setPosFile)
{
	positionsFile = setPosFile;
}
void Company::setReportFile(string setRepFile)
{
	reportFile = setRepFile;
}

//�������� � �����������

//����� ���������� � ���� ���������� � ��������
void Company::printPositions()
{
	if (positions.size()) {
		cout << "______________________________________________________________________________\n";
		cout << "|  ID  |             �������� ���������             |   �����   |   ������   |\n";
		cout << "|______|____________________________________________|___________|____________|\n";
		for (auto p : positions) {
			printf("|%6d|%44s|%11d|%12d|\n",
				p.getID(), (p.getPosition()).c_str(), p.getSalary(), p.getReward());
			cout << "|____________________________________________________________________________|" << endl;
		}
	}
	else
		cout << "���������� � ���������� �����������\n";
}
//���������� ������ � ���������� �� �����
void Company::positionsFromFile()
{
	//������� ������� ����
	ifstream inputFile(positionsFile);
	if (!inputFile)
	{
		throw( "���� " + positionsFile + " �����������\n");
	}
	positions.clear();
	while (!inputFile.eof())
	{
		string line, tmp, position;
		int id, salary;
		int reward;
		int begin = 0, end;
		//��������� ������
		getline(inputFile, line, '\n');
		if (line != "\n" && line != "")
		{
			//id
			end = line.find('/');
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp)) //�������� �� ����� �����
				id = stoi(tmp);
			else
			{
				throw("������ ����� " + positionsFile + " �����������.\n");
			}

			//position
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			position = tmp;

			//salary
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))  //�������� �� ����� �����
				salary = stoi(tmp);
			else
			{
				throw("������ ����� " + positionsFile + " �����������.\n");
			}

			//reward
			begin = end + 1;
			end = line.find(';', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))  //�������� �� ������� �����
				reward = stoi(tmp);
			else
			{
				throw("������ ����� " + positionsFile + " �����������.\n");
			}
			//��������� ����� ��������� � ��� ������
			Position p(id, position, salary, reward);
			addPosition(p);
		}
	}
	//��������� ����
	inputFile.close();
}
//������ ������ � ���������� � ����
void Company::positionsToFile()
{
	ofstream outputFile(positionsFile);
	//��������� ���������� � ���� ���������� � ������ ��������� �������� ���� � ������� ������� '/'
	for (auto p : positions)
	{
		outputFile << p.getID() << '/'
			<< p.getPosition() << '/'
			<< p.getSalary() << '/'
			<< p.getReward() << ';' << '\n';
	}
	outputFile.close();
}
//���������� ������ � ����������
void Company::sortPositions()
{
	system("cls");
	cout << "1. ID\n";
	cout << "2. ���������\n";
	cout << "3. �����\n";
	cout << "4. ������\n";
	cout << "\n0. ����� �� ������ ����������\n";
	vector<Position> sortedPositions(positions);
	bool key = true;
	while (key)
	{
		int k;
		cout << "�������� ���� ��� ����������: ";
		k=Employee::inputNumber();
		//��������� ������
		switch (k)
		{
		case 0:
		{
			key = false;
			break;
		}
		case 1:
		{
			sort(sortedPositions.begin(), sortedPositions.end(),
				[](const Position& p1, const Position& p2)
				{ return p1.getID() < p2.getID(); });
			key = false;
			break;
		}
		case 2:
		{
			sort(sortedPositions.begin(), sortedPositions.end(),
				[](const Position& p1, const Position& p2)
				{ return p1.getPosition() < p2.getPosition(); });
			key = false;
			break;
		}
		case 3:
		{
			sort(sortedPositions.begin(), sortedPositions.end(),
				[](const Position& p1, const Position& p2)
				{ return p1.getSalary() < p2.getSalary(); });
			key = false;
			break;
		}
		case 4:
		{
			sort(sortedPositions.begin(), sortedPositions.end(),
				[](const Position& p1, const Position& p2)
				{ return p1.getReward() < p2.getReward(); });
			key = false;
			break;
		}
		default:
		{
			cout << "������ ������ ���� ���. ��������� ����.\n";
			break;
		}
		}
	}
	//������� ��������������� �� ���������� ��������� ������
	if (positions.size()) {
		cout << "______________________________________________________________________________\n";
		cout << "|  ID  |             �������� ���������             |   �����   |   ������   |\n";
		cout << "|______|____________________________________________|___________|____________|\n";
		for (auto p : sortedPositions) {
			printf("|%6d|%44s|%11d|%12d|\n",
				p.getID(), (p.getPosition()).c_str(), p.getSalary(), p.getReward());
			cout << "|____________________________________________________________________________|" << endl;
		}
	}
	else
		cout << "���������� � ���������� �����������\n";
}
//�������� ������� ���������
bool Company::searchPosition(Position& P)
{
	for (auto p : positions)
		if (p == P)
			return true;
	return false;
}
//�����/������ ����������
void Company::filterPosition()
{
	cout << "1. ID\n";
	cout << "2. ���������\n";
	cout << "3. �����\n";
	cout << "4. ������\n";
	cout << "\n0. ����� �� ������ ������\n";

	vector<Position> result;
	bool key = true;
	while (key) {
		int k;
		cout << "�������� ���� ��� ������: ";
		k=Employee::inputNumber();
		//��������� ������
		switch (k)
		{
		case 0:
		{
			key = false;
			break;
		}
		case 1:
		{
			int searchData;
			cout << "ID: ";
			searchData = Employee::inputNumber();
			for (auto p : positions)
				if (p.getID() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		case 2:
		{
			string searchData;
			cout << "���������: ";
			getline(cin, searchData);
			for (auto p : positions)
				if (p.getPosition() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		case 3:
		{
			int searchData;
			cout << "�����: ";
			searchData= Employee::inputNumber();
			for (auto p : positions)
				if (p.getSalary() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		case 4:
		{
			int searchData;
			cout << "������: ";
			searchData= Employee::inputNumber();
			for (auto p : positions)
				if (p.getReward() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		default:
		{
			cout << "������ ���� ���. ��������� ����.\n";
			break;
		}
		}
	}
	if (result.size() != 0)
	{
		cout << "\n���������� ������: \n";
		cout << "______________________________________________________________________________\n";
		cout << "|  ID  |             �������� ���������             |   �����   |   ������   |\n";
		cout << "|______|____________________________________________|___________|____________|\n";
		for (auto p : result) {
			printf("|%6d|%44s|%11d|%12d|\n",
				p.getID(), (p.getPosition()).c_str(), p.getSalary(), p.getReward());
			cout << "|____________________________________________________________________________|" << endl;
		}
	}
	else
		cout << "\n�� ������ ������� ������ �� �������.\n";
}
//��������� ����� ���������
Position Company::createNewPosition()
{
	string tmp;
	string position;
	int id, salary;
	int reward;

	while (true)
	{
		cout << "ID: ";
		
		getline(cin, tmp);
		if (intNumberCheck(tmp))
		{
			id = stoi(tmp);
			break;
		}
		else
			cout << "������ ���� ������� ����� �����\n";
	}
	cout << "���������: ";
	getline(cin, tmp);
	position = tmp;
	while (true)
	{
		cout << "�����: ";
		getline(cin, tmp);
		if (intNumberCheck(tmp))
		{
			salary = stoi(tmp);
			break;
		}
		else
			cout << "������ ���� ������� ����� �����\n";
	}
	while (true)
	{
		cout << "������: ";
		getline(cin, tmp);
		if (intNumberCheck(tmp))
		{
			reward = stod(tmp);
			break;
		}
		else
			cout << "������ ���� ������� ����� ��� ������� �����\n";
	}
	Position p(id, position, salary, reward);
	return p;
}
//���������� ����� ���������
bool Company::addPosition(Position& p)
{
	//���� ����� ��������� ���, �� ���������
	if (!searchPosition(p))
	{
		positions.push_back(p);
		positionsToFile(); //��������� ������ � �����
		return true;
	}
	return false;
}
//�������� ���������
bool Company::deletePosition()
{
	printPositions();
	cout << "\nID ���������, ������� ����� �������: ";
	int ID;
	ID= Employee::inputNumber();
	vector <Position> ::iterator it;
	for (it = positions.begin(); it != positions.end(); it++)
		if (ID == (*it).getID())
		{
			positions.erase(it);
			positionsToFile(); // ��������� ������ � �����
			return true;
		}
	return false;
}
//�������������� ���������
bool Company::editPosition()
{
	printPositions();
	cout << "\nID ���������, ������� ����� ���������������: ";
	int id;
	id= Employee::inputNumber();
	vector <Position>::iterator it;
	for (it = positions.begin(); it != positions.end(); it++)
		if (id == (*it).getID())
		{
			(*it).editData();
			positionsToFile(); //��������� ����
			return true;
		}
	return false;

}

//�������� � ������������

//����� ���������� � ���� ����������� � ��������
void Company::printEmployee()
{
	if (employee.size())
	{
			cout << "___________________________________________________________________________________________\n";
			cout << "|   ID   |                  ���                  |�������|         ���������         |����|\n";
			cout << "|________|_______________________________________|_______|___________________________|____|\n";
			for (auto e : employee) {
				printf("|%8s|%39s|%7d|%27s|%4d|\n",
					e.getID().getId().c_str(), e.getFIO().c_str(), e.getAge(), (e.getPosition()).c_str(), e.getExperience());
				cout << "|_________________________________________________________________________________________|\n";
			}
	}
	else
		cout << "���������� � ����������� �����������\n";
}
//���������� ������ � ����������� �� �����
void Company::employeeFromFile()
{
	ifstream inputFile(employeeFile);
	if (!inputFile)
	{
		throw( "���� " + employeeFile + " �����������.\n");
	}
	employee.clear();
	while (!inputFile.eof())
	{
		string line, tmp, login, password, fio, position;
		int age, exp, workingDays, vacationDays, onSickLeaveDays, dependents;
		int begin = 0, end;
		getline(inputFile, line, '\n');
		if (line != "\n" && line != "")
		{
			//login
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			login = tmp;

			//password
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			password = tmp;

			//id
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			ID<string> id(tmp);

			//fio
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			fio = tmp;

			//age
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				age = stoi(tmp);
			else
			{
				throw( "������ ����� " + employeeFile + " �����������.\n");
			}

			//position
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			position = tmp;

			//experience
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				exp = stoi(tmp);
			else
			{
				throw("������ ����� " + employeeFile + " �����������.\n");
			}

			//working days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				workingDays = stoi(tmp);
			else
			{
				throw("������ ����� " + employeeFile + " �����������.\n");
			}

			//vacation days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				vacationDays = stoi(tmp);
			else
			{
				throw("������ ����� " + employeeFile + " �����������.\n");
			}

			//on sick leave days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				onSickLeaveDays = stoi(tmp);
			else
			{
				throw("������ ����� " + employeeFile + " �����������.\n");
			}
			//dependents
			begin = end + 1;
			end = line.find(';', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				dependents = stoi(tmp);
			else
			{
				throw("������ ����� " + employeeFile + " �����������.\n");
			}

			Employee e(login, password, position, id, fio, age, exp,
				workingDays, vacationDays, onSickLeaveDays, dependents);
			addEmployee(e);
		}
	}
	inputFile.close();

}
//������ ������ � ����������� � ����
void Company::employeeToFile()
{
	ofstream outputFile(employeeFile);
	for (auto e : employee)
	{
		outputFile << e.getLogin() << '/'
			<< e.getPassword() << '/'
			<< e.getID() << '/'
			<< e.getFIO() << '/'
			<< e.getAge() << '/'
			<< e.getPosition() << '/'
			<< e.getExperience() << '/'
			<< e.getNumberOfWorkingDays() << '/'
			<< e.getNumberOfVacationDays() << '/'
			<< e.getNumberOfDaysOnSickLeave() << '/'
			<< e.getDependents() << ';' << '\n';
	}
	outputFile.close();

}

//���������� ������ � �����������
void Company::sortEmployee()
{
	system("cls");
	cout << "1. ID\n";
	cout << "2. ���\n";
	cout << "3. �������\n";
	cout << "4. ���������\n";
	cout << "5. ����\n";
	cout << "\n0. ����� �� ������ ����������\n";
	vector<Employee> sortedEmployee(employee);
	bool key = true;
	while (key)
	{
		int k;
		cout << "�������� ���� ��� ����������: ";
		k= Employee::inputNumber();
		switch (k)
		{
		case 0:
		{
			key = false;
			break;
		}
		case 1:
		{
			sort(sortedEmployee.begin(), sortedEmployee.end(),
				[](Employee e1, Employee e2)
				{ return e1.getID() < e2.getID(); });
			key = false;
			break;
		}
		case 2:
		{
			sort(employee.begin(), employee.end(), 
				[](Employee e1, Employee e2)
				{ return e1.getFIO() < e2.getFIO(); });
			key = false;
			break;
		}
		case 3:
		{
			sort(sortedEmployee.begin(), sortedEmployee.end(),
				[](Employee e1, Employee e2)
				{ return e1.getAge() < e2.getAge(); });
			key = false;
			break;
		}
		case 4:
		{
			sort(sortedEmployee.begin(), sortedEmployee.end(),
				[](const Employee& e1, const Employee& e2)
				{ return e1.getPosition() < e2.getPosition(); });
			key = false;
			break;
		}
		case 5:
		{
			sort(sortedEmployee.begin(), sortedEmployee.end(),
				[](const Employee& e1, const Employee& e2)
				{ return e1.getExperience() < e2.getExperience(); });
			key = false;
			break;
		}
		default:
		{
			cout << "������ ���� ���. ��������� ����.\n";
			break;
		}
		}
	}
	cout << "___________________________________________________________________________________________\n";
	cout << "|   ID   |                  ���                  |�������|         ���������         |����|\n";
	cout << "|________|_______________________________________|_______|___________________________|____|\n";
	for (auto e : sortedEmployee) {
		printf("|%8s|%39s|%7d|%27s|%4d|\n",
			e.getID().getId().c_str(), e.getFIO().c_str(), e.getAge(), (e.getPosition()).c_str(), e.getExperience());
		cout << "|_________________________________________________________________________________________|\n";
	}
}
//�������� ������� ����������
bool Company::searchEmployee(Employee& E)
{
	for (auto e : employee)
		if (e == E)
			return true;
	return false;
}
//�����/������ �����������
void Company::filterEmployee()
{
	cout << "1. ID\n";
	cout << "2. ���\n";
	cout << "3. �������\n";
	cout << "4. ���������\n";
	cout << "5. ����\n";
	cout << "\n0. ����� �� ������ ������\n";
	vector<Employee> result;
	bool key = true;
	while (key)
	{
		int k;
		cout << "���� ��� ������: ";
		k= Employee::inputNumber();
		switch (k)
		{
		case 0:
		{
			key = false;
			break;
		}
		case 1:
		{
			string searchData;
			cout << "ID: ";
			
			getline(cin, searchData);
			for (auto e : employee)
				if (e.getID() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		case 2:
		{
			string searchData;
			cout << "���: ";
			
			getline(cin, searchData);
			for (auto e : employee)
				if (e.getFIO() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		case 3:
		{
			int searchData;
			cout << "�������: ";
			searchData= Employee::inputNumber();
			for (auto e : employee)
				if (e.getAge() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		case 4:
		{
			string searchData;
			cout << "���������: ";
			getline(cin, searchData);
			for (auto e : employee)
				if (e.getPosition() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		case 5:
		{
			int searchData;
			cout << "����: ";
			searchData= Employee::inputNumber();
			for (auto e : employee)
				if (e.getExperience() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		default:
		{
			cout << "������ ���� ���. ��������� ����.\n";
			break;
		}
		}
	}
	if (result.size() != 0)
	{
		cout << "\n���������� ������: \n";
		cout << "___________________________________________________________________________________________\n";
		cout << "|   ID   |                  ���                  |�������|         ���������         |����|\n";
		cout << "|________|_______________________________________|_______|___________________________|____|\n";
		for (auto e : result)
		{
			printf("|%8s|%39s|%7d|%27s|%4d|\n",
				e.getID().getId().c_str(), e.getFIO().c_str(), e.getAge(), (e.getPosition()).c_str(), e.getExperience());
			cout << "|_________________________________________________________________________________________|\n";
		}
	}
	else
		cout << "�� ����� ������� ������ �� �������\n";
}
//��������� ������ ����������
Employee Company::createNewEmployee()
{
	cout << "ID: ";
	string id;
	
	getline(cin, id);
	ID<string> Id(id);
	cout << "���: ";
	string fio;
	getline(cin, fio);
	cout << "�������: ";
	int age;
	age= Employee::inputNumber();
	cout << "���������: ";
	string position;
	
	getline(cin, position);
	cout << "����: ";
	int exp;
	exp= Employee::inputNumber();
	cout << "���������� ������������ ����: ";
	int workingDays;
	workingDays= Employee::inputNumber();
	cout << "���������� ��������� ����������� ����: ";
	int vacationDays;
	vacationDays= Employee::inputNumber();
	cout << "���������� ����������� ���� ����������� �������: ";
	int daysOnSickLeave;
	daysOnSickLeave= Employee::inputNumber();
	cout << "���������� ���������� � �����: ";
	int dependents;
	dependents= Employee::inputNumber();

	string login;
	while (true)
	{
		system("cls");
		cout << "����� ������ ��������� ������ ����� � �����.\n";
		cout << "�����: ";
		
		getline(cin, login);
		if (!Account::check(login))
			cout << "����� �������� ����������� �������\n";
		else
			break;
	}
	string password;
	while (true)
	{
		system("cls");
		cout << "������ ������ ��������� ������ ����� � �����.\n";
		cout << "������: ";
		password = Account::safeEnter();
		if (!Account::check(password))
			cout << "������ �������� ����������� �������\n";
		else
			break;
	}
	Employee e(login, password, position, Id, fio, age, exp, workingDays, vacationDays, daysOnSickLeave, dependents);
	return e;
}
//���������� ������ ����������
bool Company::addEmployee(Employee& e)
{
	if (!searchEmployee(e))
	{
		employee.push_back(e);
		employeeToFile();
		return true;
	}
	return false;
}
//�������� ������ ����������
bool Company::deleteEmployee()
{
	printEmployee();
	cout << "\nID ���������� ����������: ";
	string id;
	
	getline(cin, id);
	vector <Employee> ::iterator it;
	for (it = employee.begin(); it != employee.end(); it++)
		if (id == (*it).getID()) {
			employee.erase(it);
			employeeToFile();
			return true;
		}
	return false;
}
//�������������� ����������
bool Company::editEmployee()
{
	printEmployee();
	cout << "\nID �������������� ����������: ";
	string id;
	
	getline(cin, id);
	vector <Employee>::iterator it;
	for (it = employee.begin(); it != employee.end(); it++)
		if (id == (*it).getID())
		{
			(*it).editData();
			employeeToFile();
			return true;
		}
	return false;
}

//������� ���������� ����� ��� ����������� ����������
void Company::calculateSalaryFor(Employee& E)
{
	for (auto p : positions)
		if (p.getPosition() == E.getPosition())
		{
			cout << "������ ��� ������� ���������� �����\n";
			cout << "�����: ";
			string month;
			
			getline(cin, month);
			cout << "���������� ������� ����: ";
			int calendarDays = 0;
			calendarDays = Employee::inputNumber();
			Salary s(month, calendarDays);
			ofstream outputFile(reportFile, ios::app);
			double salary = s.calculateSalary(E, p); //������� ���������� �����
			cout << "���������� ����� ���������� " << E.getID() << " �� " << s.getMonth() << " ���������� " << salary << " BYN\n";
			outputFile << "���������� ����� ���������� " << E.getID() << " �� " << s.getMonth() << " ���������� " << salary << " BYN\n";
			outputFile.close();
			return;
		}
	cout << "�� ������� ���������� ���������� �����\n";
}
//����� ���������� ��� �������� ���������� �����
void Company::calculateSalary()
{
	printEmployee();
	while (true)
	{
		cout << "ID ����������: ";
		string id;
		
		getline(cin, id);
		for (auto e : employee)
			if (e.getID() == id)
			{
				calculateSalaryFor(e);
				return;
			}
		cout << "��������� �� ������\n";
		cout << "����� �� ������ '0'\n";
		int k;
		k= Employee::inputNumber();
		if (!k)
			break;
	}
}

//�����������
int Company::authorization(string login, string password)
{
	if (login == "admin" && password == "admin")
		return 1;
	for (auto e : employee)
		if (e.getLogin() == login && e.getPassword() == password)
			return 2;
	return 3;
	//3 - ������
}

//����� ���������� �� ������
Employee Company::getEmployeeByLogin(string login)
{
	for (auto e : employee)
		if (e.getLogin() == login)
			return e;
}