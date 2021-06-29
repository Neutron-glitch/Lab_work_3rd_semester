#include <iostream>

using namespace std;

class Flight
{
private:
    int flight_no;
    string destination;
    float distance;
    float max_fuel_capacity;

    void Cal_fuel()
    {   
        cout<<"------------------------------------"<<endl;
        if( ((distance<=1000) && (max_fuel_capacity>=500))  || 
        ((distance > 1000 || distance<=2000) && (max_fuel_capacity>=1100)) || 
        ((distance>2000) && (max_fuel_capacity>=2200))   )
        {
            cout<<"Fuel Capacity is fit for this flight"<<endl;
        }
        else
            cout<<"Not sufficient Fuel Capacity for this flight"<<endl;
    }

public:
    void feed_info()
    {
        cout<<"Enter values :"<<endl;
        cout<<"Flight number :";
        cin>>flight_no;
        cout<<"Destination :";
        cin>>destination;
        cout<<"Distance :";
        cin>> distance;
        cout<<"Max Fuel Capacity :";
        cin>>max_fuel_capacity;
    }
    void showInfo()
    {   
        cout<<"The values are :"<<endl;
        cout<<"Flight number :";
        cout<<flight_no<<endl;
        cout<<"Destination :";
        cout<<destination<<endl;
        cout<<"Distance :";
        cout<< distance<<endl;
        cout<<"Max Fuel Capacity :";
        cout<<max_fuel_capacity<<endl;
        Cal_fuel();
    }
};

int main()
{
    Flight sample;
    sample.feed_info();
    sample.showInfo();
    

}

