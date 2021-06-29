#include <iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    void assign(int numer, int denom)
    {
        if (denom != 0)
        {
            numerator = numer;
            denominator = denom;
        }
        else
            cout << "Error : Denominator is zero!! Number not assigned"<<endl;
    }
    double covert()
    {
        double p = (double) numerator;
        double q = (double) denominator;

        double p_q = p/q ;


        return p_q;
    }
    void invert()
    {
        int a,b;
        a = numerator ;
        b= denominator;
      

        assign(b , a);
    }
    void print()
    {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }
};


int main()
{
    RationalNumber r1,r2;
    

    
    r1.assign(10 , 12);
    r1.print();
    cout<<"Double value = "<<r1.covert()<<endl;
    r1.invert();
    r1.print();

    cout<<"--------------------------------------"<<endl;

    r2.assign(15 , 0);
    r2.print();
    cout<<"Double value = "<<r2.covert()<<endl;
    r2.invert();
    r2.print();


    return 0;
}