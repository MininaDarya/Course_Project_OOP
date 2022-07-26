#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

/* Абстрактный класс Account
*
* позволяет создавать аккаунты администраторов и сотрудников
* содержит информацию о логине и пароле
*
* Базовый класс для Employee и Admin
*/

class Account
{
	string login; //логин
	string password; //пароль

public:
	//конструктор с параметрами
	Account(string log, string pass);
	//конструктор копирования
	Account(const Account&);

	string getLogin() const;
	string getPassword() const;
	virtual string getRole() const = 0; //чисто виртуальная функция

	void setLogin(string);
	void setPassword(string);

	//метод для изменения пароля
	void newPassword();
	//статический метод для защищенного ввода пароля(максируется через #)
	static string safeEnter() {
		string tmp;
		do
		{
			unsigned char ch;
			ch = _getch(); //считываем символ с консоли
			if (ch == 13) //сравниваем с '\n'
				break;
			if (ch == '\b' && !tmp.empty())  //сравниваем с ' '
			{
				cout << '\b';
				cout << ' ';
				cout << '\b';
				tmp.pop_back();
				continue;
			}
			//проверим, относиться ли символ к алфавитно-числовым
			if (isalnum((unsigned char)ch))
			{
				cout << '#'; //выводим шифрующий символ 
				tmp.push_back(ch); //добавляем новый символ в пароль
			}
		} while (true);
		return tmp;
	}

	//перегрузка оператора сравнения
	friend bool operator== (const Account&, const Account&);
	//перегрузка оператора присваивания
	Account& operator=(const Account&);

	//проверка корректности пароля (для считанных из файла)
	static bool check(string data)
	{
		for (int i = 0; i < data.length(); i++)
			if (!isalnum(data[i])) 	//проверим, относиться ли символ к алфавитно-числовым
				return false;
		return true;
	}

};