#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x, y;
        cin >> x >> y;

        string str;
        int r{0}, l{0}, u{0}, d{0};

        if (x > 0)
        {
            while (x != 0)
            {
                ++r;
                --x;
            }
        }
        else
        {
            while (x != 0)
            {
                ++l;
                ++x;
            }
        }

        if (y > 0)
        {
            while ( y != 0)
            {
                ++u;
                --y;
            }
        }
        else
        {
            while (y != 0)
            {
                ++d;
                ++y;
            }
        }

        string orders;
        cin >> orders;

        int pr{0}, pl{0}, pu{0}, pd{0};

        for (int i = 0; i < orders.length(); ++i)
        {
            if (orders[i] == 'U')
                ++pu;
            else if (orders[i] == 'D')
                ++pd;
            else if (orders[i] == 'R')
                ++pr;
            else if (orders[i] == 'L')
                ++pl;
        }

        if ( r > pr || u > pu || l > pl || d > pd)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;


    }
}
