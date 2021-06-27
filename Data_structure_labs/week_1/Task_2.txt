#include <bits/stdc++.h>

using namespace std;


// finding factorial using iteration  

int factorial_using_iteration(int n)
{
    int factorial = 1;

    for (int i = n; i > 0; i--)
        factorial = factorial * i;

    return factorial;
}

//fining factorial using recursion

int factorial_using_recursion(int n)
{
    if (n > 1)
        return n * factorial_using_recursion(n - 1);
    else
        return 1;
}


// main function

int main()
{
    int number, factorial_itr, factorial_rec;
    cin >> number;

    factorial_itr = factorial_using_iteration(number);
    cout << factorial_itr << " (using iteration)" << endl;

    factorial_rec = factorial_using_recursion(number);
    cout << factorial_rec << " (using recursion)" << endl;

    return 0;
}