#include<iostream>
using namespace std;

void check_palindrome(string& s, int ptr1, int ptr2)
{
    if(ptr1 >= ptr2) {
        cout << "palindrome string." << endl;
        return ;
    }
    if(s[ptr1] != s[ptr2]) 
    {
        cout << "not a palindrome string." << endl;
        return ;
    }
    check_palindrome(s, ptr1+1, ptr2-1);
}

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    check_palindrome(s, 0, s.length()-1);

    return 0;
}