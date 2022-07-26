#pragma once
#include "Salary.h"
#include "Object.h"
#include <vector>

/*Класс Company
*
* содержит все данные о компании, а также
* описывает и реализует все возможные действия в ней
*/

class Company : public Object
{
    vector<Employee> employee; //список сотрудников
    vector<Position> positions; //список должностей
    string employeeFile; //имя файла с данными о сотрудниках
    string positionsFile; //имя файла с данными о должностях
    string reportFile; //имя файла с отчетом

public:
    //конструктор с параметрами
    Company(string, string, string);
    //конструктор копирования
    Company(const Company&);
    //перегрузка конструктора с параметрами
    Company(string empFile, string posFile);
    ~Company();

    void Initialization();
   
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

    //действия над должностями
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

    //действия над сотрудниками
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
    int GetCountOfEmployess();

    //методы для расчета заработной платы
    void calculateSalaryFor(typename Employee&);
    void calculateSalary();

    //авторизация
    int authorization(string, string);
    //поиск сотрудника по логину
    typename Employee getEmployeeByLogin(string);

    //статические методы для проверки корректности ввода 
    //целого числа
    static bool intNumberCheck(string str) 
    {
        for (unsigned int i = 0; i < str.size(); i++)
            if (!isdigit(str[i])) //является ли символ цифрой
                return false;
        return true;
    }
};