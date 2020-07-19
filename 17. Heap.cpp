#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Heap //MAX Heap
{
	int *a;
	int size,capacity;
public:
	Heap(int c=100)
	{
		this->capacity=c;
		this->size=0;
		a=new int [capacity];
	}

	inline int parent(int i)
	{
		return int((i-1)/2);
	}
	inline int left(int i)
	{
		return 2*i+1;
	}
	inline int right(int i)
	{
		return 2*i+2;
	}

	int getMax()
	{
		if(size>0)
		{
			return a[0];
		}
		cout<<"Heap Empty\n";
		return -1;
	}

	void build(int *arr,int n)
	{
		for(int i=(n-2)/2;i>=0;--i)
		{
			heapifyMaxHeap(arr, n, i);
		}
		size=n;
		for(int i=0;i<n;++i)
			a[i]=arr[i];
	}
	void heapifyMaxHeap(int *arr, int n, int i)
	{
		int size=n;
		int l=left(i);
		int r=right(i);
		int large=i;
		if(l<size && arr[l]>arr[i])	large=l;
		if(r<size && arr[r]>arr[large])	large=r;
		if(i!=large)
		{
			swap(arr[i],arr[large]);
			heapifyMaxHeap(arr, n, large);
		}
	}

	void heapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int large=i;
		if(l<size && a[l]>a[i])	large=l;
		if(r<size && a[r]>a[large])	large=r;
		if(i!=large)
		{
			swap(a[i],a[large]);
			heapify(large);
		}
	}

	int extractMax()
	{
		if(size<1)
		{
			cout<<"Heap is empty\n";
			return -1;
		}
		else if(size==1)
		{
			--size;
			return a[1];
		}
		int x=a[0];
		a[0]=a[--size];
		heapify(0);
		return x;
	}

	void insert(int val)
	{
		if(size==capacity)
		{
			cout<<"Heap is Full\n";
			return;
		}
		a[size++]=val;
		int i=size-1;
		while(i>0 && a[i]>a[parent(i)]) //only till root before no parent to root is there
		{
			swap(a[i],a[parent(i)]);
			i=parent(i);
		}
	}

	void display()
	{
		loop(i,0,size)
		{
			cout<<a[i]<<" ";
		}
		cout<<nl;
	}
};


int main()
{
    Heap *p=new Heap();
	int abc[] = {2,3,6,4,1,1,123123,123,3,12,3,1234,12321,21,7897,456,234,546,34,34,56,44,77,66};
	int n=sizeof(abc)/sizeof(abc[0]);
	p->build(abc,n);
	p->display();

    cout<<endl<<endl;
    return 0;
}
