/*
 * Name: Complex Numbers
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 9/5/2019
 */
#include <iostream>
#include <curses.h>

using namespace std;

class ComplexNumber {
private:
    float mReal;
    float mImaginary;

public:
    ComplexNumber(){
        mReal = 0;
        mImaginary = 0;
    }
    ComplexNumber(float real, float imaginary){
        mReal = real;
        mImaginary = imaginary;
    }
    void SetValues(float real, float imaginary){
        mReal = real;
        mImaginary = imaginary;
    }
    void PrintNumber(){
        cout << mReal << ((mImaginary > 0)?" + i":" - i") << ((mImaginary>0)?mImaginary:-1*mImaginary) << endl;
    }
    ComplexNumber operator +(const ComplexNumber &n2){
        return ComplexNumber(mReal+n2.mReal, mImaginary+n2.mImaginary);
    }
    ComplexNumber operator +(const float &real){
        return ComplexNumber(mReal+real, mImaginary);
    }
};

int main()
{
    int choice, numReal1, numImg1, numReal2,numImg2;
    ComplexNumber c1 = ComplexNumber();
    ComplexNumber c2 = ComplexNumber();
    ComplexNumber c3 = ComplexNumber();

    while(1){
        system("CLS");
        cout << "\t\tMain Menu"<<endl;
        cout << "1. Add Complex Numbers\n2. Add Complex Number & Real Number\n0. Exit" <<endl;
        cin >> choice;
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            system("CLS");
            cout << "Enter Real Part of Number 1: ";
            cin >> numReal1;
            cout << "Enter Imaginary Part of Number 1: ";
            cin >> numImg1;
            cout << "Enter Real Part of Number 2: ";
            cin >> numReal2;
            cout << "Enter Imaginary Part of Number 2: ";
            cin >> numImg2;
            c1.SetValues(numReal1,numImg1);
            c2.SetValues(numReal2,numImg2);
            c3 = c1 + c2;
            cout << "Sum of Numbers: ";
            c3.PrintNumber();
            getch();
            break;
        case 2:
            system("CLS");        
            cout << "Enter Real Part of Number 1: ";
            cin >> numReal1;
            cout << "Enter Imaginary Part of Number 1: ";
            cin >> numImg1;
            cout << "Enter Real Number 2: ";
            cin >> numReal2;
            c1.SetValues(numReal1,numImg1);
            c2 = c1 + numReal2;
            cout << "Sum of Numbers: ";
            c2.PrintNumber();
            getch();
            break;
        }
    }
    return 0;
}
