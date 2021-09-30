#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int h)
{

    int i = l, j = mid + 1, k = 0;

    while (i < mid + 1 && j < h + 1)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < mid + 1)
        temp[k++] = arr[i++];
    while (j < h + 1)
        temp[k++] = arr[j++];

    for (int i = l, k = 0; i <= h; i++, k++)
    {
        arr[i] = temp[k];
    }

    delete[] temp;
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        merge(arr, l, mid, h);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}