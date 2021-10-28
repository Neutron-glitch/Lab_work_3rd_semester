
//https://docs.google.com/document/d/1RLqO_hpENkUBNtecOpFjCfZ7tYMc19X7uhTftaMwUAs/edit

#include <iostream>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    bool endmark;
    struct Node *next[26];
    int count;
    Node()
    {
        endmark = false;
        count = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

struct Node *root = new Node();

void insert_trie(string str)
{
    struct Node *curr = root;

    
    for (int i = 0; i < str.length(); i++)
    {
        int id = str[i] - 'a';

        if (curr->next[id] == NULL)
        {
            curr->next[id] = new Node();
        }
        curr ->count++;
        curr = curr->next[id];
    }

    curr->endmark = true;
    curr-> count++;
}

int finding_prefix(string prefix)
{
    Node *curr = root;


    for (int i = 0; i < prefix.length(); i++)
    {
        int id = prefix[i] - 'a';

        if (curr->next[id] == NULL )
            return 0;
        curr = curr ->next[id];
    }
    return curr->count;  
}

int main()
{

    int a, b;

    cin >> a;
    cin >> b;
    cin.ignore();

    for(int i=0; i<a;i++)
    {
        string s;
        getline(cin, s);
        cout<<s<<endl;
        
        // transform(s.begin() ,  s.end() , ::tolower);

        for (int j = 0; j < s.length(); j++)
        {
            s[j] = tolower(s[j]);
        }
        s[s.length()]='\0';
        
        cout<<s<<endl;

        insert_trie(s);
    }

    while (b--)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            s[j] = tolower(s[j]);
        }

        int ans = finding_prefix(s);

        cout << ans << endl;
    }
}
