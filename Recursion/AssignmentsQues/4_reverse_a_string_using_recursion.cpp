// reverse a string using recursion

#include <bits/stdc++.h>
using namespace std;

// using extra storage variable to store the answer.
void reverseString(string s, int size, string &ans)
{
    if (size == -1)
        return;
    ans.push_back(s[size]);
    reverseString(s, size - 1, ans);
}

// without using aux string to store ans. Store IN-PLACE.
void reverseString2(string &s, int start, int end)
{
    if (start >= end)
        return;
    swap(s[start], s[end]);
    reverseString2(s, start + 1, end - 1);
}

int main()
{
    string s;
    cout << "Enter a string to reverse: ";
    getline(cin, s);

    // string ansstr;
    // reverseString(s, s.length()-1, ansstr);
    // cout << "Reverse string: " << ansstr << endl;

    reverseString2(s, 0, s.length() - 1);
    cout << "reverse string: " << s << endl;

    return 0;
}

/*
// reverse a string using recursion.

#include<iostream>
using namespace std;

void reverseRE(string& s, int start, int end)
{
    // base case
    if(start >= end) return ;
    // one cond.
    swap(s[start], s[end]);
    // recursive func.
    reverseRE(s, start+1, end-1);
}

int main(){
    string s = "abcdefg";

    cout << "before: ";
    for(auto it: s) cout << it;
    cout << endl;

    int start = 0, end = s.length()-1;
    reverseRE(s, start, end);

    cout << "after: ";
    for(auto it: s) cout << it;



    return 0;
}

*/