#include <stdio.h>
int main(void)
{
    int t, n, i, count;
    int notes[6] = {100, 50, 10, 5, 2, 1};

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        count = 0;
        i = 0;
        while (n != 0)
        {
            if (n >= notes[i])
            {
                n -= notes[i];
                ++count;
            }
            else
            {
                ++i;
            }
        }
        printf("%d\n", count);
    }
	return 0;
}
