/* C++ Program to build Simple calculator using Class template  */

#include <iostream>
#include<string>
using namespace std;

template <class T>
class Calculator
{
private:
        T num1, num2;

public:
        Calculator(T n1, T n2)
        {
                num1 = n1;
                num2 = n2;
        }

        void displayResult()
        {
                cout << "Numbers are: " << num1 << " and " << num2 << "." << endl;
                cout << "Addition is: " << add() << endl;
                cout << "Subtraction is: " << subtract() << endl;
                cout << "Product is: " << multiply() << endl;
                cout << "Division is: " << divide() << endl;
        }

        T add() { return num1 + num2; }

        T subtract() { return num1 - num2; }

        T multiply() { return num1 * num2; }

        T divide() { return num1 / num2; }
};


template <>
class Calculator<string>
{
private:
        string num1, num2;

public:
        Calculator(string n1, string n2)
        {
                num1 = n1;
                num2 = n2;
        }

        void displayResult()
        {
                cout << "string are: " << num1 << " and " << num2 << "." << endl;
                cout << "Addition is: " << add() << endl;

        }

        string add() { return num1 + num2; }


};


int main()
{
        Calculator<int> intCalc(3, 2);
        Calculator<float> floatCalc(3.4, 4.2);

        cout << "Int results:" << endl;
        intCalc.displayResult();

        cout << endl << "Float results:" << endl;
        floatCalc.displayResult();

        cout<<"\n\n";

Calculator<string> stringCalc("hello" ," world");
cout << "string results:" << endl;
       stringCalc.displayResult();


        return 0;
}
