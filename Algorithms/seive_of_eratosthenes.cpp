#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void print_primes(int n)
{
    vector<int> primes(n+1);
    for(int i = 0; i <= n; i++)
        primes[i] = 1; // intially all numbers till n are prime
    
    primes[0] = 0; // 0 and 1 aren't primes
    primes[1] = 0;
    
    for(int i = 0; i <= sqrt(n); i++)
    {
        if(primes[i] == 1)
        {
            for(int j = 2; i*j <= n; j++)
            {
                primes[j*i] = 0;
            }
        }
    }
    for(int i = 0; i <= n; i++ )
        if(primes[i] != 0)
            cout<<i<<" ";
}
// bool isPrime(int n)
// {
//     int flag = 0;
//     for(int i = 2; i < sqrt(n); i++)
//     {
//         if(n%i == 0)
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if(flag == 1)
//         return 0;
//     else    
//         return 1;
// }
// void normal_prime(int n)
// {
//     for(int i = 2; i <= n; i++)
//     {
//         if(isPrime(i))
//             cout<<i<<" ";
//     }
// }
int main()
{
    int n = 10000;
    print_primes(n);
    // normal_prime(n);
    return 0;
}