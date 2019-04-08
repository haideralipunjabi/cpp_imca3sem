#include <iostream>

using namespace std;

class Person {
private:
    string name;
    string address;
    int age;
public:
    Person(string n , string add, int ag){
        name = n;
        address = add;
        age = ag;
    }
    void print(){
        cout << "Name: " << name << "\nAddress: " << address << "\nAge: " << age << endl;
    }
};
class Student:public Person {
private:
    int reg_no;
    int marks;
public:
    Student(string n, string add, int ag, int r, int m):Person(n, add,ag){
        reg_no = r;
        marks = m;
    }
    void print(){
        Person::print();
        cout << "Reg No.: " << reg_no << "\nMarks: " << marks << endl;
    }
    void setMarks(int m){
        marks = m;
    }
};
int main()
{
    Student s1 = Student("Haider", "Nishat", 19, 18600003, 100);
    s1.print();
    Student s2 = s1;
    s1.setMarks(10);
    s1.print();
    s2.print();
    return 0;

}
