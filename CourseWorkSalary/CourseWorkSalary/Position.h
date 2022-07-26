#pragma once
#include "Object.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/* ����� Position
*
* �������� ���������� � ���������
*/

class Position : public Object {
	int id; //����������������� �����
	string position; //���������
	float salary = 0; //�����
    float reward; //������

public:
	//����������� � �����������
	Position(int, string, float, float);
	//����������� �����������
	Position(const Position&);

	void Initialization();

	int getID() const;
	string  getPosition() const;
    float getSalary() const;
	float getReward() const;

	void setPosition(string);
	void setSalary(float);
	void setReward(float);

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