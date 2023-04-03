class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        int n = s.size();
        if(n<=10){
            return ans;
        }
        for(int i=0; i<=n-10;i++){
            string str = s.substr(i ,10);
            mp[str]++;
        }
        for(auto itr=mp.begin();itr!=mp.end(); itr++){
            if(itr->second>1){
                ans.push_back(itr->first);
            }
        }
        return ans;
    }
};