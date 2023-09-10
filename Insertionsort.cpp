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

    for (int i = 1; i < b; i++) {
        int k = a[i], j = i - 1;
        if (a[j] < k) continue;
        while (j >= 0 && a[j] > k) {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = k;

        for (int c = 0; c < b; c++)
        {
            cout << a[c] << " ";
        }
        cout << endl;
    }

    return 0;
}
