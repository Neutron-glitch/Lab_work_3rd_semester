#include <bits/stdc++.h>

using namespace std;

int main()
{  
    // taking 2 vectors. One for the inputs and other for the frequency

    vector<int> vec;
    vector<int> count;


    // taking inputs until finding negetive or zero 

    while (1)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
            vec.push_back(temp);
        else
            break;
    }

    //assingning all the values in count vector to zero

    count.assign(10, 0);

   

   /*going through the vect vector and increasing the frequency of the index of the count vector
     for example - when we found 3 in vect we increased value of count[3] by 1 */

    for (int i = 0; i < vec.size(); i++)
    {
        int p = vec[i];

        if (p > 0)
            count[p]++;
    }

    
    int index;


    /* looping through the count vector to find the highest frequency and on the process printing it . 
        after that going through the same process to find the next highest number*/
        
    while (1)
    {
        int max = -99;

        for (int i = 1; i <= 9; i++)
        {

            if (count[i] > max)
            {
                max = count[i];
                index = i;
            }
        }
        if (max > 0)
        {
            cout << index << " occurs " << count[index] << " times" << endl;
            count[index] = 0;
        }
        else
            break;
    }

    return 0;
}