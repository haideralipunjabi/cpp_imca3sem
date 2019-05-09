/*
 * Name: Complex Numbers
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 9/5/2019
 */
#include <iostream>

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
    ComplexNumber c1 = ComplexNumber(4,-2);
    ComplexNumber c2 = ComplexNumber(8,10);
    ComplexNumber c3 = c1 + c2;
    c1.PrintNumber();
    c2.PrintNumber();
    c3.PrintNumber();
    return 0;
}
