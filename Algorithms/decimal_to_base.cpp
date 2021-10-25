#include<iostream>
using namespace std;
void print_decimal_to_base(int n, int b)
{
    if(n == 0)
    {
        cout<<0;
        return;
    }
    int a[64] = {0}, i = 0;
    while(n > 0)
    {
        a[i] = n % b;
        n = n / b;
        i++;
    }
    for(int j = i-1; j >= 0; j--)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n = 12;
    print_decimal_to_base(n, 2);
    print_decimal_to_base(n, 10);
    print_decimal_to_base(n, 4);
    print_decimal_to_base(n, 8);
    return 0;
}