#include <iostream>

using namespace std;

int sumOfN(int n)
{
    return (n * n + n) / 2;
}

void missingNumb(int arr[], int n)
{
    int sum = sumOfN(n);
    int arrSum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        arrSum += arr[i];
    }
    cout << sum - arrSum;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        missingNumb(arr, n);
    }
}