#include <iostream>

using namespace std;

class Counter
{
private:
    int count;
    int step_value;

public:
    Counter(int c = 0) : count(c)
    {
    }

    void setIncrementStep(int step_val = 1)
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
    int getstep()
    {
        return step_value;
    }

    friend Counter operator+(const Counter &lop, const Counter &rop);
    friend Counter operator+(const Counter &lop, int var);
    friend Counter operator+(int var, const Counter &rop);
    friend Counter operator+=(Counter &lop, const Counter &rop);
    friend Counter operator++(Counter &lop);
    friend Counter operator++(Counter &lop, int);
};

Counter operator+(const Counter &lop, const Counter &rop)
{
    //return Counter(count + r_count.count );

    Counter temp;
    temp.count = lop.count + rop.count;
    if (lop.step_value < rop.step_value)
        temp.step_value = lop.step_value;
    else
        temp.step_value = rop.step_value;

    return temp;
}

Counter operator+(const Counter &lop, int var)
{
    // return Counter(lop.count + var);

    Counter temp;
    temp.count = lop.count + var;

    temp.step_value = lop.step_value;

    return temp;
}

Counter operator+(int var, const Counter &rop)
{
    Counter temp;
    temp.count = rop.count + var;

    temp.step_value = rop.step_value;

    return temp;
}

// removing const as we need to change the lop value
Counter operator+=(Counter &lop, const Counter &rop)
{

    lop.count = lop.count + rop.count;
    //temp.step_value = lop.step_value;
    //return temp;
    //return
}

Counter operator++(Counter &lop)
{
    return Counter(++lop.count);
}

Counter operator++(Counter &lop, int)
{
    return Counter(lop.count++);
}



int main()
{
    Counter c1, c2, c3(5);
    c2.setIncrementStep(11);
    c3.setIncrementStep(15);

    c1 = c2 + c3;

    cout << c1.getCount() << endl;

    cout << c1.getstep() << endl;

    c1 += c3;
    cout << "c1+=c3 :" << c1.getCount() << endl;
    c1 = ++c1;
    cout << "++c1 :" << c1.getCount() << endl;
    c1 = c1++;
    cout<<"c1 ++ :"<<c1.getCount()<<endl;

    return 0;
}