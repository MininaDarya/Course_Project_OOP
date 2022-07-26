#include "Company.h"
#include "ID.h"
#include "Object.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace salary_;

//конструктор с параметрами
Company::Company(string empFile, string posFile, string repFile)
{
	//инициализируем поля
	employeeFile = empFile;
	positionsFile = posFile;
	reportFile = repFile;
	//считываем данные из файлов
	positionsFromFile();
	employeeFromFile();
}
//конструктор копирования
Company::Company(const Company& C)
{
	employeeFile = C.employeeFile;
	positionsFile = C.positionsFile;
	reportFile = C.reportFile;
	employee = C.employee;
	positions = C.positions;
}
//перегрузка конструктора с параметрами
Company::Company(string empFile, string posFile)
{
	//инициализируем поля
	employeeFile = empFile;
	positionsFile = posFile;
	//считываем данные из файлов
	positionsFromFile();
	employeeFromFile();
}

Company::~Company()
{
	employee.clear();
	positions.clear();
}

void Company::Initialization() 
{
	positionsFromFile();
	employeeFromFile();
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

//действия с должностями

//вывод информации о всех должностях в компании
void Company::printPositions()
{
	if (positions.size()) 
	{
		cout << "___________________________________________________________________________\n";
		cout << "   ID  |             Название должности             |   Оклад   |  Премия  \n";
		cout << "_______|____________________________________________|___________|__________\n";
		for (auto p : positions)
		{
			cout << setw(6) << p.getID() << setw(44) << p.getPosition().c_str() << setw(11) << p.getSalary() << setw(11) << p.getReward() << endl;
			cout << "___________________________________________________________________________" << endl;
		}
	}
	else
		cout << "Информация о долнжостях отсутствует\n";
}
//считывание данных о должностях из файла
void Company::positionsFromFile()
{
	//попытка открыть файл
	ifstream inputFile(positionsFile);
	if (!inputFile)
	{
		throw( "Файл " + positionsFile + " отсутствует\n");
	}
	positions.clear();
	while (!inputFile.eof())
	{
		string line, tmp, position;
		int id;
		float salary;
		float reward;
		int begin = 0, end;
		//считываем строку
		getline(inputFile, line, '\n');
		if (line != "\n" && line != "")
		{
			//id
			end = line.find('/');
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp)) //проверка на целое число
				id = stoi(tmp);
			else
			{
				throw("Данные файла " + positionsFile + " некорректны.\n");
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
			salary = stof(tmp);

			//reward
			begin = end + 1;
			end = line.find(';', begin);
			tmp = line.substr(begin, end - begin);
			reward = stof(tmp);
			
			//добавляем новую должность в наш список
			Position p(id, position, salary, reward);
			addPosition(p);
		}
	}
	//закрываем файл
	inputFile.close();
}

//запись данных о должностях в файл
void Company::positionsToFile()
{
	ofstream outputFile(positionsFile);
	//построчно записываем в файл информацию о каждой должности разделяя поля с помощью символа '/'
	
	for (auto p : positions)
	{
		outputFile << p.getID() << '/'
			<< p.getPosition() << '/'
			<< p.getSalary() << '/'
			<< p.getReward() << ';' << '\n';
	}
	outputFile.close();
}
//сортировка данных о должностях
void Company::sortPositions()
{
	system("cls");
	cout << "1. ID\n";
	cout << "2. Должность\n";
	cout << "3. Оклад\n";
	cout << "4. Премии\n";
	cout << "\n0. Выйти из режима сортировки\n";
	vector<Position> sortedPositions(positions);
	bool key = true;
	while (key)
	{
		int k;
		cout << "Выберите поле для сортировки: ";
		k=Employee::inputNumber();
		//обработка выбора
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
			cout << "Такого пункта меню нет. Повторите ввод.\n";
			break;
		}
		}
	}
	//выводим отсортированный по выбранному параметру список
	if (positions.size()) 
	{
		cout << "___________________________________________________________________________\n";
		cout << "   ID  |             Название должности             |   Оклад   |  Премия  \n";
		cout << "_______|____________________________________________|___________|__________\n";
		for (auto p : sortedPositions)
		{
			cout << setw(6) << p.getID() << setw(44) << p.getPosition().c_str() << setw(11) << p.getSalary() << setw(11) << p.getReward() << endl;
			cout << "___________________________________________________________________________" << endl;
		}
	}
	else
		cout << "Информация о должностях отсутствует\n";
}

