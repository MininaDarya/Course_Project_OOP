#pragma once

/*����������� ����� Object, ������� ����� ����������� �������, 
���������������� � ����������� �������
*/

class Object
{
	static int count_acc;

public:
	static void AddCount();
	static int GetCount();
	static void InitCount(int);
	virtual void Initialization() = 0;
};