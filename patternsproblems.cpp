#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i; j++)
            cout << "  ";
        int j = 1, num = 1;
        while(j <= 2*i-1)
        {
            cout << num << " ";
            if(j < i) num++;
            else num--;
            j++;
        }
        cout << endl;
    }

    return 0;
}