#include<bits/stdc++.h>
using namespace std;

int palindrome(int a, int t){
  if (a == 0)
  return t;
  t = (t * 10) + (a % 10);
  return palindrome(a / 10, t);
}

int main(){
  int n;
  cout<<"Enter the number :"; cin>>n;
  int result = palim(n, 0);
  if (result == n)
    cout << "Number "<<n<<" is a palindrome" << endl;
  else
    cout << "Number "<<n<<" is not a palindrome"<< endl;
  return 0;
}
