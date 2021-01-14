#include <stdio.h>
int main(void) {
    int t;
    long long i, a, b, lcm, gcd, prod, temp;
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld", &a, &b);
        prod = a * b;
        while (b != 0) 
        {
        	temp = b;
        	b = a % b;
 	        a = temp;
        }
        gcd = a;
        lcm = prod / gcd;
        printf("%lld %lld\n", gcd, lcm);
    }
	return 0;
}
