#include <iostream>

using namespace std;

class Calculator
{
private:
    int value;
    int temp;

public:
    Calculator() : value(0)
    {
    }
    Calculator(int val) : value(val)
    {
    }
    int getValue()
    {
        return value;
    }
    void setValue(int v)
    {
        value = v;
    }
    void add(int v)
    {   
        cout<<"Add "<<v<<endl;
        value = value + v;
    }
    void subtract(int v)
    {   
        cout<<"Subtract "<<v<<endl;
        value = value - v;
    }
    void multiply(int v)
    {   
        cout<<"Multiply "<<v<<endl;
        value = value * v;
    }
    void divideBy(int v)
    {   
        cout<<"Divide By "<<v<<endl;
        if (v == 0)
        {
            cout << "Error : divide by 0 is undefined ." << endl;
            return;
        }

        value = value / v;
    }
    void clear()
    {   
        cout<<"Clear"<<endl;
        value = 0;
    }
    int display()
    {
        return value;
    }
    ~Calculator()
    {
        cout << "Calculator object is destroyed" << endl;
    }

};

void line()
{
     cout<<"---------------------------------------------------"<<endl;
}


int main()
{
    Calculator sample;

    sample.add(10);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.add(7);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.multiply(31);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.subtract(42);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.divideBy(7);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.divideBy(0);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.add(3);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.subtract(1);
    cout << "Calculator dispaly :" << sample.display() << endl;
    line();

    sample.clear();
    cout << "Calculator dispaly :" << sample.display() << endl;

    return 0;
}