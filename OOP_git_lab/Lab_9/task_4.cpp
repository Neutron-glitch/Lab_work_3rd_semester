#include <iostream>
#include <cmath>

using namespace std;

class furniture
{
private:
    string material, product_name;
    float reg_price, disc_price;

public:
    furniture(float a = 0, float b = 0, string s = "") : reg_price(a), disc_price(b), material(s)
    {
    }
    void set()
    {
        cout << "Product name :";
        cin >> product_name;
        cout << "Regular Price :";
        cin >> reg_price;
        cout << "Discounted Price :";
        cin >> disc_price;
        cout << "Material :";
        cin >> material;
    }
    void get()
    {
        cout << "Product name : " << product_name << endl;
        cout << "Regular Price :" << reg_price << endl;
        cout << "Discounted Price :" << disc_price << endl;
        cout << "Material :" << material << endl;
    }

    float discount_price()
    {
        return disc_price;
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
        cout << "enter bed information :" << endl;
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
        cout << "#######################" << endl;
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
        cout << "enter sofa information :" << endl;
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
        cout << "#######################" << endl;
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
        cout << "enter dining table information :" << endl;
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
        cout << "#######################" << endl;
    }
};

void sort_bed_price(Bed **b, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*(b + i))->discount_price() < (*(b + j))->discount_price())
            {
                Bed *temp = *(b + i);
                *(b + i) = *(b + j);
                *(b + j) = temp;
            }
        }
    }
}

void sort_sofa_price(Sofa **b, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*(b + i))->discount_price() < (*(b + j))->discount_price())
            {
                Sofa *temp = *(b + i);
                *(b + i) = *(b + j);
                *(b + j) = temp;
            }
        }
    }
}
void sort_diningTable_price(DiningTable**b, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*(b + i))->discount_price() < (*(b + j))->discount_price())
            {
                DiningTable *temp = *(b + i);
                *(b + i) = *(b + j);
                *(b + j) = temp;
            }
        }
    }
}

int main()
{
    while (1)
    {
        int n;
        cout << "For bed press 1" << endl;
        cout << "For sofa press 2" << endl;
        cout << "For dining table press 3" << endl;
        cout << "Exit press 4" << endl;

        cin >> n;
        if (n == 1)
        {

            cout << "Input number of beds :" << endl;
            int t;
            cin >> t;

            Bed *b[t];
            for (int i = 0; i < t; ++i)
            {
                b[i] = new Bed;
                b[i]->setBed();
                cout << endl;
            }
            sort_bed_price(b, t);

            cout << "the sorted array is :" << endl;
            for (int i = 0; i < t; i++)
            {
                b[i]->productDetails();
            }

            for (int i = 0; i < t; i++)
            {
                delete b[i];
            }
        }
        else if (n == 2)
        {
            cout << "Input number of sofa :" << endl;
            int t;
            cin >> t;

            Sofa *b[t];
            for (int i = 0; i < t; ++i)
            {
                b[i] = new Sofa;
                b[i]->setSofa();
                cout << endl;
            }
            sort_sofa_price(b, t);

            cout << "the sorted array is :" << endl;
            for (int i = 0; i < t; i++)
            {
                b[i]->productDetails();
            }

            for (int i = 0; i < t; i++)
            {
                delete b[i];
            }
        }
        else if (n == 3)
        {
            cout << "Input number of Dining table :" << endl;
            int t;
            cin >> t;

            DiningTable *b[t];
            for (int i = 0; i < t; ++i)
            {
                b[i] = new DiningTable;
                b[i]->setDiningTable();
                cout << endl;
            }
            sort_diningTable_price(b, t);

            cout << "the sorted array is :" << endl;
            for (int i = 0; i < t; i++)
            {
                b[i]->productDetails();
            }

            for (int i = 0; i < t; i++)
            {
                delete b[i];
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}
