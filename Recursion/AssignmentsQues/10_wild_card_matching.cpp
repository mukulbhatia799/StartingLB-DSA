// wildcard Matching
#include <iostream>
using namespace std;

bool findMatching(string &s, string &p, int si, int pi)
{
    // base case.
    if (si == s.length() && pi == p.length())
    {
        return true;
    }
    if (si == s.length() || pi < p.length())
    { // wrong cond. need fix
        return false;
    }
    // one case
    if (s[si] == p[pi] || p[pi] == '?')
    {
        return findMatching(s, p, si + 1, pi + 1);
    }
    else if (p[pi] == '*')
    {
        // '*' == 0 character
        int result1 = findMatching(s, p, si, pi + 1);
        // '*' == one character
        int result2 = findMatching(s, p, si + 1, pi);
        return (result1 || result2);
    }
    return false;
}

int main()
{
    string s = "abcdefg";
    string p = "****ab*?fg*";

    bool ans = findMatching(s, p, 0, 0);

    if (ans == true)
        cout << "string matches" << endl;
    else
        cout << "string doesn't match" << endl;

    return 0;
}