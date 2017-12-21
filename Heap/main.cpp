#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

/****
	Complete Binary Heap implementation
	
	All operations work in time O(logn)
	We used an array of priorities. Parent-child connections aren't stored, but computed on the fly
		
****/
class Heap
{
	private:
		int *H; // pointer to array of elements in Heap
		int maxSize, // capacity of Heap
			size; // number of current elements in Heap
		int parent(int i);
		int leftChild(int i);
		int rightChild(int i);
		void siftUp(int i);
		void siftDown(int i);
		
	public:
		Heap();
//		~Heap();
		void insert(int value);
		int extractMax();
		void getMax();
		void print();
		void remove(int i);
		void changePriority(int i, int value);
		void getSize();		
	
	// Constructor: Builds a heap
	Heap(int capacity)
	{
	    maxSize = capacity;
	    size = 0;
	    H = new int[maxSize];
	}
};

void Heap::print()
{
	cout << "\n===HEAP===\n";
	
	for(int i = 0; i < size; i++)
	{
		cout << H[i] << " ";
	}
	
	cout << "\n======\n";
}

void Heap::insert(int value)
{
	if(size == maxSize)
	{
		cout << "Couldn't insert element. Heap overloaded. \n";
		return;
	}
	
	// insert element at the end of Heap
	int i = size;
	size++;
	H[i] = value;
	
	siftUp(i);
}

// TODO: check it one more time
int Heap::parent(int i)
{
	return (i - 1) / 2;
}

int Heap::leftChild(int i)
{
	return 2 * i + 1;
}

int Heap::rightChild(int i)
{
	return 2 * i + 2;
}

int parent(int i)
{
	return (i - 1) / 2;
}

void Heap::siftUp(int i)
{
	// if not root element 
	// if greater than parent elment
	while(i > 0 && H[i] > H[parent(i)])
	{
		int temp = H[i];
		H[i] = H[parent(i)];
		H[parent(i)] = temp;
		
		i = parent(i); 
	}
	return;
}

void Heap::siftDown(int i)
{
	// find max child
	int maxIndex = i;
	
	int left = leftChild(i);
	if(left <= size && H[left] > H[maxIndex])
	{
		maxIndex = left;
	}
	
	int right = rightChild(i);
	if(right <= size && H[right] > H[maxIndex])
	{
		maxIndex = right;
	}
	
	// swap with max child
	if(i != maxIndex)
	{
		int temp = H[i];
		H[i] = H[maxIndex];
		H[maxIndex] = temp;
		
		siftDown(maxIndex);
	}
	
	return;
}

int Heap::extractMax()
{
	int max = H[0];
	H[0] = H[size - 1]; // change with rightest element in the last level
	size--; // decrease size
	
	siftDown(0);
	
	return max;	
}

void Heap::getMax()
{
	if(size == 0)
	{
		cout << "Heap is empty!";
		return;
	}
	cout << "MAX element: " << H[0] << "\n";
}

void Heap::remove(int i)
{	
	H[i] = INT_MAX; // change ot +infinity
	
	siftUp(i); // sift up infinity 
	
	extractMax(); // extract max - which is our infinity
}

void Heap::changePriority(int i, int value)
{
	int oldValue = H[i];
	H[i] = value;
	
	if(value > oldValue)
	{
		siftUp(i);
	}
	else
	{
		siftDown(i);
	}
}

void Heap::getSize()
{
	cout << "Size: \t" << size << "\n";
}


int main()
{
	Heap H(11);
	H.insert(3);
	
	H.getSize();
	H.print();
	
	H.insert(2);
	
	H.getSize();
	H.print();
	
	H.remove(1);
	
	H.getSize();
	H.print();
	
	 
	H.insert(15);
	
	H.getSize();
	H.print();
	
	
	H.insert(5);
	H.insert(4);
	H.insert(45);
	
	H.getSize();
	H.print();
	
	H.getMax();
	cout << "MAX element (extracted): "	<< H.extractMax() << "\n";
	H.changePriority(2, 1);
	
	H.getSize();
	H.print();
	
	
	return 0;
}
