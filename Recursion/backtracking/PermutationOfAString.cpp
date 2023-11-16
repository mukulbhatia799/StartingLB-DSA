// Permutation of a string
// backtracking :- means to add some additional code to keep the things as it is. Because sometimes we call string by reference and even the arrays are called by reference by default. So, backtracking is a important concept to place all the things back to it's place.
#include<iostream>
using namespace std;

void PermutationOfString(string& s, int ptr)
{
    // base case
    if(ptr == s.length()) {
        cout << "->" << s << endl;
        return ;
    }

    for(int j = ptr; j < s.length(); j++)
    {
        swap(s[j], s[ptr]);
        PermutationOfString(s, ptr+1);      // recursive func.

        // backtracting :- placing all the letters at it's original place if we are calling string by reference because changing the string by reference can change the previous calls strings.
        swap(s[j], s[ptr]);     // keeping the string as it is.
    }    
}


int main(){
    string s = "abcde";       // result: abc, acb, bac, bca, cab, cba

    PermutationOfString(s, 0);
    
    return 0;
}