#include <iostream>
#include <cmath>

using namespace std;

class furniture
{
private:
    string name;
    

public:
    furniture( string s = "") : name(s) 
    {
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
        set_size();
    }
    void get_size() const
    {
        cout << " Bed size :" << bed_size << endl;
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
        set_no();
    }
    void get_sofa() const
    {
        cout << " Seat no :" << seat_no << endl;
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
        setCount();
    }
    void getCount()
    {
        cout << "Chair Count: " << chairCount << endl;
    }
    
};

int main()
{

    Bed b;
    b.setBed();
    b.get_size();
   

    Sofa s;
    s.setSofa();
    s.get_sofa();
   

    DiningTable d;
    d.setDiningTable();
    d.getCount();
   
}
