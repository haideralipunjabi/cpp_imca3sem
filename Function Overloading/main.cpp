/*
 * Name: Function Overloading C++
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 8/5/2019
 */
#include <iostream>

using namespace std;

class AreaCalculator {

public:
    void Calculate(int side) {
        cout << "Area of Square: " << side*side << endl;
    }
    void Calculate(int length, int breadth){
        cout << "Area of Breadth: " << length*breadth << endl;
    }
    void Calculate(double radius){
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

int main()
{
    AreaCalculator ac = AreaCalculator();
    ac.Calculate(10);       // Area of Square
    ac.Calculate(5,10);     // Area of Rectangle
    ac.Calculate(10.10);    // Area of Circle
    return 0;   
}
