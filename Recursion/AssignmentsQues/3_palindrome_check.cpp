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


// revision 1
// #include<iostream>
// using namespace std;

// bool checkPalindromeRE(string& s, int i)
// {
//     if(i >= s.length()/2)
//     {
//         return true;
//     }
//     if(s[i] != s[s.length()-1-i]) return false;
//     checkPalindromeRE(s, i+1);
// }

// int main(){
//     string s = "momomo";

//     bool ans = checkPalindromeRE(s, 0);

//     if(ans == true) cout << "palindrome" << endl;
//     else cout << "not a palindrome" << endl;

//     return 0;
// }