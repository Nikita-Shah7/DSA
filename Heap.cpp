// Heap is tree based Data Structure
// It is a complete Binary Tree i.e. the nodes are arranged as left as possible
// There are 2 types of Heaps:
// a. Max Heap : parent node >= child node
// b. Min Heap : parent node <= child node
// Elements of Heap are stored in an array
// Indexing begins from 1
// Index of Parent Node of ith node = i/2 floor value ;
// Index of left child of ith node = 2*i
// Index of right child of ith node = 2*i + 1
// Index of last non-leaf node = size/2

#include<bits/stdc++.h>
using namespace std;

class maxHeap
{
    int *arr;
    int maxSize, size;

    bool isEmpty();
    bool isFull();
    int parent(int);
    int leftChild(int);
    int rightChild(int);
    bool search(int,int);

public:
    maxHeap(int);
    void Create();
    void Insert();
    void Display();
    void Delete();
    void Search();
    void Heapify();
};

maxHeap ::maxHeap(int n)
{
    maxSize = n;
    size = 0; // index of last element
    arr = new int[maxSize];
}

bool maxHeap ::isEmpty()
{
    if (size == 0)
        return 1;
    return 0;
}

bool maxHeap ::isFull()
{
    if (size == maxSize)
        return 1;
    return 0;
}

int maxHeap ::parent(int i)
{
    return i / 2;
}

int maxHeap ::leftChild(int i)
{
    return 2 * i;
}

int maxHeap ::rightChild(int i)
{
    return 2 * i + 1;
}

void maxHeap ::Create()
{
    if (!isEmpty())
    {
        cout << "Heap is already created!\n";
        return;
    }

    cout << "Note:: Enter -1 to finish entering the data.\n";
    int val;
    cout << "Enter the data.\n";
    cin >> val;
    while (val != -1)
    {
        if (isFull())
        {
            cout << "Heap is Full!\n";
            return;
        }
        size++;
        arr[size] = val;
    }
    Heapify();
    return;
}

void maxHeap ::Insert()
{
    // Inserting takes place from bottom
    // We insert the new node at the first empty place(since heap is complete BT)
    // and then replace the node with it's parent (to satisfy Max Heap property)
    int val;
    cout << "Enter the data to be inserted : ";
    cin >> val;
    if (isFull())
    {
        cout << "Heap is Full!\n";
        return;
    }
    size++;
    arr[size] = val;

    for (int i = size; i > 0; i = i / 2)
    {
        if (arr[parent(i)] < arr[i])
            swap(arr[parent(i)], arr[i]);
        else
            break;
    }
}

void maxHeap ::Heapify()
{
    // Heapifying means that every node of Heap must satisfy the Heap property
    // bottom-up approach
    int i = (size) / 2;
    while (i >= 1)
    {
        if (arr[leftChild(i)] > arr[rightChild(i)] && arr[leftChild(i)] > arr[i])
            swap(arr[i], arr[leftChild(i)]);
        else if (rightChild(i) <= size && arr[rightChild(i)] > arr[i] && arr[leftChild(i)] < arr[rightChild(i)])
            swap(arr[i], arr[rightChild(i)]);
        i--;
    }

    // top-down approach
    i = 1;
    while (i <= parent(size))
    {
        if (arr[left] > arr[rightChild(i)] && arr[leftChild(i)] > arr[i])
            swap(arr[i], arr[leftChild(i)]);
        else if (rightChild(i) <= size && arr[rightChild(i)] > arr[i] && arr[leftChild(i)] < arr[rightChild(i)])
            swap(arr[i], arr[rightChild(i)]);
        i++;
    }
}

void maxHeap ::Delete()
{
    // we can delete the root node only.
    cout<<"Element to be deleted : "<<arr[1]<<endl;
    swap(arr[1], arr[size]);
    size--;

    int i=1;
    while(i <= parent(size))
    {
        int maxi = max(arr[leftChild(i)], arr[rightChild(i)]);
        if(maxi > arr[i])
        {
            if(maxi == arr[leftChild(i)])
            {
                swap(arr[leftChild(i)], arr[i]);
                i = leftChild(i);
            }
            else
            {
                swap(arr[rightChild(i)], arr[i]);
                i = rightChild(i);
            }
        }
        else return;
    }
    return;
}

int maxHeap ::Display()
{
    if (isEmpty())
    {
        cout << "Heap is empty!\n";
        return;
    }

    cout<<endl;
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

bool maxHeap :: search(int val, int i)
{
    if(i > size)    return 0;
    if(val == arr[i])        
        return 1;    
    else
        return search(val,leftChild(i)) || search(val,rightChild(i)) ;
}

void maxHeap :: Search()
{
    if (isEmpty())
    {
        cout << "Heap is empty!\n";
        return;
    }

    int val;
    cout<<"Enter the element to Search for : ";
    cin>>val;
    if(search(val,1))   cout<<"Element Found\n";
    else cout<<"Element not Found\n";
    return;
}


int main(void)
{
    maxHeap heap(21);
    int opt;
    cout << "***** MAX HEAP DATA STRUCTURE MENU DRIVEN *****" << endl;
    cout << "0: Display Max Heap" << endl;
    cout << "1: Create a Max Heap." << endl;
    cout << "2: Insert an element." << endl;
    cout << "3: Delete an element." << endl;
    cout << "4: Search for an element." << endl;
    cout << "5: Sort." << endl;
    cout << "-1: Quit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            heap.Display();
            break;
        case 1:
            heap.Create();
            break;
        case 2:
            heap.Insert();
            break;
        case 3:
            heap.Delete();
            break;
        case 4:
            heap.Search();
            break;
        case 5:
            heap.Sort();
            break;
        case -1:
            cout << "***** THANK YOU *****" << endl;
            break;
        default:
            cout << "Enter Valid Option." << endl;
            break;
        }
    } while (opt != -1);
    return 0;
}

// Creation : O(n)
// insertion : O(log n) = O(h)
// Search : O(n)
// deletion : O(log n) = O(h)
// Heapify : O(n)