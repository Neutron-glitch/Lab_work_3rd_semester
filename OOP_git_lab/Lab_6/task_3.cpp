#include <iostream>
#include <cmath>

using namespace std;

class Coordinate
{
private:
    float x;
    float y;
    float distance;

public:
    Coordinate(float a = 0, float b = 0) : x(a), y(b)
    {
    }

    void display()
    {
        cout<<"abscissa value :"<<x<<endl;
        cout<<"ordinate value : "<<y<<endl;
    }

    float getDistance(Coordinate c)
    {
        return distance = sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));
    }

    float getDistance()
    {
        return distance = sqrt(x * x + y * y);
    }

    void move_x(float val)
    {
        x = x + val;
    }
    void move_y(float val)
    {
        y = y + val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }

    bool operator>(const Coordinate &rop)
    {
        return (distance > rop.distance);
    }
    bool operator<(const Coordinate &rop)
    {
        return (distance < rop.distance);
    }
    bool operator>=(const Coordinate &rop)
    {
        return (distance >= rop.distance);
    }
    bool operator<=(const Coordinate &rop)
    {
        return (distance <= rop.distance);
    }
    bool operator==(const Coordinate &rop)
    {
        return (distance == rop.distance);
    }
    bool operator!=(const Coordinate &rop)
    {
        return (distance != rop.distance);
    }

    Coordinate operator++()
    {
        //Coordinate temp;
        ++x;
        ++y;
        return Coordinate(x,y);
    }
    Coordinate operator++(int)
    {
        Coordinate temp(x,y);
        ++x;
        ++y;
        return temp;
    }
    Coordinate operator--()
    {
        //Coordinate temp;
        --x;
        --y;
        return Coordinate(x,y);
    }
    Coordinate operator--(int)
    {
        Coordinate temp(x,y);
        --x;
        --y;
        return temp;
    }
    ~Coordinate()
    {
    }
};


int main()
{
    Coordinate c1(3,4),c2(1,1),c3;

    cout<<"c1.getdistance() :"<<c1.getDistance()<<endl;
    cout<<"c1.getdistance(c2) :"<<c1.getDistance(c2)<<endl;
    
    c1.move(5);
    c1.move_x(2);
    c1.move_y(3);

    c1++;

    cout<<"c1.getdistance() :"<<c1.getDistance()<<endl;

    c1.display();

    



}