#include<iostream>

using namespace std;

class Complex
{
    private:
      int imag2;
    public:
    int imag;
    int real;

Complex()
{

}
void setdata(int i, int r)
    {
        imag = i;
        real =r;
    }
     void getdata()
    {
        cout<<"\n imaginary part is "<<imag<< " real part is " <<real<<endl;
    }


Complex operator+(Complex obj2)
    {
        Complex obj3;

        obj3.imag = imag + obj2.imag;
        obj3.real = real + obj2.real;
     return obj3;
    }


Complex operator++()
    {
        Complex obj3;

        obj3.imag = ++imag;
        obj3.real = ++real;
     return obj3;
    }

Complex operator++(int)
    {
        Complex obj3;

        obj3.imag = imag++;
        obj3.real = real++;
     return obj3;
    }

Complex(const Complex  &obj)
{
    imag = obj.imag;
    real = obj.real;
}


friend Complex operator*(Complex obj1, Complex obj2)
    {
        Complex obj3;

obj1.imag2 = obj2.imag2 = 5;
        obj3.imag2 = obj1.imag2 * obj2.imag2;
        obj3.imag = obj1.imag * obj2.imag;
        obj3.real = obj1.real * obj2.real;

     return obj3;
    }



};



Complex operator-(Complex obj1 , Complex obj2)
    {
        Complex obj3;

        obj3.imag = obj1.imag - obj2.imag;
        obj3.real = obj1.real - obj2.real;
     return obj3;
    }


int main()
{

    Complex obj1 , obj2, obj3;
    obj1.setdata(10,15);
    obj1.getdata();

    obj2.setdata(2,3);

obj2.getdata();
/*
    obj3 = obj1 + obj2 ;
    obj3.getdata();



        obj3.getdata();

        ++obj3;


        obj3.getdata();

        obj3++;

        obj3.getdata();

        Complex obj4 = obj3++;
        Complex obj5 = ++obj3;

        obj4.getdata();
        obj5.getdata();

Complex obj6 = obj3 - obj2;


obj6.getdata();
*/
Complex obj7 = obj1*  obj2;
obj7.getdata();

}


