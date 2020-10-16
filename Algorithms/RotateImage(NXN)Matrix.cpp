#include <bits/stdc++.h>
using namespace std;

int R,C;
void reverseColumns(int arr[1000][1000])
{
    for (int i = 0; i < C; i++)
        for (int j = 0, k = R - 1; j < k; j++, k--)
            swap(arr[j][i], arr[k][i]);
}

void transpose(int arr[1000][1000])
{
    for (int i = 0; i < R; i++)
        for (int j = i; j < C; j++)
            swap(arr[i][j], arr[j][i]);
}

void printMatrix(int arr[1000][1000])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

void rotate90(int arr[1000][1000])
{
    transpose(arr);
    reverseColumns(arr);
}

int main()
{
    int N;
    cin>>N;
    R=N;C=N;

    int arr[1000][1000];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>arr[i][j];
    rotate90(arr);
    printMatrix(arr);
    return 0;
}
