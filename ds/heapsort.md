
## Heap Sort Algorithm

Heap Sort is one of the best sorting methods being in-place and with no quadratic worst-case scenarios. Heap sort algorithm is divided into two basic parts :

-Creating a Heap of the unsorted list.

-Then a sorted array is created by repeatedly removing the largest/smallest element from the heap, and inserting it into the array. The heap is reconstructed after each removal.

##What is a Heap ?

Heap is a list that satisfy the following special heap properties :

  Suppost a[1 . . n], where n = length[a].  Then each element a[i] is either [greater than or equal to] or [less than or equal to] each of its children a[2i] and a[2i\+1]  ( if its children  exist,that is  2i<n , 2i+1<n). 

If the parent nodes are greater than their children, heap is called a **Max-Heap**, and if the parent nodes are smalled than their child nodes, heap is called **Min-Heap**.

**heap can be imagine as a sequential-memory of a Complete Binary Tree with special Shape Property**

   A array  be imagine as a sequential-memory of a Complete Binary Tree.

   ![](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13ex-Fig01.jpg)

   A Heap be imagine as a sequential-memory of a Complete Binary Tree with special Shape Property.

   ![](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13ex-Fig07.jpg)

#### Reference  

[](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L13-HeapSortEx.htm)  

[](http://www.studytonight.com/data-structures/heap-sort)  

[](https://www.cs.usfca.edu/~galles/visualization/HeapSort.html)  
