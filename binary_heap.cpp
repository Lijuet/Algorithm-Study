#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void swap(int *x, int *y);

class MinHeap{
    int *harr;
    int capacity;
    int heap_size;

    public:
    MinHeap(int capcaity);

    void buildMinHeap(int*, int);
    void MinHeapify(int);
    
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i ) { return 2*i+2; }

    int getMin();
    int extractMin();
    void decreaseKey(int i, int new_val);
    void insertKey(int k);
    void deleteKey(int i);
};

MinHeap::MinHeap(int cap){
    harr = new int[cap];
    capacity = cap;
    heap_size = 0;
}

void MinHeap::buildMinHeap(int *arr, int size){
    heap_size = size;
    harr = arr;

    for(int i = heap_size/2; i >= 0; i--) MinHeapify(i);
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[l] < harr[smallest]) smallest = l;
    if(r < heap_size && harr[r] < harr[smallest]) smallest = r;

    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::getMin(){
    if(heap_size < 1){
        cout << "\nNo element in the heap\n";
        return INT_MAX;
    }

    int root = harr[0];

    return root;
}

int MinHeap::extractMin(){
    int root = getMin();
    deleteKey(0);

    return root;
}

void MinHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}

void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout << "\nOverflow: Could not insertkey\n";
        return;
    }

    harr[heap_size++] = k;

    int i = heap_size - 1;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
    if(heap_size < 1){
        cout << "\nNo element in the heap\n";
        return;
    }

    harr[i] = harr[--heap_size];
    MinHeapify(0);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


//*******************HEAP SORT***********************
void heapSort(int* arr, int size){
    MinHeap h(size);
    h.buildMinHeap(arr, size);

    for(int i = 0; i < size; i++) arr[size - 1 - i] = h.extractMin();
}


//*******************PROBLEM SOLVING*******************

void first_k_largest_elements(int arr[], int size, int k){
    // Build MH with first k elements
    MinHeap h(k);
    h.buildMinHeap(arr, k);

    for(int i = k; i < size; i++) {
        if(arr[i] > arr[0]) {
            arr[0] = arr[i];
            h.MinHeapify(0);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}


int main()
{
    cout << "BINARY HEAP TEST" << endl;
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin() << "\n";

    cout << "HEAP SORTING TEST" << endl;
    int arr[] = {1, 5, 3, 2, 4};
    heapSort(arr, 5);
    
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "K LARGEST TEST" << endl;
    int arr2[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int size = sizeof(arr2) / sizeof(arr2[0]);
 
    // Size of Min Heap
    int k = 3;
 
    first_k_largest_elements(arr2,size,k);

    return 0;
}