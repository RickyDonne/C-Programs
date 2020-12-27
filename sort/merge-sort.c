#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *A,int n);
void Merge(int *A, int *L, int *R, int leftCount, int rightCount);

int main() {

	int A[] = {6,2,3,1,9,10,15,13,12,17};
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]);

	MergeSort(A,numberOfElements);

	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);

	return 0;
}

void MergeSort(int *A,int n)
{
	int mid,i, *L, *R;
	if(n < 2) return;

	mid = n/2;

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,R,mid,n-mid);
    free(L);
    free(R);
}

void Merge(int *A, int *L, int *R, int leftCount, int rightCount)
{
	int i,j,k;
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount)
        {
            if(L[i] < R[j])
            {
                A[k] = L[i];
                ++i;
            }
            else
            {
                A[k] = R[j];
                ++j;
            }
            ++k;
        }
	while(i < leftCount)
    {
        A[k] = L[i];
        ++i;
        ++k;
    }
	while(j < rightCount)
    {
        A[k] = R[j];
        ++j;
        ++k;
    }
}
