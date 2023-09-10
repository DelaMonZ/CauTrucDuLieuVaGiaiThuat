#include <iostream>

using namespace std;

void _swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int _partition(int a[], int l, int h) {
    int pivot = a[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (a[j] < pivot) {
            i++;
            _swap(a, i, j);
        }
    }
    _swap(a, i + 1, h);
    return i + 1;
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int k = _partition(a, l, h);
        quickSort(a, l, k - 1);
        quickSort(a, k + 1, h);
    }
}

int main()
{
    int b;
    cin >> b;
    int a[b];
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, b - 1);
    for (int i = 0; i < b; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

