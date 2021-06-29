#include <iostream>

using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    // Rectangle() : length(1), width(1)
    // {
    // }
    Rectangle(float l = 1, float w = 1) : length(l), width(w)
    {
        setValue(l, w);
    }

    float perimeter()
    {
        return (2 * (length + width));
    }

    float area()
    {
        return (length * width);
    }

    void setValue(float l, float w)
    {
        if (l >= 1.0 && l < 20.0)
            length = l;
        else
            length = 1;
        if (w >= 1.0 && w < 20.0)
            width = w;
        else
            width = 1;
    }
    float get_length()
    {
        return length;
    }
    float get_width()
    {
        return width;
    }
};

int main()
{
    Rectangle sample(3, 20);

    cout << "length : " << sample.get_length() << endl;
    cout << "width :" << sample.get_width() << endl;
    cout<<"Area :"<<sample.area()<<endl;
    cout<<"Perimeter :"<<sample.perimeter()<<endl;

    return 0;
}