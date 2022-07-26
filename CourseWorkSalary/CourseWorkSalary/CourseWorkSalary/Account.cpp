#include "Account.h"

//конструктор с параметрами
Account::Account(string log, string pass)
{
	login = log;
	password = pass;
}

//конструктор копировани€
Account::Account(const Account& A)
{
	login = A.login;
	password = A.password;
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

//метод дл€ изменени€ парол€
void Account::newPassword()
{
	system("cls");
	while (true)
	{
		//свер€ем старый пароль
		cout << "—тарый пароль: ";
		string oldPassword = safeEnter(); //защищенный ввод
		if (oldPassword != password)
			cout << "Ќеверный пароль. ѕовторите ввод.\n";
		else
			break;
	}
	string newPassword;
	system("cls");
	cout << "ѕароль должен содержать только буквы и цифры.\n";
	while (true)
	{
		cout << "Ќовый пароль: ";
		newPassword = safeEnter(); //защищенный ввод
		if (check(newPassword)) //провер€ем новый пароль на корректность
			cout << "ѕароль содержит запрещенные символы.\n";
		else
			break;
	}
	setPassword(newPassword); //устанавливаем новый пароль
}

//перегрузка оператора сравнени€
bool operator== (const Account& A1, const Account& A2)
{
	return (A1.getLogin() == A2.getLogin() &&
		A1.getPassword() == A2.getPassword());
}
//перегрузка оператора присваивани€
Account& Account::operator=(const Account& A)
{
	if (this != &A) //проверка на самоприсваивание
	{
		login = A.login;
		password = A.password;
	}
	return *this;
}