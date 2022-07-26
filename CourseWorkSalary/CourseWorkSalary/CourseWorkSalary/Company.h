#pragma once
#include "Salary.h"
#include <vector>

/*����� Company
*
* �������� ��� ������ � ��������, � �����
* ��������� � ��������� ��� ��������� �������� � ���
*/

class Company
{
    vector<Employee> employee; //������ �����������
    vector<Position> positions; //������ ����������
    string employeeFile; //��� ����� � ������� � �����������
    string positionsFile; //��� ����� � ������� � ����������
    string reportFile; //��� ����� � �������
public:
    //����������� � �����������
    Company(string, string, string);
    //����������� �����������
    Company(const Company&);
    ~Company();

    vector<Employee> getEmployee() const;
    vector<Position> getPositions() const;
    string getEmployeeFile() const;
    string getPositionsFile() const;
    string getReportFile() const;

    void setEmployee(vector< Employee>);
    void setPositions(vector< Position>);
    void setEmployeeFile(string);
    void setPositionsFile(string);
    void setReportFile(string);

    //�������� ��� �����������
    void printPositions();
    void positionsFromFile();
    void positionsToFile();
    void sortPositions();
    bool searchPosition(Position&);
    void filterPosition();
    Position createNewPosition();
    bool addPosition(Position&);
    bool deletePosition();
    bool editPosition();

    //�������� ��� ������������
    void printEmployee();
    void employeeFromFile();
    void employeeToFile();
    void sortEmployee();
    bool searchEmployee(typename Employee&);
    void filterEmployee();
    typename Employee createNewEmployee();
    bool addEmployee(typename Employee&);
    bool deleteEmployee();
    bool editEmployee();

    //������ ��� ������� ���������� �����
    void calculateSalaryFor(typename Employee&);
    void calculateSalary();

    //�����������
    int authorization(string, string);
    //����� ���������� �� ������
    typename Employee getEmployeeByLogin(string);

    //����������� ������ ��� �������� ������������ ����� 
    //������ �����
    static bool intNumberCheck(string str) {
        for (unsigned int i = 0; i < str.size(); i++)
            if (!isdigit(str[i])) //�������� �� ������ ������
                return false;
        return true;
    }
};