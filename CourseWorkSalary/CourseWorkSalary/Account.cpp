#include "Account.h"

//����������� � �����������
Account::Account(string log, string pass)
{
	login = log;
	password = pass;
}
//����������� �����������
Account::Account(const Account& A)
{
	login = A.login;
	password = A.password;
}

//��������������� ����� ����������� �������, ������� ��������� � ������ Object
void Account::Initialization() {
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, login);
	cout << "������� ������: ";
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

//���������� ��������� ���������
bool operator== (const Account& A1, const Account& A2)
{
	return (A1.getLogin() == A2.getLogin() &&
		A1.getPassword() == A2.getPassword());
}
//���������� ��������� ������������
Account& Account::operator=(const Account& A)
{
	if (this != &A) //�������� �� ����������������
	{
		login = A.login;
		password = A.password;
	}
	return *this;
}