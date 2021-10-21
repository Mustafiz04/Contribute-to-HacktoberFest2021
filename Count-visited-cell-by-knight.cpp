#include <bits/stdc++.h>
using namespace std;
 
const int N = 10;
 
// All possible moves of the knight.
 
// In X axis.
vector<int> X = { 2, 1, -1, -2, -2, -1, 1, 2 };
 
// In Y axis.
vector<int> Y = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
void getCountRec(vector<vector<bool> >& board,
                 int i, int j, int n)
{
    // if n=0, we have our result.
    if (n == 0)
        return;
 
    for (int k = 0; k < 8; k++) {
        int p = i + X[k];
        int q = j + Y[k];
 
        // Condition for valid cells.
        if (p >= 0 && q >= 0
            && p < 10 && q < N) {
            board[p][q] = true;
            getCountRec(board, p, q, n - 1);
        }
    }
}
 
int getCount(int i, int j, int n)
{
    vector<vector<bool> > board(N, vector<bool>(N));
    board[i][j] = true;
 
    // Call the recursive function to mark
    // visited cells.
    getCountRec(board, i, j, n);
 
    int cnt = 0;
    for (auto row : board) {
        for (auto cell : row) {
            if (cell)
                cnt++;
        }
    }
    return cnt;
}
 
// Driver Code
int main()
{
    int i = 3, j = 3, N = 2;
    cout << getCount(i, j, N) << endl;
    return 0;
}
