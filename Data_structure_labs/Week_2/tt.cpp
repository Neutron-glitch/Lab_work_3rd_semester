#include <bits/stdc++.h>

using namespace std;

class Counter
{
private:
    int count;

public:
    int have_count(int co)
    {
        return co;
    }
    int get_count(int c)
    {
        return count;
    }
    ~Counter()
    {
        count << "Counter object destrying\n";
    }
};

int main()
{
    Counter c1;
    count = c1.have_count(5); // initializing the count
                              // variable of c1 object to 5

    cout << c1.get_count(count);
}