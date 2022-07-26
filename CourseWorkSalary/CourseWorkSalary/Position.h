#pragma once
#include "Object.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/* Класс Position
*
* содержит информацию о должности
*/

class Position : public Object {
	int id; //идентификационный номер
	string position; //должность
	float salary = 0; //оклад
    float reward; //премия

public:
	//конструктор с параметрами
	Position(int, string, float, float);
	//конструктор копирования
	Position(const Position&);

	void Initialization();

	int getID() const;
	string  getPosition() const;
    float getSalary() const;
	float getReward() const;

	void setPosition(string);
	void setSalary(float);
	void setReward(float);

	//методы для редактирования
	void editSalary();
	void editPosition();
	void editReward();

	//редактирование
	void editData();
	//меню редактирования
	void editMenu();

	//перегрузка оператора вывода
	friend ostream& operator<< (ostream&, const Position&);
	//перегрузка оператора сравнения
	friend bool operator== (const Position&, const Position&);
	//перегрузка оператора присваивания
	Position& operator=(const Position&);
};