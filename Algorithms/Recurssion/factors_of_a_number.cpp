#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void print_factors(int n)
{
    vector <int> v(n);
    int root = sqrt(n);
    int count = 0;
    for(int i = 1; i <= root; i++)
    {
        if(n % i == 0)
        {
            v[count] = i;
            count++;
            v.push_back(i);
            if(i != root)
            {
                v[count] = n / i;
                count++;
            }
        }
    }
    sort(v.begin(), v.begin()+count);
    for(int i = 0; i < count; i++)
        cout<<v[i]<<" ";
}
int main()
{
    int n = 24;
    print_factors(n);
    return 0;
}