//проверка наличия должности
bool Company::searchPosition(Position& P)
{
	for (auto p : positions)
		if (p == P)
			return true;
	return false;
}
//поиск/фильтр должностей
void Company::filterPosition()
{
	cout << "1. ID\n";
	cout << "2. Должность\n";
	cout << "3. Оклад\n";
	cout << "4. Премии\n";
	cout << "\n0. Выйти из режима поиска\n";

	vector<Position> result;
	bool key = true;
	while (key) {
		int k;
		cout << "Выберите поле для поиска: ";
		k=Employee::inputNumber();
		//обработка выбора
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
			cout << "Должность: ";
			getline(cin, searchData);
			for (auto p : positions)
				if (p.getPosition() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		case 3:
		{
			float searchData;
			cout << "Оклад: ";
			try {
				if (!(cin >> searchData) || searchData <= 0) {
					throw 13;
				}
			}
			catch (int a) {
				if (a == 13) {
					while (!(cin >> searchData) || searchData <= 0) {
						if (cin.fail())
							cout << "Работает cin.fail()" << endl;
						cin.clear();
						cin.ignore(32767, '\n');
						cout << "Ошибка! Повторите ввод!" << endl
							<< "Ввод: ";
					}
				}
			}
			for (auto p : positions)
				if (p.getSalary() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		case 4:
		{
			int searchData;
			cout << "Премия: ";
			try {
				if (!(cin >> searchData) || searchData <= 0) {
					throw 14;
				}
			}
			catch (int a) {
				if (a == 14) {
					while (!(cin >> searchData) || searchData <= 0) {
						if (cin.fail())
							cout << "Работает cin.fail()" << endl;
						cin.clear();
						cin.ignore(32767, '\n');
						cout << "Ошибка! Повторите ввод!" << endl
							<< "Ввод: ";
					}
				}
			}
			for (auto p : positions)
				if (p.getReward() == searchData)
					result.push_back(p);
			key = false;
			break;
		}
		default:
		{
			cout << "Такого поля нет. Повторите ввод.\n";
			break;
		}
		}
	}
	if (result.size() != 0)
	{
		cout << "\nРезультаты поиска: \n";
		cout << "___________________________________________________________________________\n";
		cout << "   ID  |             Название должности             |   Оклад   |  Премия  \n";
		cout << "_______|____________________________________________|___________|__________\n";
		for (auto p : result)
		{
			cout << setw(6) << p.getID() << setw(44) << p.getPosition().c_str() << setw(11) << p.getSalary() << setw(11) << p.getReward() << endl;
			cout << "___________________________________________________________________________" << endl;
		}
	}
	else
		cout << "\nПо вашему запросу ничего не найдено.\n";
}
//созданиие новой должности
Position Company::createNewPosition()
{
	string tmp;
	string position;
	int id;
	float salary;
	float reward;

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
			cout << "Должно быть введено целое число\n";
	}
	cout << "Должность: ";
	getline(cin, tmp);
	position = tmp;
	cout << "Оклад: ";
	try {
		if (!(cin >> salary) || salary <= 0) {
			throw 5;
		}
	}
	catch (int a) {
		if (a == 5) {
			while (!(cin >> salary) || salary <= 0) {
				if (cin.fail())
					cout << "Работает cin.fail()" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка! Повторите ввод!" << endl
					<< "Ввод: ";
			}
		}
	}
	cout << "Премия: ";
	try {
		if (!(cin >> reward) || reward <= 0) {
			throw 7;
		}
	}
	catch (int a) {
		if (a == 7) {
			while (!(cin >> reward) || reward <= 0) {
				if (cin.fail())
					cout << "Работает cin.fail()" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка! Повторите ввод!" << endl
					<< "Ввод: ";
			}
		}
	}
	Position p(id, position, salary, reward);
	return p;
}
//добавление новой должности
bool Company::addPosition(Position& p)
{
	//если такой должности нет, то добавляем
	if (!searchPosition(p))
	{
		positions.push_back(p);
		positionsToFile(); //обновляем данные в файле
		return true;
	}
	return false;
}
//удаление должности
bool Company::deletePosition()
{
	printPositions();
	cout << "\nID должности, которую нужно удалить: ";
	int ID;
	ID= Employee::inputNumber();
	vector <Position> ::iterator it;
	for (it = positions.begin(); it != positions.end(); it++)
		if (ID == (*it).getID())
		{
			positions.erase(it);
			positionsToFile(); // обновляем данные в файле
			return true;
		}
	return false;
}
//редактирование должности
bool Company::editPosition()
{
	printPositions();
	cout << "\nID должности, которую нужно отредактировать: ";
	int id;
	id= Employee::inputNumber();
	vector <Position>::iterator it;
	for (it = positions.begin(); it != positions.end(); it++)
		if (id == (*it).getID())
		{
			(*it).editData();
			positionsToFile(); //обновляем файл
			return true;
		}
	return false;

}

//действия с сотрудниками

//вывод информации о всех сотрудниках в компании
void Company::printEmployee()
{
	if (employee.size())
	{
			cout << "___________________________________________________________________________________________\n";
			cout << "   ID   |                  ФИО                  |Возраст|         Должность         | Стаж \n";
			cout << "________|_______________________________________|_______|___________________________|______\n";
			for (auto e : employee) 
			{
				cout << setw(7) << e.getID().getId().c_str() << setw(39) << e.getFIO().c_str() << setw(7) << e.getAge()
					<< setw(27) << e.getPosition().c_str() << setw(8) << e.getExperience() << endl;
				cout << "___________________________________________________________________________________________\n";
			}
	}
	else
		cout << "Информация о сотрудниках отсутствует\n";
}
//считывание данных о сотрудниках из файла
void Company::employeeFromFile()
{
	ifstream inputFile(employeeFile);
	if (!inputFile)
	{
		throw( "Файл " + employeeFile + " отсутствует.\n");
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
				throw( "Данные файла " + employeeFile + " некорректны.\n");
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
				throw("Данные файла " + employeeFile + " некорректны.\n");
			}

			//working days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				workingDays = stoi(tmp);
			else
			{
				throw("Данные файла " + employeeFile + " некорректны.\n");
			}

			//vacation days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				vacationDays = stoi(tmp);
			else
			{
				throw("Данные файла " + employeeFile + " некорректны.\n");
			}

			//on sick leave days
			begin = end + 1;
			end = line.find('/', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				onSickLeaveDays = stoi(tmp);
			else
			{
				throw("Данные файла " + employeeFile + " некорректны.\n");
			}
			//dependents
			begin = end + 1;
			end = line.find(';', begin);
			tmp = line.substr(begin, end - begin);
			if (intNumberCheck(tmp))
				dependents = stoi(tmp);
			else
			{
				throw("Данные файла " + employeeFile + " некорректны.\n");
			}

			Employee e(login, password, position, id, fio, age, exp,
				workingDays, vacationDays, onSickLeaveDays, dependents);
			addEmployee(e);
		}
	}
	inputFile.close();

}
//запись данных о сотрудниках в файл
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

