class Solution {
public:
    int len;
    vector<int>ans;
    vector<int> splitIntoFibonacci(string num) 
    {
        len=num.length();
        int idx=0;
        vector<int>v;
        fun(idx,num,v);
        return ans;
    }
    void fun(int idx,string &nums,vector<int>&v)
    {
       if(idx >= nums.length())
       {
            if(v.size() > 2)
            {
                 ans=v;
            }

            return;
       }

       long long int num=0;
       string str="";

       for(int i=idx;i<nums.length();i++)
       {
           char ch = nums[i];
           num = (num * 10LL) + ch-'0';
           str.push_back(ch);

           if(str.length() > (len/2) or (num>INT_MAX))
           {
               return;
           }
           //checking for the leading zeros
           if(str.length()>0 and str[0]=='0' and num>0)       // 005
           {
              return; 
           }

           if(v.size()<2)   //0 1
           {
               v.push_back(num);
               fun(i+1,nums,v);

               if(ans.size()!=0)
               return;

               v.pop_back();  
           }
           else if(v.size() >= 2)
           {
               long long temp_sum=0LL+v[v.size()-1]+v[v.size()-2];
               if(num < temp_sum)
               {
                   continue;
               }
               else if(num > temp_sum)
               {
                  return;
               }
               if(num == temp_sum)
               {
                   v.push_back(num);
                   fun(i+1,nums,v);

                   if(ans.size()!=0)
                   return;

                   v.pop_back();
               }
           }
       }
    }
};
