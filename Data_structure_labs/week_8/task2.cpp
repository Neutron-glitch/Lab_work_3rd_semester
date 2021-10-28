#include <bits/stdc++.h>

using namespace std;

// finding the hash value of the string
int hashvalue(string s, int len)
{
    int hash = 0, p = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        hash = hash+ (s[i] * p);
        p =p* 10;
    }
    return hash;
}

bool string_match(string text,  string pattern)
{
    int text_len = text.length();
    int pattern_len = pattern.length();
    if (text_len < pattern_len)
        return false;
   

  
    int power = 1;
    for (int i = 1; i < pattern_len; i++)
        power =power* 10;

    int hash_text = hashvalue(text, pattern_len);
    int hash_pattern = hashvalue(pattern, pattern_len);

    if (hash_text == hash_pattern)
    {
        bool flag = true;
        for (int j = 0; j < pattern_len; j++)
        {
            if (text[j] != pattern[j])
            {
                flag = false;
                break;
            }
        }
            return flag;
    }

    // using rolling hash
    for (int i = pattern_len; i < text_len; i++)
    {

       
        hash_text = hash_text - (power * text[i - pattern_len]);
        hash_text = (hash_text * 10);
        hash_text = (hash_text + text[i]);

        if (hash_text == hash_pattern)
        {
            bool flag = true;

            for (int j = 0, k = i - pattern_len + 1; j < pattern_len; j++, k++)
            {
                if (text[k] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
    }
    return false;
}


int main()
{
    cout<<"Enter text :";
    string text ;
    cin >> text;
    cout<<"Enter times of query :"<<endl;
    int query;
    cin >> query;

    while (query--)
    {   
        string pattern;
        cin >> pattern;

        if( string_match(text, pattern) == true )
            cout<<"Pattern Matched"<<endl;
        else
            cout<<"Did not Matched"<<endl;
    }
    return 0;
}    
    