#include <iostream>

using namespace std;

class Counter
{
private:
    int count = 0;
    int step_value;

public:
    void setIncrementStep(int step_val)
    {
        step_value = step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count = count + step_value;
    }
    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    Counter c1, c2;

    c1.setIncrementStep(10);
    cout << "c1 count :" << c1.getCount() << endl;
    c1.increment();
    cout << "c1 count :" << c1.getCount() << endl;
    c1.resetCount();
    cout << "c1 count :" << c1.getCount() << endl;

    cout<<"--------------------"<<endl;

    c2.setIncrementStep(6);
    cout << "c2 count :" << c2.getCount() << endl;
    c2.increment();
    cout << "c2 count :" << c2.getCount() << endl;
    c2.resetCount();
    cout << "c2 count :" << c2.getCount() << endl;

    return 0;
}