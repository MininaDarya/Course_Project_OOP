#pragma once
#include "Account.h"
#include "ID.h"

using namespace std;

/*����� Admin
*
* ���������� ���� � ����������������� ����� ��������������
* �������� ���� ��������� ��� �������������� �������
*
* ����������� �����, ���������� �� Account
*/

class Admin : public Account {
	ID<int> id; //����������������� �����
public:
	//����������� � �����������
	Admin(string, string, ID<int>);
	//����������� �����������
	Admin(const Admin&);

	//����������� ����
	string getRole() const;

	//���� ��������������
	void menu();
};