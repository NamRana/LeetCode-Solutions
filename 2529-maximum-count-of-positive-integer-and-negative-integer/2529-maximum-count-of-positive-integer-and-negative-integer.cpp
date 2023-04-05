class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int p=0,q=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                p++;
            }
            else if(nums[i]<0){
                q++;
            }
        }
        if(p>q)return p;
        return q;
    }
};