#ifndef MAIN_H
#define MAIN_H

#define DATASET_SIZE 100

unsigned long mix(unsigned long a, unsigned long b, unsigned long c);

class AbstractSort
{
private:
  int comparisonCount{0};

protected:
  /**
   * @brief Compares two values and returns true if the first is greater than the second.
   *
   * Returns 0 if the values are equal.
   * Returns -1 if the first value is less than the second.
   * Returns 1 if the first value is greater than the second.
   */
  int compare(int a, int b);

public:
  AbstractSort() = default;
  virtual ~AbstractSort() = default;

  int getComparisonCount() const;

  virtual void sort(int *arr, int size) = 0;
};

class BubbleSort : public AbstractSort
{
public:
  BubbleSort() = default;
  virtual ~BubbleSort() = default;

  void sort(int *arr, int size) override final;
};

#endif
