#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // initialize n with even number only.
    // if odd is taken then n-1 will be printed.
    int stars = 1, space = n/2;
    for(int i = 1; i <= n; i++)
    {
        // spaces
        for(int j = 1; j < space; j++)
        {
            cout << "  ";
        }
        // stars
        for(int j = 1; j <= stars; j++)
        {
            if(j == 1 || j == stars)
                cout << "* ";
            else 
                cout << "  ";
        }
        cout << endl;
        if(i >= n/2)
        {
            if(i == n/2) continue;
            else 
            {
                space++;
                stars -= 2;
            }
        }
        else
        {
            space--;
            stars += 2;
        }
    }

    return 0;
}
