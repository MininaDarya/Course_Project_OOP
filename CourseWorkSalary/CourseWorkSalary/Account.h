#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include "Object.h"

using namespace std;

/* ����������� ����� Account
*
* ��������� ��������� �������� ��������������� � �����������
* �������� ���������� � ������ � ������
*
* ������� ����� ��� Employee � Admin
*/

class Account : public Object
{
	string login; //�����
	string password; //������

public:
	//����������� � �����������
	Account(string log, string pass);
	//����������� �����������
	Account(const Account&);

	void Initialization();

	string getLogin() const;
	string getPassword() const;
	virtual string getRole() const = 0; //����� ����������� �������

	void setLogin(string);
	void setPassword(string);

	//����������� ����� ��� ����������� ����� ������ (����������� ����� #)
	static string safeEnter() {
		string tmp;
		do
		{
			unsigned char ch;
			ch = _getch(); //��������� ������ � �������
			if (ch == 13) //���������� � '\n'
				break;
			if (ch == '\b' && !tmp.empty())  //���������� � ' '
			{
				cout << '\b';
				cout << ' ';
				cout << '\b';
				tmp.pop_back();
				continue;
			}
			//��������, ���������� �� ������ � ���������-��������
			if (isalnum((unsigned char)ch))
			{
				cout << '#'; //������� ��������� ������ 
				tmp.push_back(ch); //��������� ����� ������ � ������
			}
		} while (true);
		return tmp;
	}

	//���������� ��������� ���������
	friend bool operator== (const Account&, const Account&);
	//���������� ��������� ������������
	Account& operator=(const Account&);

	//�������� ������������ ������ (��� ��������� �� �����)
	static bool check(string data)
	{
		for (int i = 0; i < data.length(); i++)
			if (!isalnum(data[i])) 	//��������, ���������� �� ������ � ���������-��������
				return false;
		return true;
	}
};