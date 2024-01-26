// #include<iostream>
// #include<queue>
// using namespace std;

// class Heap {
//     int* arr;
//     int size;
//     int capacity;
// public:
//     Heap(int capacity) {
//         this->arr = new int[capacity];
//         this->capacity = capacity;
//         this->size = 0;
//     }
//     void insertMaxHeap(int element) {  // converting in max heap
//         if(size >= capacity) {
//             cout << "Heap overflow" << endl;
//             return ;
//         }
//         size++;
//         arr[size] = element;
//         int parentIndex = size;
//         while(arr[parentIndex] > arr[parentIndex/2]) 
//         {
//             swap(arr[parentIndex], arr[parentIndex/2]);
//             parentIndex = parentIndex / 2;
//         }
//     }
//     void DeleteFromMaxHeap() {
//         int deletingValue = arr[1];
//         arr[1] = arr[size];
//         size--;
//         // now heapify
//         int currIndex = 1;
//         while(currIndex <= size) {
//             int leftChildIndex = 2*currIndex;
//             int rightChildIndex = 2*currIndex + 1;
//             int largestIndex = currIndex;
//             if(leftChildIndex <= size && arr[largestIndex] < arr[leftChildIndex]) {
//                 largestIndex = leftChildIndex;
//             }
//             if(rightChildIndex <= size && arr[largestIndex] < arr[rightChildIndex]) {
//                 largestIndex = rightChildIndex;
//             }
//             if(largestIndex == currIndex) break;
//             swap(arr[currIndex],  arr[largestIndex]);
//             currIndex = largestIndex;
//         }
//     }
//     void heapifyAnIndex(int arr[], int size, int index) { // (index == heapify Index)
//         int leftChildIndex = 2*index;
//         int rightChildIndex = 2*index + 1;
//         int largestIndex = index;   // Let curr index is largest index.

//         // no need to give base cond. bcz if leftchildindex or rightchildindex is greater than size then autom. it will be out of the recursive func.

//         if(leftChildIndex <= size && arr[leftChildIndex] > arr[largestIndex]) {
//             largestIndex = leftChildIndex;
//         }
//         if(rightChildIndex <= size && arr[rightChildIndex] > arr[largestIndex]) {
//             largestIndex = rightChildIndex;
//         }

//         if(largestIndex != index) {
//             swap(arr[largestIndex], arr[index]);
//             index = largestIndex;
//             heapifyAnIndex(arr, size, index);   // recursive function
//         }

//     }
//     void buildHeap(int arr[], int size) {
//         int nonleafindex = size/2;
//         for(int i = nonleafindex; i > 0; i--) {
//             heapifyAnIndex(arr, size, i);
//         }
//     }
//     void heapSort(int arr[], int size) {    // O(nlogn)
//         while(size > 1) {   // O(n)
//             heapifyAnIndex(arr, size, 1);   // as we are swapping the 1st index element with the last unsorted index and heapify the first index. // time complexity: O(logn)
//             swap(arr[1], arr[size]);
//             size--;
//         }
//     }
//     int getKthSmallestElement(int arr[], int size, int k)
//     {
//         priority_queue<int> pq;     // creates max heap
//         for(int i = 0; i < k; i++) { // 
//             pq.push(arr[i]);
//         }
//         for(int i = k; i < size; i++) {
//             if(arr[i] < pq.top()) {
//                 pq.pop();
//                 pq.push(arr[i]);
//             }
//         }
//         return pq.top();
//     }
//     int getKthGreatestElement(int arr[], int size, int k) {
//         priority_queue<int, vector<int>, greater<int> > pq; // creates min heap
//         for(int i = 0; i < k; i++) {
//             pq.push(arr[i]);
//         }
//         for(int i = k; i < size; i++) {
//             if(arr[i] > pq.top()) {
//                 pq.pop();
//                 pq.push(arr[i]);
//             }
//         }
//         return pq.top();
//     }
//     void printHeap() {
//         cout << "Heap: ";
//         for(int i = 1; i <= size; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     void printHeapArray(int *arr, int size) {
//         for(int i = 1; i <= size; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main(){
//     Heap hp(25);    // max capacity of heap is 25.

//     hp.insertMaxHeap(10);
//     hp.insertMaxHeap(20);
//     hp.insertMaxHeap(5);
//     hp.insertMaxHeap(18);
//     hp.insertMaxHeap(1);

//     hp.printHeap();

//     hp.DeleteFromMaxHeap();
//     hp.printHeap();
//     hp.DeleteFromMaxHeap();
//     hp.printHeap();

//     int arr[] = {-1, 8, 5, 1, 2, 9, 10};   // heapify the 4th index because it's child is greater.
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int heapifyIndex = 3;
//     cout << "Before heapify: ";
//     hp.printHeapArray(arr, size-1);
    
//     hp.heapifyAnIndex(arr, size-1, heapifyIndex);//(arr, lastIndexOfHeap, heapifyIndex).
//     cout << "After heapify: ";
//     hp.printHeapArray(arr, size-1);

//     // build heap using this array.
//     int arr2[] = {-1, 1, 9, 8, 5, 2, 10};
//     size = sizeof(arr2) / sizeof(arr2[0]);
//     cout << "Before heap is build: ";
//     hp.printHeapArray(arr2, size-1);
    
//     hp.buildHeap(arr2, size-1);
//     cout << "After heap is build: ";
//     hp.printHeapArray(arr2, size-1);


//     // Heap Sort: time complexity:- O(nlogn).
//     int arr3[] = {-1, 5, 3, 7, 6, 1, 9, 10, 4};
//     size = sizeof(arr3) / sizeof(int);
//     cout << "Before Heap Sort: ";
//     hp.printHeapArray(arr3, size-1);

//     hp.heapSort(arr3, size-1);   // sort heap in ascending or descending order.
//     cout << "After Heap Sort: ";
//     hp.printHeapArray(arr3, size-1);


//     // find kth smallest element.
//     int arr4[] = {5, 11, 6, 3, 17, 2, 8, 1, 0}; // 0, 1, 2, 3, 5, 6, 8, 11, 17.
//     cout << "kth smallest element: " << hp.getKthSmallestElement(arr4, size, 6) << endl;    // in O(n) time complexity and  O(k) space.
//     cout << "kth greatest element: " << hp.getKthGreatestElement(arr4, size, 5) << endl; // in O(n) time complexity and  O(k) space.

//     return 0;
// }





// revision:

#include<iostream>
#include<queue>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node(int data) {
        this->data = data;
    }
    Node* create() {
        int value;
        cout << "Enter value(-1 for NULL value): ";
        cin >> value;

        if(value == -1) {
            return NULL;
        }

        Node* newnode = new Node(value);
        newnode->left = create();
        newnode->right = create();
        return  newnode;
    }
    void levelOrderTraversal(Node* root) {
        cout << "Print using level order traversal: " << endl;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if(temp == NULL) {
                cout << endl;
                if(!q.empty()) q.push(NULL);
            }
            else {
                cout << temp->data << " ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        cout << endl;
    }
};

int main(){
    Node* heap;
    Node* root = heap->create();

    heap->levelOrderTraversal(root);

    return 0;
}