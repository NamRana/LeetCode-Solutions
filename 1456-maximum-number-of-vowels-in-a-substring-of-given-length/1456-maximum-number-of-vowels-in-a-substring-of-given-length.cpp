class Solution {
public:
    
    int is(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int mx=0,curv=0;
        for(int i=0;i<s.size();i++){
            curv+=(is(s[i]));
            if(i>=k){
                curv-=is(s[i-k]);
            }
            mx=max(mx,curv);
        }
        return mx;
    }
};