#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int len;
};

void Display (struct Array arr);
void Append (struct Array *arr, int key);
void insert (struct Array *arr, int pos, int key);

int main()
{
    struct Array arr1 = {{2, 5, 6, 3, 7, 9}, 10, 6};
    Display(arr1);

    Append(&arr1, 8);
    Display(arr1);

    insert(&arr1, 2, 4);
    Display(arr1);

    return 0;
}

void Display (struct Array arr)
{
    printf("Elements are: ");
    for (int i = 0; i < arr.len; ++i)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void insert (struct Array *arr, int pos, int key)
{
    if (pos >= 0 && pos <= arr->len)
    {
        for (int i = arr->len; i > pos; --i)
            arr->A[i] = arr->A[i - 1];
        arr->A[pos] = key;
        ++arr->len;
    }
}

void Append (struct Array *arr, int key)
{
    if (arr->size > arr->len)
    {
        arr->A[arr->len] = key;
        ++arr->len;
    }
}
