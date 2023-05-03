class Solution {
public:
    
    int lr(vector<int> &height){
        stack<int> st;
        int ma=0;
        int n=height.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || height[st.top()]>=height[i])){
                int h=height[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else width=i-st.top()-1;
                
                ma=max(ma,width*h);
            }
            st.push(i);
        }
        return ma;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxiarea=0,n=matrix.size(),m=matrix[0].size();
        vector<int> height(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            int area=lr(height);
        maxiarea=max(maxiarea,area);
        }
        return maxiarea;
    }
};