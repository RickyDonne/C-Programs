#include <iostream>

using std::cout;
using std::endl;

/**********prototype:************/
void bubblesort(int arr[], int n);
void swap(int *large, int *small);
void printarray(int arr[], int n);
void selectionsort(int arr[], int n);
void insertionsort(int arr[], int n);
void mergesort(int arr[], int l, int r); void merge (int arr[], int l, int m, int r);
void quicksort(int arr[], int low, int high); int partition (int arr[], int low, int high);
/*****************************************************************************************/

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

//    bubblesort(arr, n);
//    selectionsort(arr, n);
//    insertionsort(arr, n);
//    mergesort(arr, 0, n - 1);
    quicksort(arr, 0, n - 1);

    printarray(arr, n);
    return 0;
}
/***************Quick-sort****************/
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
/*****************************************/

/************Merge-sort**************/
void mergesort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r - 1) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] =  R[j];
        j++;
        k++;
    }
}
/************************************/

/********Insertion-sort***************/
void insertionsort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/***********Selection-sort*************/
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int mini = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(&arr[mini], &arr[i]);
    }
}

/************Bubble-sort**************/
void bubblesort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for(int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void swap(int *large, int *small)
{
    int temp = *large;
    *large = *small;
    *small = temp;
}

void printarray(int arr[], int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
/***********End********************************/
