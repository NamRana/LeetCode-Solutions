class Solution {
public:
    int takeCharacters(string s, int k) {
        int size=s.size();
        if(k==0)
            return 0;
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        int max_a=mp['a']-k,max_b=mp['b']-k,max_c=mp['c']-k,i=0,j=0,maxi=0;
        if(max_a<0 || max_b<0 || max_c<0)
            return -1;
        mp.clear();
        while(j<size){
            mp[s[j]]++;
            if(s[j]=='a'){
                while(mp[s[j]]>max_a){
                    mp[s[i]]--;
                    i++;
                }
            }
            else if(s[j]=='b'){
                while(mp[s[j]]>max_b){
                    mp[s[i]]--;
                    i++;
                }
            }
            else if(s[j]=='c'){
                while(mp[s[j]]>max_c){
                    mp[s[i]]--;
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return size-maxi;
    }
};