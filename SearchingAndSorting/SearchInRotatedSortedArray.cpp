#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPivot(int arr[], int l, int h)
    {
        int mid = l + (h - l) / 2;

        while (l < h)
        {

            if (arr[mid] >= arr[0])
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
            mid = l + (h - l) / 2;
        }

        return mid;
    }

    int BinarySearch(int arr[], int l, int h, int key)
    {

        if (h >= l)
        {

            int mid = l + (h - l) / 2;

            if (arr[mid] == key)
                return mid;
            if (arr[mid] > key)
            {
                return BinarySearch(arr, l, mid - 1, key);
            }
            if (arr[mid] < key)
            {
                return BinarySearch(arr, mid + 1, h, key);
            }
        }

        return -1;
    }
    int search(int arr[], int l, int h, int key)
    {

        int pivot = findPivot(arr, l, h);
        if (key >= arr[0])
        {
            return BinarySearch(arr, l, pivot - 1, key);
        }
        else
        {
            return BinarySearch(arr, pivot, h, key);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
