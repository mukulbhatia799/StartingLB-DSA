#include<iostream>
using namespace std;

void subseq(string s, string ans, int i)
{
    if(i >= s.length())
    {
        cout << "->" << ans << endl;
        return ;
    }
    // Here first we are including then excluding. We can even do excluding first.*/
    /*
        char ch = s[i];     // include
        ans.push_back(ch);

        subseq(s, ans, i+1);    // recursive function

        ans.pop_back();         // exclude     // because we have included the character before recursive function.
        subseq(s, ans, i+1);
    */

    // excluding first

    char ch = s[i];     // exclude
    
    subseq(s, ans, i+1);    // recursive function
    
    ans.push_back(ch);  // include
    subseq(s, ans, i+1);
}

int main(){
    string s = "abc";

    string subStrings;
    subseq(s, subStrings, 0);

    return 0;
}