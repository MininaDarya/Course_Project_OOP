#pragma once
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* ����� Position
*
* �������� ���������� � ���������
*/

class Position {
	unsigned int id; //����������������� �����
	string position; //���������
	int salary = 0; //�����
	int reward; //������

public:
	//����������� � �����������
	Position(int, string, int, int);
	//����������� �����������
	Position(const Position&);

	int getID() const;
	string  getPosition() const;
	int  getSalary() const;
	int getReward() const;

	void setPosition(string);
	void setSalary(int);
	void setReward(int);

	//������ ��� ��������������
	void editSalary();
	void editPosition();
	void editReward();

	//��������������
	void editData();
	//���� ��������������
	void editMenu();

	//���������� ��������� ������
	friend ostream& operator<< (ostream&, const Position&);
	//���������� ��������� ���������
	friend bool operator== (const Position&, const Position&);
	//���������� ��������� ������������
	Position& operator=(const Position&);
};