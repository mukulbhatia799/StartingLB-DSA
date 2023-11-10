#include<iostream>
#include<cmath>
using namespace std;

//  using recursive function
void findsubseqUsingRE(string& s, int i, string subseq)
{
    if(i == s.length()) 
    {
        cout << "-> '" << subseq << "'" << endl;
        return ;
    }
    // include
    subseq.push_back(s[i]);
    findsubseqUsingRE(s, i+1, subseq);
    // exclude
    subseq.pop_back();
    findsubseqUsingRE(s, i+1, subseq);
}

// using bit masking
void findsubseqUsingBit(string& s)
{
    int n = s.length();
    int size = pow(2, n);

    for(int i = 0; i < size; i++)
    {
        int num = i;
        int track = 0;
        cout << "-> ";
        if(num == 0) {
            cout << endl;
            continue;
        }
        while(num)
        {
            int bit = (num & 1);
            if(bit == 1) cout << s[track];
            num = num >> 1;
            track++;
        }
        cout << endl;
    }
}

int main(){
    string s = "abc";
    string subseq;
    // findsubseqUsingRE(s, 0, subseq);

    findsubseqUsingBit(s);

    return 0;
}