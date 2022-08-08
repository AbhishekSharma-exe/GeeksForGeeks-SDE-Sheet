#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int BinarySearch(int arr[], int low, int high, int element)
{
    if (low <= high)
    {

        int mid = (low + high)/2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] > element)
        {
            return BinarySearch(arr, low, mid - 1, element);
        }
        if (arr[mid] < element)
        {
            return BinarySearch(arr, mid + 1, high, element);
        }
    }

    return -1;
}
int main()
{
    int arr[] = {2, 5, 9, 11, 19, 21, 45, 56};
    int size = sizeof(arr) / sizeof(int);

    int element;
    cout << "Element to be searched : ";
    cin >> element;

    int index = BinarySearch(arr, 0, size - 1, element);
    if (index != -1)
    {
        cout << "Index : " << index;
    }
    else
    {
        cout << "Element not found";
    }
}