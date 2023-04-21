class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        
        while(l<r){
            int mid=(l+r)>>1;
            
            int current=0;
            int split=1;
            
            for(int i=0;i<nums.size();i++){
                if(current+nums[i]>mid){
                    current=0;
                    split++;
                }
                current+=nums[i];
            }
            
            if(split>k)l=mid+1;
            
            else r=mid;
        }
        
        return l;
    }
};