//сортировка данных о сотрудниках
void Company::sortEmployee()
{
	system("cls");
	cout << "1. ID\n";
	cout << "2. ФИО\n";
	cout << "3. Возраст\n";
	cout << "4. Должность\n";
	cout << "5. Стаж\n";
	cout << "\n0. Выйти из режима сортировки\n";
	vector<Employee> sortedEmployee(employee);
	bool key = true;
	while (key)
	{
		int k;
		cout << "Выберите поле для сортировки: ";
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
			cout << "Такого поля нет. Повторите ввод.\n";
			break;
		}
		}
	}
	if (employee.size())
	{
		cout << "___________________________________________________________________________________________\n";
		cout << "   ID   |                  ФИО                  |Возраст|         Должность         | Стаж \n";
		cout << "________|_______________________________________|_______|___________________________|______\n";
		for (auto e : sortedEmployee)
		{
			cout << setw(7) << e.getID().getId().c_str() << setw(39) << e.getFIO().c_str() << setw(7) << e.getAge()
				<< setw(27) << e.getPosition().c_str() << setw(8) << e.getExperience() << endl;
			cout << "___________________________________________________________________________________________\n";
		}
	}
	else
		cout << "Информация о сотрудниках отсутствует\n";
}
//проверка наличия сотрудника
bool Company::searchEmployee(Employee& E)
{
	for (auto e : employee)
		if (e == E)
			return true;
	return false;
}
//поиск/фильтр сотрудников
void Company::filterEmployee()
{
	int initC = GetCountOfEmployess();
	InitCount(initC);

	cout << "ВСЕГО ЗАРЕГИСТРИРОВАНО СОТРУДНИКОВ: " << GetCount() << endl;

	cout << "1. ID\n";
	cout << "2. ФИО\n";
	cout << "3. Возраст\n";
	cout << "4. Должность\n";
	cout << "5. Стаж\n";
	cout << "\n0. Выйти из режима поиска\n";
	vector<Employee> result;
	bool key = true;
	while (key)
	{
		int k;
		cout << "Поле для поиска: ";
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
			cout << "ФИО: ";
			
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
			cout << "Возраст: ";
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
			cout << "Должность: ";
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
			cout << "Стаж: ";
			searchData= Employee::inputNumber();
			for (auto e : employee)
				if (e.getExperience() == searchData)
					result.push_back(e);
			key = false;
			break;
		}
		default:
		{
			cout << "Такого поля нет. Повторите ввод.\n";
			break;
		}
		}
	}
	if (result.size() != 0)
	{
		cout << "\nРезультаты поиска: \n";
		cout << "___________________________________________________________________________________________\n";
		cout << "   ID   |                  ФИО                  |Возраст|         Должность         | Стаж \n";
		cout << "________|_______________________________________|_______|___________________________|______\n";
		for (auto e : result)
		{
			cout << setw(7) << e.getID().getId().c_str() << setw(39) << e.getFIO().c_str() << setw(7) << e.getAge()
				<< setw(27) << e.getPosition().c_str() << setw(8) << e.getExperience() << endl;
			cout << "___________________________________________________________________________________________\n";
		}
	}
	else
		cout << "По вашем запросу ничего не найдено\n";
}
//созданиие нового сотрудника
Employee Company::createNewEmployee()
{
	cout << "ID: ";
	string id;
	
	getline(cin, id);
	ID<string> Id(id);
	cout << "ФИО: ";
	string fio;
	getline(cin, fio);
	cout << "Возраст: ";
	int age;
	age= Employee::inputNumber();
	cout << "Должность: ";
	string position;
	
	getline(cin, position);
	cout << "Стаж: ";
	int exp;
	exp= Employee::inputNumber();
	cout << "Количество отработанных дней: ";
	int workingDays;
	workingDays= Employee::inputNumber();
	cout << "Количество отпускных календарных дней: ";
	int vacationDays;
	vacationDays= Employee::inputNumber();
	cout << "Количество календарных дней больничного отпуска: ";
	int daysOnSickLeave;
	daysOnSickLeave= Employee::inputNumber();
	cout << "Количество иждивенцев в семье: ";
	int dependents;
	dependents= Employee::inputNumber();

	string login;
	while (true)
	{
		system("cls");
		cout << "Логин должен содержать только буквы и цифры.\n";
		cout << "Логин: ";
		
		getline(cin, login);
		if (!Account::check(login))
			cout << "Логин содержит запрещенные символы\n";
		else
			break;
	}
	string password;
	while (true)
	{
		system("cls");
		cout << "Пароль должен содержать только буквы и цифры.\n";
		cout << "Пароль: ";
		password = Account::safeEnter();
		if (!Account::check(password))
			cout << "Пароль содержит запрещенные символы\n";
		else
			break;
	}
	Employee e(login, password, position, Id, fio, age, exp, workingDays, vacationDays, daysOnSickLeave, dependents);
	return e;
}
//добавление нового сотрудника
bool Company::addEmployee(Employee& e)
{
	if (!searchEmployee(e))
	{
		employee.push_back(e);
		AddCount();
		employeeToFile();
		return true;
	}
	return false;
}
//удаление нового сотрудника
bool Company::deleteEmployee()
{
	printEmployee();
	cout << "\nID удаляемого сотрудника: ";
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
//редактирование сотрудника
bool Company::editEmployee()
{
	printEmployee();
	cout << "\nID редактируемого сотрудника: ";
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

int Company::GetCountOfEmployess() {
	return this->employee.size();
}

//рассчет заработной платы для конкретного сотрудника
void Company::calculateSalaryFor(Employee& E)
{
	for (auto p : positions)
		if (p.getPosition() == E.getPosition())
		{
			cout << "Данные для расчета заработной платы\n";
			cout << "Месяц: ";
			string month;
			
			getline(cin, month);
			cout << "Количество рабочих дней: ";
			int calendarDays = 0;
			calendarDays = Employee::inputNumber();
			Salary s(month, calendarDays);
			ofstream outputFile(reportFile, ios::app);
			double salary = s.calculateSalary(E, p); //считаем заработную плату
			cout << "Заработная плата сотрудника " << E.getID() << " за " << s.getMonth() << " составляет " << salary << " BYN\n";
			outputFile << "Заработная плата сотрудника " << E.getID() << " за " << s.getMonth() << " составляет " << salary << " BYN\n";
			outputFile.close();
			return;
		}
	cout << "Не удалось рассчитать заработную плату\n";
}
//выбор сотрудника для рассчета заработной платы
void Company::calculateSalary()
{
	printEmployee();
	while (true)
	{
		cout << "ID сотрудника: ";
		string id;
		
		getline(cin, id);
		for (auto e : employee)
			if (e.getID() == id)
			{
				calculateSalaryFor(e);
				return;
			}
		cout << "Сотрудник не найден\n";
		cout << "Выйти из режима '0'\n";
		int k;
		k= Employee::inputNumber();
		if (!k)
			break;
	}
}

//авторизация
int Company::authorization(string login, string password)
{
	if (login == "admin" && password == "admin")
		return 1;
	for (auto e : employee)
		if (e.getLogin() == login && e.getPassword() == password)
			return 2;
	return 3;
	//3 - ошибка
}

//поиск сотрудника по логину
Employee Company::getEmployeeByLogin(string login)
{
	for (auto e : employee)
		if (e.getLogin() == login)
			return e;
}