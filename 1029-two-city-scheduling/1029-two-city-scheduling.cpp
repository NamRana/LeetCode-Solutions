class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& nums) {   
        
        int ans=0;
        vector<int> d;
        
        for(int i=0;i<nums.size();i++){
            ans+=nums[i][0];
            d.push_back(nums[i][1]-nums[i][0]);
        }
        sort(d.begin(),d.end());
        
        for(int i=0;i<nums.size()/2;i++){
            ans+=d[i];
        }
        return ans;
    }
};