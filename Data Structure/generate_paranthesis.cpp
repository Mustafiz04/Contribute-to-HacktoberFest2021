class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        backtrack(ans,"",0,0,n);
        return ans;
        
    }
    void backtrack(vector<string>&ans,string str,int open,int close,int max)
    {

    if(str.length()==2*max)
    {
    ans.push_back(str);
        return ;
    
    }
        if(open<max)
        {

        backtrack(ans,str+'(',open+1,close,max);
        }
        
         if(close<open)
        {

        backtrack(ans,str+')',open,close+1,max);
        }
    
    
    }
};
