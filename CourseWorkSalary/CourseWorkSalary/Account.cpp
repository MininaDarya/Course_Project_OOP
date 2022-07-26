#include "Account.h"

//конструктор с параметрами
Account::Account(string log, string pass)
{
	login = log;
	password = pass;
}
//конструктор копирования
Account::Account(const Account& A)
{
	login = A.login;
	password = A.password;
}

//переопределение чисто виртуальной функции, которая находится в классе Object
void Account::Initialization() {
	cout << "Введите логин: ";
	cin.ignore();
	getline(cin, login);
	cout << "Введите пароль: ";
	cin.ignore();
	getline(cin, password);
}

string Account::getLogin() const
{
	return login;
}
string Account::getPassword() const
{
	return password;
}

void Account::setLogin(string setLog)
{
	login = setLog;
}
void Account::setPassword(string setPass)
{
	password = setPass;
}

//перегрузка оператора сравнения
bool operator== (const Account& A1, const Account& A2)
{
	return (A1.getLogin() == A2.getLogin() &&
		A1.getPassword() == A2.getPassword());
}
//перегрузка оператора присваивания
Account& Account::operator=(const Account& A)
{
	if (this != &A) //проверка на самоприсваивание
	{
		login = A.login;
		password = A.password;
	}
	return *this;
}