#include <iostream>
#include <cmath>

using namespace std;

class furniture
{
private:
    string material;
    float reg_price, disc_price;

public:
    furniture(float a = 0, float b = 0, string s = "") : reg_price(a), disc_price(b), material(s)
    {
    }
    void set()
    {
        cout << "Regular Price :";
        cin >> reg_price;
        cout << "Discounted Price :";
        cin >> disc_price;
        cout << "Material :";
        cin >> material;
    }
    void get()
    {
        cout << "Regular Price :" << reg_price << endl;
        cout << "Discounted Price :" << disc_price << endl;
        cout << "Material :" << material << endl;
    }
};

class Bed : public furniture
{
private:
    string bed_size;

public:
    Bed(string a = "") : bed_size(a)
    {
    }
    void set_size()
    {
        cout << "Bed size :";
        cin >> bed_size;
    }
    void setBed()
    {   
        cout<<"enter bed information :"<<endl;
        set();
        set_size();
    }
    void get_size() const
    {
        cout << " Bed size :" << bed_size << endl;
    }
    void productDetails()
    {
        get();
        get_size();
        cout<<"#######################"<<endl;
    }
};

class Sofa : public furniture
{
private:
    string seat_no;

public:
    Sofa(string a = "") : seat_no(a)
    {
    }
    void set_no()
    {
        cout << "Seat Number: ";
        cin >> seat_no;
    }
    void setSofa()
    {
        cout<<"enter sofa information :"<<endl;
        set();
        set_no();
    }
    void get_sofa() const
    {
        cout << " Seat no :" << seat_no << endl;
    }
    void productDetails()
    {
        get();
        get_sofa();
        cout<<"#######################"<<endl;
    }
};

class DiningTable : public furniture
{
private:
    string chairCount;

public:
    DiningTable(string s = "") : chairCount(s)
    {
    }
    void setCount()
    {
        cout << "Chair Count: ";
        cin >> chairCount;
    }
    void setDiningTable()
    {   
        cout<<"enter dining table information :"<<endl;
        set();
        setCount();
    }
    void getCount()
    {
        cout << "Chair Count: " << chairCount << endl;
    }
    void productDetails()
    {
        get();
        getCount();
        cout<<"#######################"<<endl;
    }
};

int main()
{

    Bed b;
    b.setBed();
    cout << "---------------------" << endl;
    b.productDetails();

    Sofa s;
    s.setSofa();
    cout << "---------------------" << endl;
    s.productDetails();

    DiningTable d;
    d.setDiningTable();
    cout << "---------------------" << endl;
    d.productDetails();
}
