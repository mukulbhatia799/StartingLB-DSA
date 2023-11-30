#include<iostream>
using namespace std;

// checking (right to left) means when we got the element then that will be the last occ. only.
int lastOccOfString(int* arr, int size, int ele)
{
    if(size == -1)
    {
        return -1;
    }
    if(arr[size] == ele) return size;
    return lastOccOfString(arr, size-1, ele);
}


// checking (left to right) means we have to take one variable where we can store the occurences of asked element.
void lastOccOfString_leftToRight(int* arr, int size, int i, int ele, int &ans)
{
    // base case 
    if(size == arr[i]) return ;
    else if(arr[i] == ele) ans = i;
    // recursive function
    lastOccOfString_leftToRight(arr, size, i+1, ele, ans);
}

int main(){
    int arr[]={10, 20, 30, 40, 40, 40, 50, 40, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    int n;
    cout << "Enter element to find it's last occ. " << endl;
    cin >> n;
    int ans = lastOccOfString(arr, size-1, n);
    if(ans == -1) cout << "Element not found. right to left" << endl;
    else 
    {
        cout << "using left to right recursiion. Element last occ. is " << ans << endl;
    }


    int storeResult = -1;
    lastOccOfString_leftToRight(arr, size, 0, n, storeResult);
    if(storeResult == -1) 
        cout << "Using left to right recursion. Element not found." << endl;
    else 
        cout << "Using left to right recursion. Element last occ. found at " << storeResult << endl;


    return 0;
}



// ================ Revision-1 ================ 

// #include<iostream>
// using namespace std;

// int ans = -1;
// int findLastOcc_rightToLeft(string& s, char ch, int ptr)
// {
//     if(ptr == -1) return -1;
//     if(s[ptr] == ch) return ptr;
//     findLastOcc_rightToLeft(s, ch, ptr-1);
// }

// // by saving ans in a variable.
// void findLastOcc_LeftToRight(string& s, char ch, int ptr, int& ans)
// {
//     if(ptr == s.length()) return ;
//     if(s[ptr] == ch) ans = ptr;
//     findLastOcc_LeftToRight(s, ch, ptr+1, ans);

// }

// int main(){
//     // last occ. of a char
//     string s = "abcddef";

//     char ch;
//     cout << "input char to find it's last occ. ";
//     cin >> ch;

//     // right to left
//     // int ans = findLastOcc_rightToLeft(s, ch, s.length()-1);
//     // if(ans == -1) cout << "value not found" << endl;
//     // else cout << "Last occ of " << ch << " is " << ans << endl;

//     // left to right
//     int ans = -1;
//     findLastOcc_LeftToRight(s, ch, 0, ans);
//     if(ans == -1) cout << "value not found" << endl;
//     else cout << "Last occ of " << ch << " is at index " << ans << endl;
    
//     return 0;
// }