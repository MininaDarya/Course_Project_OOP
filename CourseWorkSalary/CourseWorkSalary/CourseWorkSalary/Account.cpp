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

//����� ��� ��������� ������
void Account::newPassword()
{
	system("cls");
	while (true)
	{
		//������� ������ ������
		cout << "������ ������: ";
		string oldPassword = safeEnter(); //���������� ����
		if (oldPassword != password)
			cout << "�������� ������. ��������� ����.\n";
		else
			break;
	}
	string newPassword;
	system("cls");
	cout << "������ ������ ��������� ������ ����� � �����.\n";
	while (true)
	{
		cout << "����� ������: ";
		newPassword = safeEnter(); //���������� ����
		if (check(newPassword)) //��������� ����� ������ �� ������������
			cout << "������ �������� ����������� �������.\n";
		else
			break;
	}
	setPassword(newPassword); //������������� ����� ������
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