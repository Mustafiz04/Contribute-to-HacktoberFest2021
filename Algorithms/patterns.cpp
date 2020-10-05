#include <bits/stdc++.h>
using namespace std;
void Pattern1();
void Pattern2();
void Pattern3();
void Pattern4();
void Pattern5();
void Pattern6();
void Pattern7();
int main()
{
	int n;
	char flag = 'N';
	do
	{
	cout<<"Which pattern do you want to see. Enter the number : ";
	cin>>n;

	switch(n)
	{
		case 1 : Pattern1();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 2 : Pattern2();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 3 : Pattern3();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 4 : Pattern4();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 5 : Pattern5();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 6 : Pattern6();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		case 7 : Pattern7();cout<<"Press 'Y' to continue."<<endl;cin>>flag;
		break;
		default : cout<<"Work in progress. Please come later";
    }
}while(flag =='Y'||flag == 'y');
	return 0;
}
void Pattern1()
{
	for(int i=0;i<5;i++)
	{
		for(int k=i;k>0;k--)
		{	
			cout<<"  ";
		}
		for(int j=5-i;j>0;j--)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
}
void Pattern2()
{
	for(int i=0;i<5;i++)
	{
		for(int k=i;k>0;k--)
		{	
			cout<<"    ";
		}
		for(int j=5-i;j>0;j--)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	
}
void Pattern3()
{
	cout<<"Not fully identical"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int k=i;k<5;k=k+1)
		{	
			cout<<" ";
		}
		for(int j=0;j<=i;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}	
}
void Pattern4()
{
	for(int i=1;i<6;i++)
	{
		for(int k = 5-i;k>=0;k--)
		{
			cout<<"  ";
		}
		for(int j = 0;j<i;j++)
		{
			cout<<" *";
		}
		cout<<endl;
	}
	for(int i = 4;i>0;i--)
	{
		for(int k = 5-i;k>=0;k--)
		{
			cout<<"  ";
		}
		for(int j = 0;j<i;j++)
		{
			cout<<" *";
		}
		cout<<endl;
	}
}
void Pattern5()
{
	cout<<"Incorrect solution. Searching for answers.\n\n";
	int n = 12;
	for(int i = 1;i<=13;i++)
	{
		for(int j = 1;j<=n/2+1;j++)
		{
			if(i%2 != 0)
			{
				if(i != n/2 + 1)
				{
					cout<<"* ";
				}
				else cout<<" ";
			}
			else cout<<" ";
		}cout<<endl;
	}
}
void Pattern6()
{
	for(int i=1;i<10;i++)
	{
		if(i%2 != 0)
		{
			for(int k = 10-i;k>=0;k--)
			{
				cout<<" ";
			}
			for(int j = 1;j<=i;j++)
			{
				cout<<j<<" ";
			}
			cout<<endl;
    	}
	}
}
void Pattern7()
{
	for(int i = 1;i<=10; i++)
	{
		if(i%2 != 0)
		{
			for(int k = (10-i)/2;k>0;k--)
			{
				cout<<"  ";
			}
			for(int j = 1;j<=i;j++)
			{
				if(j==i || j==1)
				{
					cout<<i/2+1<<" ";
				}
				else cout<<"0 ";
			}
		}
		cout<<endl;
	}
}
