#include "Object.h"

void Object::AddCount() 
{
	count_acc++;
}

int Object::GetCount() 
{
	return count_acc;
}

void Object::InitCount(int count) 
{
	count_acc = count;
}

int Object::count_acc = 0;