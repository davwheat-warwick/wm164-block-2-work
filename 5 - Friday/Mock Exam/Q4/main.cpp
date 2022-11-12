#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

#include "./main.hpp"

/*
Birmingham 120
Derbyshire 94
Essex 182
Hertfordshire 174
Kent 157
Liverpool 102
Northamptonshire 107
Nottinghamshire 88
Staffordshire 89
Wolverhampton 89
*/

#define ARR_SIZE 10

int main(int argc, char *argv[])
{
  std::string ultaNames[ARR_SIZE] = {"Birmingham", "Derbyshire", "Essex", "Hertfordshire", "Kent", "Liverpool", "Northamptonshire", "Nottinghamshire", "Staffordshire", "Wolverhampton"};
  int ultaCases[ARR_SIZE] = {120, 94, 182, 174, 157, 102, 107, 88, 89, 89};

  // find length of largest string in ultaNames
  int largestUltaName = 0;
  for (int i = 0; i < ARR_SIZE; i++)
  {
    if (ultaNames[i].length() > largestUltaName)
    {
      largestUltaName = ultaNames[i].length();
    }
  }
  size_t padLength = (size_t)largestUltaName + 2;

  int ultaCasesSelectionCopy[ARR_SIZE];
  std::copy(std::begin(ultaCases), std::end(ultaCases), std::begin(ultaCasesSelectionCopy));

  int ultaCasesBubbleCopy[ARR_SIZE];
  std::copy(std::begin(ultaCases), std::end(ultaCases), std::begin(ultaCasesBubbleCopy));

  // Sort
  // selectionSort(ultaCasesSelectionCopy, ARR_SIZE);
  // Sort
  bubbleSort(ultaCasesSelectionCopy, ARR_SIZE);

  for (int i = 0; i < ARR_SIZE; i++)
  {
    // Find the index of the name based on cases location in the original array
    int index = std::distance(ultaCases, std::find(ultaCases, ultaCases + ARR_SIZE, ultaCasesSelectionCopy[i]));

    // Pad left of name to keep nums aligned
    std::string t = std::string(padLength, ' ') + ultaNames[index];
    std::string padded = t.substr(std::min(t.size() - padLength, padLength));

    std::cout << padded << " " << ultaCasesSelectionCopy[i] << std::endl;
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n)
{
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap(&arr[min_idx], &arr[i]);
  }
}

void bubbleSort(int arr[], int n)
{
  // Inefficient -- does not check for swaps in each outer iteration
  // for exit early case
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}