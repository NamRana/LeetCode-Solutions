class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        int res=0,n=s.size();
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(i==0){
                res=max(res,s[i]-bottom);
            }
            else{
                res=max(res,s[i]-s[i-1]-1);
            }
        }
        res=max(res,top-s[n-1]);
        return res;
    }
};