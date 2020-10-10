

#include <stdio.h>
int first(int a[],int l,int r, int s)
{
    int mid = 0;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(s==a[mid])
        {
            if(s==a[mid - 1])
            {
                r = mid - 1;
                continue;
            }
            return mid;
        }
        else if(s<a[mid])
        {
            r = mid - 1;
        }
        else if(s>a[mid])
        {
            l = mid + 1;
        }
    }
    return -1;
}
int last(int a[],int l,int r, int s)
{
    int mid = 0;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(s==a[mid])
        {
            if(s==a[mid + 1])
            {
                l = mid + 1;
                continue;
            }
            return mid;
        }
        else if(s<a[mid])
        {
            r = mid - 1;
        }
        else if(s>a[mid])
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int a[10000],n,i,l,r,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&s);
    l = first(a,0,n,s);
    r = last(a,0,n,s);
    if(l!=-1||r!=-1)
    {
    printf("\n %d first occurence at %d",s,l);
    printf("\n %d last occurence at %d",s,r);
    printf("\n No of elements is : %d",r-l+1);
    }
    else
    {
        printf("Not found");
    }
    return 0;
}

