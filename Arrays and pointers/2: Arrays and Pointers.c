#include <stdio.h>
int main() {
  int x[5] = {1, 2, 3, 4, 5};
  int* ptr;

  // ptr is assigned the address of the third element
  ptr = &x[2]; 

  printf("*ptr = %d \n", *ptr);   // 3
  printf("*(ptr+1) = %d \n", *(ptr+1)); // 4
  printf("*(ptr-1) = %d", *(ptr-1));  // 2

  return 0;
}

/*
In this example, &x[2], the address of the third element, is assigned to the ptr pointer. Hence, 3 was displayed when we printed *ptr.
And, printing *(ptr+1) gives us the fourth element. Similarly, printing *(ptr-1) gives us the second element.
*/
