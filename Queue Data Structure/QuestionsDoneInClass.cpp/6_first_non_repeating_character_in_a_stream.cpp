/*
i/p -> abacd
o/p -> aabbb

i/p -> abacbcd
o/p -> abbbc#d

so, basically we have to keep the track of each character from left to right so that we can find which is the first non repeating char. So, if we use map to store the frequency of all characters in a string and if it's frequency is 1 then push it else check if map[queue.front()] frequency is one or not. If not, queue.pop() and again check if queue is empty or not, if not empty print the next queue.front() element else if empty, print '#'.

stream increases by one index each time and we have to tell the first* non-repeating means which is not occuring more than once in that stream. If non of them is a non-repeating then put '#'.
*/

#include<iostream>
#include<map>
#include<queue>
using namespace std;

void usingMap(string s)
{
    map<char, int> mp;   // <char, index>   // instead of map, we can use hash array too.
    queue<char> q;          // stores the char frequency if not present in previous streams.
    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        auto it = mp.find(s[i]);
        if(it->second == 1) q.push(s[i]);
        if(mp[q.front()] == 1) cout << q.front() << " ";
        else {
            while(!q.empty() && mp[q.front()] != 1)
                q.pop();
            if(!q.empty()) cout << q.front() << " ";
            else cout << "# ";
        }
    }
}

int main(){
    string s = "facfdcad";
    // string s = "abacbcd";

    usingMap(s);        // time complexity :- O(n^2) as we are running a loop and within it we are using find() which takes another O(n) time in worst case.

    return 0;
}