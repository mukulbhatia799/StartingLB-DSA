// reverse a string using recursion

#include<bits/stdc++.h>
using namespace std;

// using extra storage variable to store the answer.
void reverseString(string s, int size, string& ans)
{
    if(size == -1) return ;
    ans.push_back(s[size]);
    reverseString(s, size-1, ans);
}


// without using aux string to store ans. Store IN-PLACE.
void reverseString2(string &s, int start, int end)
{
    if(start >= end) return ;
    swap(s[start], s[end]);
    reverseString2(s, start+1, end-1);
}


int main(){
    string s;
    cout << "Enter a string to reverse: ";
    getline(cin, s);

    // string ansstr;
    // reverseString(s, s.length()-1, ansstr);
    // cout << "Reverse string: " << ansstr << endl;


    reverseString2(s, 0, s.length()-1);
    cout << "reverse string: " << s << endl;


    return 0;
}