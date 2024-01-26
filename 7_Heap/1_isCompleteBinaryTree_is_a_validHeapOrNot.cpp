// all methods are same for this code. The only difference is that every function returns something different like first method return the maxval with bool value whether the left and right tree is valid heap or not. 
// same as, second method use pair stl where creation of class is not required. 
// In third method, we only check whether the left and right tree is valid heap or not and check in every recursive function that whether it arr[i] > arr[leftchildIndex] && arr[i] > arr[rightchildIndex].

#include<iostream>
#include<climits>
using namespace std;

// method-1:
class Info {
    int maxVal;
    bool isHeap;
public:
    Info isValidCompleteBinaryTreeOrNot(int *arr, int size, int i)
    {
        if(i >= size) {     // suppose the last child node parent have only one child. so, i >= size and return INT_MIN and true because if there is not any node then also it is a valid max heap.
            Info temp;
            temp.maxVal = INT_MIN;
            temp.isHeap = true;
            return temp;
        }
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;

        if(leftChild >= size && rightChild >= size) {
            Info temp;
            temp.maxVal = arr[i];
            temp.isHeap = true;
            return temp;
        }

        Info leftans = isValidCompleteBinaryTreeOrNot(arr, size, leftChild);
        Info rightans = isValidCompleteBinaryTreeOrNot(arr, size, rightChild);

        if(leftans.maxVal < arr[i] && leftans.isHeap && rightans.maxVal < arr[i] && rightans.isHeap) {
            Info temp;
            temp.maxVal = max(arr[i], max(arr[leftChild], arr[rightChild]));
            temp.isHeap = true;
            return temp;
        }
        else {
            Info temp;
            temp.maxVal = INT_MIN;
            temp.isHeap = false;
            return temp;
        }        
    }
    bool checkValidOrNot(Info &pr) {
        if(pr.isHeap == false) return false;
        return true;
    }
};


// method-2:
// we can also create a complete binary tree and send the root node to function. Also we can do this ques by creating a pair instead of creating class.
// pair<int, bool> isValidCompleteBinaryTreeOrNot(int *arr, int size, int i) {}



// method-3: return only bool valid whether left and right is valid heap or not.
bool checkValidHeapOrNot(int *arr, int size, int i)
{
    if(i >= size) {
        return true;
    }
    int leftchild = 2*i+1;
    int rightchild = 2*i+2;

    if(leftchild >= size && rightchild >= size) {
        return true;
    }

    bool leftans = checkValidHeapOrNot(arr, size, leftchild);
    bool rightans = checkValidHeapOrNot(arr, size, rightchild);

    if(leftans && rightans) {
        if(leftchild < size && arr[i] > arr[leftchild]) {
            if(rightchild < size && arr[i] > arr[rightchild])
                return true;
            if(rightchild >= size) return true;
            else return false;
        } else return false;
        if(rightchild < size && arr[i] > arr[rightchild]) {
            return true;
        } else return false;
    }
    else  return false;
}


int main(){
    int arr[] = {10, 5, 8, 1, 3, 6, 7}; // find this C.B.T is a valid max heap or not. stored in level order traversal.
    // int arr[] = {10, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    Info obj;
    cout << "done" << endl;
    Info pr = obj.isValidCompleteBinaryTreeOrNot(arr, size, 0); // <maxval, T/F> true if C.B.T is a valid heap else false.
    bool ans = obj.checkValidOrNot(pr);
    if(ans) {
        cout << "it's a valid heap." << endl;
    }
    else {
        cout << "not a valid heap." << endl;
    }


    bool ans2 = checkValidHeapOrNot(arr, size, 0);
    if(ans) {
        cout << "it's a valid heap." << endl;
    }
    else cout << "not a valid heap." << endl;

    return 0;
}