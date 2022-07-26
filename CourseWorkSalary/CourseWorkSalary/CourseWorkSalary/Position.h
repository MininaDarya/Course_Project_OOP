#pragma once
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* Класс Position
*
* содержит информацию о должности
*/

class Position {
	unsigned int id; //идентификационный номер
	string position; //должность
	int salary = 0; //оклад
	int reward; //премия

public:
	//конструктор с параметрами
	Position(int, string, int, int);
	//конструктор копирования
	Position(const Position&);

	int getID() const;
	string  getPosition() const;
	int  getSalary() const;
	int getReward() const;

	void setPosition(string);
	void setSalary(int);
	void setReward(int);

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