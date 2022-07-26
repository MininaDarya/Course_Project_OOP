#include "Admin.h"
#include "Company.h"
#include "Object.h"
#include <Windows.h>
#include <memory>

void menu()
{
	cout << "1. Войти\n";
	cout << "2. Зарегистрироваться\n";
	cout << "3. Выйти из программы\n";
}

//функциональность сотрудника
int employeeFunctionality(Employee E, shared_ptr<Company>& C)
{
	E.getRole();
	int k = 0;
	while (true)
	{
		system("cls");
		E.menu();
		k = Employee::inputNumber();
		switch (k)
		{
		case 1:
		{
			cout << E;
			system("pause");
			break;
		}
		case 2:
		{
			E.editData();
			system("pause");
			break;
		}
		case 3:
		{
			C->calculateSalaryFor(E);
			system("pause");
			break;
		}
		case 4:
		{
			C->printPositions();
			cout << "\nДля перехода в режим сортировки введите \"sort\"\n";
			cout << "Для выхода в меню введите любой символ\n";
			string sort;
			cin >> sort;
			if (sort == "sort")
			{
				C->sortPositions();
				system("pause");
			}
			break;
		}
		case 5:
			return 1;
		case 6:
			return 2;
		default:
		{
			cout << "Такого пункта меню нет. Повторите ввод.";
			break;
		}
		}
	}
}

//функциональность администратора
int adminFunctionality(Admin A, shared_ptr<Company>& C)
{
	int k = 0;
	while (true)
	{
		system("cls");
		A.menu();
		k = Employee::inputNumber();
		switch (k)
		{
		case 1:
		{
			system("cls");
			C->printEmployee();
			cout << "\nДля перехода в режим сортировки введите \"sort\"\n";
			cout << "Для выхода в меню введите любой символ\n";
			string sort;
			cin >> sort;
			if (sort == "sort")
			{
				C->sortEmployee();
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("cls");
			Employee e(C->createNewEmployee());
			if (C->addEmployee(e))
				cout << "\nСотрудник успешно добавлен\n";
			else
				cout << "\nНе удалось добавить сотрудника\n";
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (C->deleteEmployee())
				cout << "\nСотрудник успешно удален\n";
			else
				cout << "\nНе удалось удалить сотрудника\n";
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			if (C->editEmployee())
				cout << "\nСотрудник успешно отредактирован\n";
			else
				cout << "\nНе удалось найти сотрудника\n";
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			C->filterEmployee();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			C->printPositions();
			cout << "\nДля перехода в режим сортировки введите \"sort\"\n";
			cout << "Для выхода в меню введите любой символ\n";
			string sort;
			cin >> sort;
			if (sort == "sort") {
				C->sortPositions();
				system("pause");
			}
			break;
		}
		case 7:
		{
			system("cls");
			Position p(C->createNewPosition());
			if (C->addPosition(p))
				cout << "\nДолжность успешно добавлена\n";
			else
				cout << "\nНе удалось добавить должность\n";

			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			if (C->deletePosition())
				cout << "\nДолжность успешно удалена\n";
			else
				cout << "\nНе удалось удалить должность\n";
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			if (C->editPosition())
				cout << "\nДолжность успешно отредактирована\n";
			else
				cout << "\nНе удалось найти должность\n";
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			C->filterPosition();
			system("pause");
			break;
		}
		case 11:
		{
			system("cls");
			C->calculateSalary();
			system("pause");
			break;
		}
		case 12:
			return 1;
		case 13:
			return 2;
		default:
		{
			cout << "\nТакого пункта в меню нет. Повторите ввод.\n";
			break;
		}
		}
	}
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try 
	{
		shared_ptr<Company> C(new Company("employee.txt", "positions.txt", "report.txt"));//умный указатель
		while (true)
		{
			system("cls");
			menu();
			cout << "\nВыберите пункт меню: ";
			int k = Employee::inputNumber();
			switch (k)
			{
			case 1:
			{
				while (true)
				{
					system("cls");
					cout << "\nЛогин: ";
					string login;
					getline(cin, login);
					cout << "\nПароль: ";
					string password = Account::safeEnter();//безопасный ввод пароля
					int role = C->authorization(login, password);//проверка входа
					if (role == 1) {
						Admin A(login, password, ID<int>(1));
						cout << A.getRole();
						system("pause");
						int end = adminFunctionality(A, C);
						if (end == 1)
							break;
						else
							return 0;
					}
					else if (role == 2)
					{
						Employee E(C->getEmployeeByLogin(login));
						cout << E.getRole();
						system("pause");
						int end = employeeFunctionality(E, C);
						if (end == 1)
							break;
						else
							return 0;
					}
					else
						cout << "\nНе удалось войти в систему. Проверьте данные.\n";
					system("pause");
				}
				break;
			}
			case 2:
			{
				Employee E(C->createNewEmployee());
				C->addEmployee(E);
				int end = employeeFunctionality(E, C);
				if (end == 1)
					break;
				else
					return 0;
			}
			case 3:
			{
				cout << "\nДо свидания!\n";
				return 0;
			}
			default: 
			{
				cout << "\nТакого пункта меню нет. Повторите ввод.\n";
				break;
			}
			}
		}
	}
	catch (const char* message) 
	{
		cout << message;
	}
	return 0;
}