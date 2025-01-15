/*
Name: Pearl Esezobor
NetID: w10167217
Program Description:A program that calculates the runtime of a Bubble Sort and quick
sort algorithim */




#include <random>
#include "sorting.h"

using namespace std;

// An optimized version of Bubble Sort
void bubbleSort(std::vector<int> arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}


int partition(std::vector<int> arr, int low, int high)
{
    //choose the pivot

    int pivot = arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i = (low - 1);

    for (int j = low;j <= high;j++)
    {
        //If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            //Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(std::vector<int> arr, int low, int high)
{
    // when low is less than high
    if (low < high)
    {
        // pi is the partition return index of pivot

        int pi = partition(arr, low, high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

std::vector<int> random(int size)
{
    int min = 1;

    int max = 1000;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    std::vector<int> result(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = dist6(rng);
    }
    return result;
}


/*
The following code is referenced from geeksforgeeks.org
which can be found at the following link:
https://www.geeksforgeeks.org/bubble-sort/
https://www.geeksforgeeks.org/quick-sort/

Date Accessed: April 30, 2024
*/