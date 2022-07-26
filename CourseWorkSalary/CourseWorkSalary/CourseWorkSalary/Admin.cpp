#include "Admin.h"

//����������� � �����������
Admin::Admin(string log, string pass, ID<int> i) :
	Account(log, pass)
{
	id = i;
}
//����������� �����������
Admin::Admin(const Admin& A) :
	Account((Account&)A)
{
	id = A.id;
}

//���������� ������������ ������ ������������ ������ Account
string Admin::getRole() const
{
	return "\n���� ���� - �������������.\n";
}

void Admin::menu() {
	cout << "1. ���������� ������ � �����������\n";
	cout << "2. �������� ����������\n";
	cout << "3. ������� ����������\n";
	cout << "4. ������������� ����������\n";
	cout << "5. ����� �����������\n";
	cout << "6. ���������� ������ � ����������\n";
	cout << "7. �������� ���������\n";
	cout << "8. ��������� ���������\n";
	cout << "9. ������������� ���������\n";
	cout << "10. ����� ���������\n";
	cout << "11. ���������� ���������� �����\n";
	cout << "12. ����� �� �������� ��������������\n";
	cout << "13. ����� �� ���������\n";
}
