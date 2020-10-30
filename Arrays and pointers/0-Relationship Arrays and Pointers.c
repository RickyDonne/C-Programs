#include <stdio.h>
int main() {
   int x[4];
   int i;

   for(i = 0; i < 4; ++i) {
      printf("&x[%d] = %p\n", i, &x[i]);
   }

   printf("Address of array x: %p", x);

   return 0;
}

/*
Output:
&x[0] = 1450734448
&x[1] = 1450734452
&x[2] = 1450734456
&x[3] = 1450734460
Address of array x: 1450734448

There is a difference of 4 bytes between two consecutive elements of array x. It is because the size of int is 4 bytes (on our compiler).
Notice that, the address of &x[0] and x is the same. It's because the variable name x points to the first element of the array.

From the above example, it is clear that &x[0] is equivalent to x. And, x[0] is equivalent to *x.
Similarly,

&x[1] is equivalent to x+1 and x[1] is equivalent to *(x+1).
&x[2] is equivalent to x+2 and x[2] is equivalent to *(x+2).
Basically, &x[i] is equivalent to x+i and x[i] is equivalent to *(x+i).


*/
