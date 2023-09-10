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

    int d;
    for (int c = 1; c < b; c++)
    {
        int n = 0;
        for (int i = 0; i < b-1; i++)
        {
            if (a[i] > a[i+1]) n++;
        }

        if (n > 0) {
            for (int i = 0; i < b-1; i++)
            {
                if (a[i] > a[i+1]) {
                    d = a[i];
                    a[i] = a[i+1];
                    a[i+1] = d;
                    for (int i = 0; i < b; i++)
                    {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                }
            }
        } else {
            return 0;
        }
    }
}

