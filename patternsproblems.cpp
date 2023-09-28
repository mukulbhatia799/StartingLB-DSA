#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // n should be even.
    int stars = 1, spaces = n-1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= stars; j++)
            cout << "* ";
        for(int j = 1; j <= spaces; j++)
            cout << "  ";
        for(int j = 1; j <= stars; j++)
            cout << "* ";
        cout << endl;
        if(i < (n+1)/2)
        {
            stars++;
            spaces-=2;
        }
        else if(i == (n+1)/2) continue;
        else 
        {
            stars--;
            spaces+=2;
        }
    }

    return 0;
}
