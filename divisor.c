#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    long long d, count, i, j;
    while (t--)
    {
        scanf("%lld", &d);

        for (i = 6; i < 10000000; ++i)
        {
            count = 0;
            for (j = 1; j <= i; j += d)
            {
                if (i % j == 0)
                    ++count;
            }

            if (count >= 4)
            {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}
