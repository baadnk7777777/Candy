#include <iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);
  
class MinHeap
{
    int *harr; 
    int capacity; 
    int heap_size; 
public:
    // Constructor
    MinHeap(int capacity);
  
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    int left(int i) { return (2*i + 1); }
  
    int right(int i) { return (2*i + 2); }
  
    int extractMin();
  
    void decreaseKey(int i, int new_val);
  
    int getMin() { return harr[0]; }
    
    void deleteKey(int i);
  
    void insertKey(int k);
    
    void Display();
};
  
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
  
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
  
  
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
  
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
  
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::Display()
{ 
  	 for(int i=0;i<heap_size;i++)
    {
    	cout << harr[i] << " ";
	}
    cout <<endl;
}


int main()
{
	MinHeap h(100002);
	while(true)
	{
		string oparation;
		cin >> oparation;
		
		if(oparation == "A")
		{
			int data;
			cin >> data;
			h.insertKey(data);
		}else if(oparation == "D")
		{
			h.Display();
		}
		else if(oparation == "Q")
		{	
			if(h.getMin()>=0)
			{
				cout << h.getMin() << endl;
			}
			else cout << "empty" <<endl; 
			
			h.deleteKey(0);
		}
		else if(oparation == "X")
		{
			return 0;
		}
		else {
			cout << "Unkhnow !!" <<endl;
		}
	}
}
