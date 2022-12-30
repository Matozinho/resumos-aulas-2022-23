#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

// quick sort algorithm
void quickSort(int *arr, int left, int right)
{
  int _left = left, _right = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  // Use current time as seed for random generator
  srand(time(0));

  int possibleIndexes = right - left;

  std::random_device randDev;
  std::mt19937 twister(randDev());
  std::uniform_int_distribution<int> dist(left, right);

  std::cout << "Random Number: " << dist(twister);
  std::cout << " | left: " << left << " rigth: " << right << std::endl;

  // get the pivot by tree random numbers
  // if (sizeof arr < 3)
  //   pivot = arr[static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (0 - sizeof arr)))];
  // else
  // {
  //   int a = arr[static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (0 - sizeof arr)))];
  //   int b = arr[static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (0 - sizeof arr)))];
  //   int c = arr[static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (0 - sizeof arr)))];
  //   pivot = (a + b + c) / 3;
  // }

  /* partition */
  while (_left <= _right)
  {
    while (arr[_left] < pivot)
      _left++;
    while (arr[_right] > pivot)
      _right--;
    if (_left <= _right)
    {
      tmp = arr[_left];
      arr[_left] = arr[_right];
      arr[_right] = tmp;
      _left++;
      _right--;
    }
  };

  /* recursion */
  if (left < _right)
    quickSort(arr, left, _right);
  if (_left < right)
    quickSort(arr, _left, right);
}

// counting sort algorithm
void countingSort(int *arr, int n)
{
  // varredura para descobrir o maior valor do conjunto
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];

  int *count = new int[max + 1];
  for (int i = 0; i <= max; i++)
    count[i] = 0;

  for (int i = 0; i < n; i++)
    count[arr[i]]++;

  int j = 0;
  for (int i = 0; i <= max; i++)
    while (count[i] > 0)
    {
      arr[j] = i;
      j++;
      count[i]--;
    }
}

// the params are 1 - filename and 2 - method => count | quick
int main(int argc, char *argv[])
{
  const std::string fileName = argv[1];
  const std::string method = argv[2];

  // read all numbers from file into an array
  // std::ifstream file(fileName);
  // std::vector<int> values;
  // int number;
  // while (file >> number)
  //   values.push_back(number);

  // int length = values.size();

  // convert vector to array
  // int *valuesArr = new int[length];
  // for (int i = 0; i < length; i++)
  //   valuesArr[i] = values[i];

  // count time execution of the methods
  std::chrono::time_point<std::chrono::system_clock> start, end;
  int length = 10;
  int valuesArr2[length] = {-20, 0, 1, 2, 3, -50, -100, 100, 50, 20};

  start = std::chrono::high_resolution_clock::now();
  quickSort(valuesArr2, 0, length - 1);
  end = std::chrono::high_resolution_clock::now();

  std::cout << "[ ";
  for (int i = 0; i < length; i++)
    std::cout << valuesArr2[i] << " ";
  std::cout << " ]" << std::endl;

  // if (method == "count")
  // {
  //   start = std::chrono::high_resolution_clock::now();
  //   countingSort(valuesArr, length);
  //   end = std::chrono::high_resolution_clock::now();
  // }
  // else if (method == "quick")
  // {
  //   start = std::chrono::high_resolution_clock::now();
  //   quickSort(valuesArr, 0, length - 1);
  //   end = std::chrono::high_resolution_clock::now();
  // }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << duration << std::endl;

  return 0;
}
