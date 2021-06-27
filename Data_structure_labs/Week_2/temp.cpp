#include <bits/stdc++.h>

using namespace std ;

class Foo
{
    private:
        int mem_c;
    public :
        Foo() : mem_c(5)
        {
            cout<< "ctor is called"<<endl;
        }
        ~Foo()
        {
            cout<<"dtor is called"<<endl;
        }
};

int func()
{
    Foo fl;
    return 5;
}

int main()
{
    int c =func();
    cout<<c;
}


class MyInt
{ 
private:
         int data;
public :
         Myint() :  data(0)
         {  
             
        }
    void add(int c)
{    
       data = data +c; 
} 

int getInt()
{ 
  return data;
}