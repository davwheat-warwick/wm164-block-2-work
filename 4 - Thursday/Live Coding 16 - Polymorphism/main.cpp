#include <iostream>
#include <memory>

#include "./main.hpp"

int main(int argc, char *argv[])
{
  // init randomiser with better seed
  unsigned long seed = mix(clock(), time(NULL), getpid());
  srand(seed);

  int unsortedArray[DATASET_SIZE];

  // Fill dataset with random numbers up to 10,000
  for (int i = 0; i < DATASET_SIZE; i++)
  {
    unsortedArray[i] = rand() % 10000;
  }

  std::unique_ptr<BubbleSort> bubbleSort(new BubbleSort());

  // copy unsortedArray to allow for expansion
  // with more sorting algorithms without changing
  // the original array
  int *bubbleArray = (int *)malloc(sizeof(int) * DATASET_SIZE);
  memcpy(bubbleArray, unsortedArray, sizeof(int) * DATASET_SIZE);

  bubbleSort->sort(bubbleArray, DATASET_SIZE);

  // Output comparison count
  std::cout << "Bubble sort comparisons: " << bubbleSort->getComparisonCount() << std::endl;
}

int generateRandomNumber()
{
  return rand() % 100;
}

AbstractSort::getComparisonCount() const
{
  return comparisonCount;
}

AbstractSort::compare(int a, int b)
{
  comparisonCount++;

  if (a == b)
  {
    return 0;
  }

  if (a < b)
  {
    return -1;
  }

  return 1;
}

void BubbleSort::sort(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    int swaps = 0;

    for (int j = 0; j < size - 1; j++)
    {

      if (compare(arr[j], arr[j + 1]) == 1)
      {
        ++swaps;

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    // If no moves have happened, the array is sorted
    if (swaps == 0)
    {
      break;
    }
  }
}

// Robert Jenkins' 96 bit Mix Function
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
  a = a - b;
  a = a - c;
  a = a ^ (c >> 13);
  b = b - c;
  b = b - a;
  b = b ^ (a << 8);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 13);
  a = a - b;
  a = a - c;
  a = a ^ (c >> 12);
  b = b - c;
  b = b - a;
  b = b ^ (a << 16);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 5);
  a = a - b;
  a = a - c;
  a = a ^ (c >> 3);
  b = b - c;
  b = b - a;
  b = b ^ (a << 10);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 15);
  return c;
}