#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,len,j;
	char pt[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ch[26]={'w','x','y','z','q','r','s','t','u','v','j','k','l','m','n','o','p','f','g','h','i','c','d','e','a','b'};
	char key[20],key1[20],key2[20];
	printf("enter the key\n");
	gets(key);
	len=strlen(key);
	for(i=0;i<26;i++)
	{
		for(j=0;j<len;j++)
		{
			if(pt[i]==key[j])
			{
				key1[j]=ch[i];
			}
		}
	}
	printf("the encrypted string is\t %s\n",key1);
	for(i=0;i<26;i++)
	{
		for(j=0;j<len;j++)
		{
			if(ch[i]==key1[j])
			{
				key2[j]=pt[i];
			}
		}
	}
		printf("the decrypted string is\t %s",key2);
	
}
