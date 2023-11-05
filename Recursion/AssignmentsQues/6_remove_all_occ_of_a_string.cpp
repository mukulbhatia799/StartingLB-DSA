#include<iostream>
using namespace std;

// iterative solution
// string removeOccurrences(string s, string part) {
//         int pos = s.find(part);

//         while(pos != string::npos)
//         {
//             s.erase(pos, part.length());
//             pos = s.find(part);
//         }
//         return s;
// }

// recursive solution
string removeOccurrences(string& s, string part) {
    int pos = s.find(part);
    if(pos != string::npos)
    {
        string left_str = s.substr(0, pos);
        string right_str = s.substr(pos+part.length(), s.length());
        s = left_str + right_str;
        removeOccurrences(s, part);
    }
    return s;
}

int main(){
    string s = "axxxxyyyyb", part = "xy";

    cout << "new string: " << removeOccurrences(s, part);

    return 0;
}