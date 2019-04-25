/*
 * Name: Inheritance C++
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 24/4/2019
 */
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Person{
private:
    string mName;
    string mAddress;
    int mAge;
public:
    void GetData(){
       cout << "Enter Name: " << endl;
       cin >> mName;
       cout << "Enter Address: " << endl;
       cin >> mAddress;
       cout << "Enter Age: " << endl;
       cin >> mAge;
    }
    void PrintInfo(){
        cout << "\t\tPersonal Information"<<endl;
        cout << "Name: " << mName << "\nAge: " << mAge <<"\nAddress: "<< mAddress <<endl;
    }
};

class Student:Person{
private:
    string mCourseId;
    int mRegdNo;
    int mMarks;
public:
    void GetData(){
        Person::GetData();
        cout << "Enter Course ID: " << endl;
        cin >> mCourseId;
        cout << "Enter Registration No.: " << endl;
        cin >> mRegdNo;
        cout << "Enter Marks: " << endl;
        cin >> mMarks;
    }
    void PrintInfo(){
        Person::PrintInfo();
        cout << "\t\tStudent Information"<<endl;
        cout << "Course ID: " << mCourseId << "\nRegistration No.: " << mRegdNo <<"\nMarks: "<< mMarks <<endl;
    }
};
class Employee:Person{
private:
    string mJobTitle;
    float mBasicSalary;
    float mBonus;
    float mGrossSalary;
public:
    Employee(){
        mBonus = 0.0;
        mGrossSalary = 0.0;
    }
    void GetData(){
        Person::GetData();
        cout << "Enter Job Title: " << endl;
        cin >> mJobTitle;
        cout << "Enter Basic Salary.: " << endl;
        cin >> mBasicSalary;
    }
    void PrintInfo(){
        Person::PrintInfo();
        cout << "\t\tEmployee Information"<<endl;
        cout << "Job Title: " << mJobTitle << "\nBasic Salary: " << mBasicSalary <<"\nGross Salary: "<< mGrossSalary << "\nBonus: " << mBonus <<endl;
    }
    void SetBonusPercentage(float bonusPercentage){
        mBonus = mBasicSalary * (bonusPercentage / 100);
    }
    void SetBonusAmount(float bonusAmount){
        mBonus = bonusAmount;
    }
    /*
     * Gross Salary = Basic Salary + 9% of Basic Salary + 16% of Basic Salary
     */
    void CalculateGrossSalary(){
        mGrossSalary = mBasicSalary * 1.25 + mBonus;
    }

};
int main()
{
    int choice, choiceStudent, choiceEmployee;
    Student students[100];
    int studentCount =0;
    Employee employees[100];
    int employeeCount = 0;
    float tempEmployeeBonusPercentage, tempEmployeeBonusAmount;
    while(1){
        system("CLS");
        cout << "\t\tMain Menu"<<endl;
        cout << "1. Student\n2. Employee\n0. Exit\nEnter Choice: "<< endl;
        cin >> choice;
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            system("CLS");
            cout << "\t\tStudent Menu"<<endl;
            cout << "1. Create Student\n2. Show All Students\n0. Go Back" <<endl;
            cin >> choiceStudent;
            switch(choiceStudent){
            case 0:
                break;
            case 1:
                students[studentCount++].GetData();
                break;
            case 2:
                for(int i=0;i<studentCount;i++){
                    students[i].PrintInfo();
                }
                getch();
                break;
            }
            break;
        case 2:
            system("CLS");
            cout << "\t\tEmployee Menu"<<endl;
            cout << "1. Create Employee\n2. Calculate Gross Salaries\n3. Give Bonus(percentage)\n4. Give Bonus(Amount)\n5. Show All Employees\n0. Go Back" <<endl;
            cin >> choiceEmployee;
            switch(choiceEmployee){
            case 0:
                break;
            case 1:
                employees[employeeCount++].GetData();
                break;
            case 2:
                for(int i=0;i<employeeCount;i++){
                    employees[i].CalculateGrossSalary();
                }
                break;
            case 3:
                cout<<"Enter Bonus Percentage"<<endl;
                cin >> tempEmployeeBonusPercentage;
                for(int i=0;i<employeeCount;i++){
                    employees[i].SetBonusPercentage(tempEmployeeBonusPercentage);
                }
                break;
            case 4:
                cout<<"Enter Bonus Amount"<<endl;
                cin >> tempEmployeeBonusAmount;
                for(int i=0;i<employeeCount;i++){
                    employees[i].SetBonusAmount(tempEmployeeBonusAmount);
                }
                break;
            case 5:
                for(int i=0;i<employeeCount;i++){
                    employees[i].PrintInfo();
                }
                getch();
                break;
            }
            break;
        }
    }

    return 0;
}
