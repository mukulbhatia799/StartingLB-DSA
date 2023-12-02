// Permutation of a string
// backtracking :- means to add some additional code to keep the things as it is. Because sometimes we call string by reference and even the arrays are called by reference by default. So, backtracking is an important concept to place all the things back to it's place.
#include <iostream>
using namespace std;

void PermutationOfString(string &s, int ptr)
{
    // base case
    if (ptr == s.length())
    {
        cout << "->" << s << endl;
        return;
    }

    for (int j = ptr; j < s.length(); j++)
    {
        swap(s[j], s[ptr]);
        PermutationOfString(s, ptr + 1); // recursive func.

        // backtracting :- placing all the letters at it's original place if we are calling string by reference because changing the string by reference can change the previous calls strings.
        swap(s[j], s[ptr]); // keeping the string as it is.
    }
}

int main()
{
    string s = "abcde"; // result: abc, acb, bac, bca, cab, cba

    PermutationOfString(s, 0);

    return 0;
}

// revision

// print all permutations of a string using RE.
// using include exclude principle
// #include<iostream>
// using namespace std;

// void printPerm(string& s, int i, string ans)
// {
//     if(i == s.length()) {
//         cout << ans;
//         return ;
//     }
//     // include
//     ans.push_back(s[i]);
//     // recursive func.
//     printPerm(s, i+1, ans);
//     // exclude
//     ans.pop_back();
//     // recursive func.
//     printPerm(s, i+1, ans);
// }

// int main(){
//     string s = "abc";

//     string ans;
//     printPerm(s, 0, ans);

//     return 0;
// }