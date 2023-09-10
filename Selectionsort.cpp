#include <iostream>

using namespace std;

int main()
{
    int b;
    cin >> b;
    int a[b];
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < b-1; i++)
    {
        int k = i, h;
        for (int j = i+1; j < b; j++)
        {
            if (a[j] < a[k]) {
                k = j;
            }
        }

        if (i != k) {
            h = a[i];
            a[i] = a[k];
            a[k] = h;
            for (int c = 0; c < b; c++)
            {
                cout << a[c] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
