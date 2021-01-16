#include <math.h>
#include <stdio.h>

int main()
{
    int t, r, a[3][2], i, j;
    double d1, d2, d3;
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &r);
        for (i = 0; i < 3; ++i)
        {
            for (j = 0; j < 2; ++j)
                scanf("%d", &a[i][j]);
        }
        
	    d1=(double)sqrt(pow((a[0][0]-a[1][0]),2)+pow((a[0][1]-a[1][1]),2));
	    d2=(double)sqrt(pow((a[1][0]-a[2][0]),2)+pow((a[1][1]-a[2][1]),2));
	    d3=(double)sqrt(pow((a[0][0]-a[2][0]),2)+pow((a[0][1]-a[2][1]),2));
	    if((d1<=r && d2<=r) || (d2<=r && d3<=r) || (d1<=r && d3<=r))
	        printf("yes\n");
	    else
	        printf("no\n");
    }
    
    return 0;
}
