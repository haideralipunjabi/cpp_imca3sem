/*
 * Name: Inheritance C++
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 24/4/2019
 */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
//#include <curses.h>
#include <conio.h>
#include <string>

using namespace std;

class Person{
private:
    string mName;
    string mAddress;
    class Date {
    private:
        int mDay;
        int mMonth;
        int mYear;
        int mAge;
    public:
        void GetData(){
            cout << "Enter Day: " << endl;
            cin >> mDay;
            cout << "Enter Month: " << endl;
            cin >> mMonth;
            cout << "Enter Year: " << endl;
            cin >> mYear;
            mAge = 2019 - mYear;
        }
        void PrintInfo(){
            cout << "Date: " << setw(2) << setfill('0') << mDay << "-" << setw(2) << setfill('0') << mMonth << "-" << mYear << "\nAge: " << mAge << endl;
        }
    } mDOB;
public:
    void GetData(){
       cout << "Enter Name: " << endl;
       cin.clear();
       cin.sync();
       getline(cin,mName);
       cout << "Enter Address: " << endl;
       getline(cin,mAddress);
       mDOB.GetData();
    }
    void PrintInfo(){
        cout << "\t\tPersonal Information"<<endl;
        cout << "Name: " << mName << "\nAddress: "<< mAddress <<endl;
        mDOB.PrintInfo();
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
        cin.clear();
        cin.sync();
        getline(cin,mCourseId);
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
class Specialization{
private:
    string mSubject;
    int mExp;
public:
    void GetData(){
        cout << "Enter Subject of Research: " << endl;
        cin.clear();
        cin.sync();
        getline(cin,mSubject);
        cout << "Enter Experience: " << endl;
        cin >> mExp;
    }
    void PrintInfo(){
        cout << "\t\tSpecialization" << endl;
        cout << "Subject of Research: " << mSubject << "\nExperience: " << mExp << endl;
    }
};

class Bonus {
public:
    float mBonus;
};

class Employee:Person,Bonus{
private:
    string mJobTitle;
    float mBasicSalary;
    float mGrossSalary;
public:
    Employee(){
        mBonus = 0.0;
        mGrossSalary = 0.0;
    }
    Employee(string JobTitle){
        mJobTitle = JobTitle;
    }
    void GetData(){
        Person::GetData();
        if(mJobTitle==""){
            cout << "Enter Job Title: " << endl;
            cin.clear();
            cin.sync();
            getline(cin,mJobTitle);
        }
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

class Teacher:Employee,Specialization{

public:
    Teacher():Employee("Teacher"){}
    void GetData(){
        Employee::GetData();
        Specialization::GetData();
    }
    void PrintInfo(){
        Employee::PrintInfo();
        Specialization::PrintInfo();
    }
    void SetBonusPercentage(float bonusPercentage){
        Employee::SetBonusPercentage(bonusPercentage);
    }
    void SetBonusAmount(float bonusAmount){
        Employee::SetBonusAmount(bonusAmount);
    }
    void CalculateGrossSalary(){
        Employee::CalculateGrossSalary();
    }
};

int main()
{
    int choice, choiceStudent, choiceEmployee,choiceTeacher;
    Student students[100];
    int studentCount =0;
    Employee employees[100];
    int employeeCount = 0;
    Teacher teachers[100];
    int teacherCount = 0;
    float tempEmployeeBonusPercentage, tempEmployeeBonusAmount;
    while(1){
        system("CLS");
        cout << "\t\tMain Menu"<<endl;
        cout << "1. Student\n2. Employee\n3. Teacher\n0. Exit\nEnter Choice: "<< endl;
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
        case 3:
            system("CLS");
            cout << "\t\Teacher Menu"<<endl;
            cout << "1. Create Teacher\n2. Calculate Gross Salaries\n3. Give Bonus(percentage)\n4. Give Bonus(Amount)\n5. Show All Teachers\n0. Go Back" <<endl;
            cin >> choiceTeacher;
            switch(choiceTeacher){
            case 0:
                break;
            case 1:
                teachers[teacherCount++].GetData();
                break;
            case 2:
                for(int i=0;i<teacherCount;i++){
                    teachers[i].CalculateGrossSalary();
                }
                break;
            case 3:
                cout<<"Enter Bonus Percentage"<<endl;
                cin >> tempEmployeeBonusPercentage;
                for(int i=0;i<teacherCount;i++){
                    teachers[i].SetBonusPercentage(tempEmployeeBonusPercentage);
                }
                break;
            case 4:
                cout<<"Enter Bonus Amount"<<endl;
                cin >> tempEmployeeBonusAmount;
                for(int i=0;i<teacherCount;i++){
                    teachers[i].SetBonusAmount(tempEmployeeBonusAmount);
                }
                break;
            case 5:
                for(int i=0;i<teacherCount;i++){
                    teachers[i].PrintInfo();
                }
                getch();
                break;
            }
            break;
        }

    }

    return 0;
}
