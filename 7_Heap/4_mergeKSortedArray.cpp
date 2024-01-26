// merge k sorted array.

#include <iostream>
#include <queue>
using namespace std;

// Info class is required because we have stored first index value of arr[][] in min heap. While storing the min value in result then we have to update the pointer to next column index of that row.
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int data, int rowIndex, int colIndex)
    {
        this->data = data;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};

// Here we have created our own compare function, if row1.data > row2.data then the result will be in descending order else if row1.data < row2.data, result will be in ascending order.
// Also creating our own compare function or class is required because the type is of info and we can't write priority_queue< , , greater<Info> > pq as here Info type is not known by the Inbuild priority_queue.
class compare
{
public:
    bool operator()(Info row1, Info row2)
    {
        return row1.data > row2.data;
    }
};

vector<int> mergeKSortedArray(int arr[][4], int row, int col)
{
    vector<int> result;

    priority_queue<Info, vector<Info>, compare> pq;

    // first store the 0th index value of all the K arrays.
    for (int i = 0; i < row; i++)
    {
        Info temp(arr[i][0], i, 0);
        pq.push(temp);
    }

    // After storing the 0th index value, we will have the min value at the top of the min heap. So, we will just push_back() that value in result and update that array pointer to it's next index (means update the column index to next index).
    while (!pq.empty())
    {
        Info minValue = pq.top();
        pq.pop();
        result.push_back(minValue.data);

        int nextRow = minValue.rowIndex;
        int nextCol = minValue.colIndex + 1;
        int nextValue = arr[nextRow][nextCol];
        // this if condition is required because there might be the case that index is out of bound.
        if (nextCol < col)
        {
            Info temp(nextValue, nextRow, nextCol);
            pq.push(temp);
        }
    }

    return result;
}

void printMergedArray(vector<int> &vec, int row, int col)
{
    cout << "Displaying merged array: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14}};

    int row = 3, col = 4;
    vector<int> answer = mergeKSortedArray(arr, row, col);

    printMergedArray(answer, row, col);

    return 0;
}