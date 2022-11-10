# Live Coding 15 - Recursion

## Recursion

> Design a class AbstractSort that can be used to analyze the number of comparisons performed by a sorting algorithm.
>
> The class should have a member function compare that is capable of comparing two int and a means of keeping track of the number of comparisons performed.
>
> ```cpp
> int compare(int x, int y);
> int comparisonCount;
> ```
>
> The class should also have a virtual member function that needs to be overridden by subclasses.
>
> ```cpp
> virtual void sort(int arr[], int size){}
> ```
>
> When overridden this function will sort the int array by calling the compare function to determine the relative order of pairs of numbers.
>
> Create a subclass of AbstractSort that uses a simple sorting algorithm to implement the sort function.
>
> The class should have a member function that can be called after the sorting is done to retrieve the number of comparisons performed.
