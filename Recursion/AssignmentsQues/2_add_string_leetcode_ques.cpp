#include<iostream>
#include<vector>

using namespace std;


void solve(string& num1, string& num2, int ptr1, int ptr2, int carry, string& ans)
{   // always try to send the arguments in function using call by reference because the compiler will not make the copy in each iteration. Check the memory difference without call by refernence for num1 and num2 string.
        // base cond.
        if(ptr1 < 0 && ptr2 < 0) {  
            cout << "carry: " << carry << endl;
            if(carry > 0) ans.push_back(carry + '0');
            return ;
        }
        char ch1, ch2;
        if(ptr1 < 0) ch1 = '0';
        else if(ptr1 >= 0) ch1 = num1[ptr1];
        if(ptr2 < 0) ch2 = '0';
        else if(ptr2 >= 0) ch2 = num2[ptr2];
        int sum = int(ch1 - '0') + int(ch2 - '0') + carry;
        int summod = sum % 10;
        carry = sum / 10;
        // cout << "sum: " << sum << " carry: " << carry << endl;
        ans.push_back(char(summod) + '0');
        
        // recursive function
        solve(num1, num2, ptr1-1, ptr2-1, carry, ans);
}
string addStrings(string& num1, string& num2) {     // we can use call by reference to save the memory.         // Always try to send the arguments using call by reference specially during recursion and iterative approach.
        string ans;
        solve(num1, num2, num1.length()-1, num2.length()-1, 0, ans);
        // reverse the string
        // cout << "ans length: " << ans.length() << endl;
        for(int i = 0; i < ans.length()/2; i++)
        {
            swap(ans[i], ans[ans.length()-i-1]);
        }
        return ans;
}

int main(){
    string s1 = "123";
    string s2 = "967";

    addStrings(s1, s2);

    return 0;
}



// ================== revision 1 ============
// add strings and return sum using RE
#include<iostream>
using namespace std;

void addStringsRE(string& s1, string& s2, int p1, int p2, int carry, string& ans)
{
    // base case.
    if(p1 < 0 && p2 < 0)
    {
        ans += char(carry + '0');
        return ;
    }
    // one cond.
    int sum = 0;
    if(p1 >= 0) sum += s1[p1] - '0';
    if(p2 >= 0) sum += s2[p2] - '0';
    sum += carry;
    int mod = sum % 10;
    ans += char(mod + '0');
    carry = sum / 10;
    // recursive func.
    addStringsRE(s1, s2, p1-1, p2-1, carry, ans);
}

int main(){
    string s1 = "999";
    string s2 = "99";

    int p1 = s1.length()-1, p2 = s2.length()-1;
    string ans;
    int carry = 0;
    addStringsRE(s1, s2, p1, p2, carry, ans);

    cout << "sum of strings: ";
    for(int i = ans.length()-1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}