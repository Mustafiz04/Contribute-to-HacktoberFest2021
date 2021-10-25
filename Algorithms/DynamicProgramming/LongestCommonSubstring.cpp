#include <iostream>
using namespace std;

//program to find length of the longest common substring using dp recursively
string X, Y;
int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1])
    {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count, max(lcs(i, j - 1, 0), lcs(i - 1, j, 0)));
    return count;
}

int main()
{
    int n, m;
    X = "abcdxyz";
    Y = "xyzabcd";

    n = X.size();
    m = Y.size();

    cout << lcs(n, m, 0);

    return 0;
}