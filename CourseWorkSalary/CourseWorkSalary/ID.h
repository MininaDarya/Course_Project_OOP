#pragma once

/* ������ ������ ID
*
* ������ ��� ����, ����� ���� ����������� ���������
* ��� ����� �������� ����������������� �����(��� ���������������),
* ��� � ��������-�������� (��� �����������)
*/

template <typename T>
class ID
{
private:
    T id; //����������������� �����

public:
    //����������� �� ���������
    ID() {}
    //����������� � ����������
    ID(T id) : id(id) {}
    //����������� �����������
    ID(const ID& I) : id(I.id) {}

    T getId() const
    {
        return id;
    }

    //���������� ��������� ������������
    ID& operator=(const ID& I)
    {
        if (this != &I) //�������� �� ����������������
        {
            id = I.id;
        }
        return *this;
    }
    //���������� ��������� ���������
    friend bool operator== (const ID& i1, const ID& i2)
    {
        return (i1.getId() == i2.getId());
    }
    //���������� ��������� ������
    bool operator< (const ID& I2)
    {
        return (getId() < I2.getId());
    }
    //���������� ��������� ������
    friend ostream& operator<< (ostream& os, const ID& I)
    {
        return os << I.getId();
    }
};