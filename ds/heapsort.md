
##Heap Sort Algorithm

Heap Sort is one of the best sorting methods being in-place and with no quadratic worst-case scenarios. Heap sort algorithm is divided into two basic parts :

-Creating a Heap of the unsorted list.

-Then a sorted array is created by repeatedly removing the largest/smallest element from the heap, and inserting it into the array. The heap is reconstructed after each removal.

##What is a Heap ?

Heap is a list that satisfy the following special heap properties :

  Suppost a[1 . . n], where n = length[a].  Then each element a[i] is either [greater than or equal to] or [less than or equal to] each of its children a[2i] and a[2i\+1].  ( if its children  exist,that is  2i<n , 2i+1<n). 

If the parent nodes are greater than their children, heap is called a **Max-Heap**, and if the parent nodes are smalled than their child nodes, heap is called **Min-Heap**.

**heap can be imagine as a sequential-memory of a Complete Binary Tree with special Shape Property**

   A array  be imagine as a sequential-memory of a Complete Binary Tree.

   ![](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13ex-Fig01.jpg)

   A Heap be imagine as a sequential-memory of a Complete Binary Tree with special Shape Property.

   ![](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13ex-Fig07.jpg)

##How Heap Sort Works

 1) first, the  unordered list is converted to a heap using the function buildheap() which depend on a satisfyheap() which adjust a node i to satisfy the heap properties.

    Please see ** "A Building the heap tree" ** in refer 1)

 2) second,  the first element of the Heap is either largest or smallest(depending upon Max-Heap or Min-Heap), so we swap the first element  and the last element of the heap.  the largest or smallest element will be at the tail. Then we adjust the remain elements to a heap y calling satisfyheap() so that the first element in the reamin elements satisfy the heap properties.

    Please see ** "B Sorting - performing deleteMax operations:" ** in refer 1)


 ```
void satisfyheap(int a[], int i, int heapsize)
{
  int l, r, largest, temp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] > a[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if( r <= heapsize && a[r] > a[largest])
  {
    largest = r;
  }
  if(largest != i)
  {
    temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    satisfyheap(a, largest, heapsize);
  }
}

void buildheap(int a[], int length)
{
  int i, heapsize;
  heapsize = length - 1;
  for( i=(length/2); i >= 0; i--)
  {
    satisfyheap(a, i, heapsize);
  } 
}


void heapsort(int a[], int length)
{
  buildheap(a, length);
  int heapsize, i, temp;
  heapsize = length - 1;
  for( i=heapsize; i >= 0; i--)
  {
    temp = a[0];
    a[0] = a[heapsize];
    a[heapsize] = temp;
    heapsize--;
    satisfyheap(a, 0, heapsize);
  }
  for( i=0; i < length; i++)
  {
    cout << "\t" << a[i];
  }
}

void main()
{
  int a[10], i, size;
  cout << "Enter size of list";    // less than 10, because max size of array is 10
  cin >> size;
  cout << "Enter" << size << "elements";
  for( i=0; i < size; i++)
  {
    cin >> a[i];
  }
  heapsort(a, size);
  getch();
}

```



**Reference**

[](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13-HeapSortEx.htm)

[](http://www.studytonight.com/data-structures/heap-sort)

[](https://www.cs.usfca.edu/~galles/visualization/HeapSort.html)  
