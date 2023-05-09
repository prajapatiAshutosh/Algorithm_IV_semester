#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

void max_heapify(int ar[],int size,int root, int &comparisons)
{
    int largest=root;
    int l = (root*2)+1;
    int r = (root*2)+2;
    if(l<size && ar[l]>ar[largest])
    {
        largest=l;
    }
    if(r<size && ar[r]>ar[largest])
    {
        largest=r;
    }
    if(largest!=root)
    {
        swap(ar[root],ar[largest]);
        comparisons++; // incrementing the counter variable
        max_heapify(ar,size,largest, comparisons);
    }
    return;
}

void build_max_heap(int ar[],int size, int &comparisons)
{
    for(int i=(size/2)-1;i>=0;i--)
    {
        max_heapify(ar,size,i, comparisons);
    }
}

void heap_sort(int ar[],int size)
{
    int comparisons = 0; // initializing the counter variable
    build_max_heap(ar,size, comparisons);
    for(int i=size-1;i>0;i--)
    {
        swap(ar[0],ar[i]);
        comparisons++; // incrementing the counter variable
        max_heapify(ar,i,0, comparisons);
    }
    cout << "Number of comparisons: " << comparisons << endl; // printing the number of comparisons
}

void display(int ar[],int size)
{
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    int *ar;
    cout<<"Enter the size of the array: ";
    cin>>n;
    ar = new int[n];
    cout<<"Enter the values of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"The input array is: ";
    display(ar,n);
    heap_sort(ar,n);
    cout<<"The sorted array is: ";
    display(ar,n);
}
