#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define llu long long unsigned
#define INF INT_MAX
#define SINF 1e18
#define pb push_back
#define mod 1000000007
#define PI 3.1415926535897932384626433832795

set<vector<int>> ans;

 bool check(vector<vector<int>> &v,int x,int y,int n){
     bool flag=true;
     for(int i=0;i<n;i++){if(v[x][i]==1){flag=false;break;}}
     for(int i=0;i<n;i++){if(v[i][y]==1){flag=false;break;}}
     int i=x,j=y;
     while(i>=0 and i<n and j>=0 and j<n and flag==true){
         if(v[i][j]==1){flag=false;break;}
         i-=1;j-=1;
     }i=x;j=y;
     while(i>=0 and i<n and j>=0 and j<n and flag==true){
         if(v[i][j]==1){flag=false;break;}
         i+=1;j+=1;
     }i=x;j=y;
     while(i>=0 and i<n and j>=0 and j<n and flag==true){
         if(v[i][j]==1){flag=false;break;}
         i-=1;j+=1;
     }i=x;j=y;
     while(i>=0 and i<n and j>=0 and j<n and flag==true){
         if(v[i][j]==1){flag=false;break;}
         i+=1;j-=1;
     }
     return flag;
 }

void helper(int k,vector<vector<int>> &v,int n,int row){
    if(k==0){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(v[i][j]);
            }
        }
        ans.insert(temp);
        return;
    }
    int i=row;
    for(int j=0;j<n;j++){
        if(v[i][j]==0 and check(v,i,j,n)){
            v[i][j]=1;
            helper(k-1,v,n,row+1);
            v[i][j]=0;
        }
    }
    return;
}

void placeNQueens(int n){
    vector<vector<int>> v(n,vector<int>(n,0));
    helper(n,v,n,0);
    set <vector<int>> :: iterator itr;
    for(itr=ans.begin();itr!=ans.end();itr++){
        for(int j=0;j<(*itr).size();j++){
            cout<<(*itr)[j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    //////////////
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif
    /////////////
    int n=4;
    //make sure that n is within 10 i.e. 1<=n<=10
    placeNQueens(n);
    return 0;
}