#include <iostream>

using namespace std;

int unionArray(int a[], int b[], int n, int m)
{
    int i, j;
    int count = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            count++;
            i++;
        }
        else if (a[i] > b[j])
        {
            count++;
            j++;
        }
        else
        {
            count++;
            i++, j++;
        }
    }

    while (i < n)
    {
        count++;
        i++;
    }

    while (j < m)
    {
        count++;
        j++;
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        int counter = unionArray(a, b, n, m);
        cout << counter << endl;
    }
}