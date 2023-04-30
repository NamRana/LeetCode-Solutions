class DSU{
    public:
    vector<int> Parent,Rank;
    
    DSU(int n){
        Parent.resize(n,0);
        Rank.resize(n,0);
        for(int i=0;i<n;i++){
            Parent[i]=i;
        }
    }
        
        int Find(int x){
            return Parent[x]=Parent[x]==x?x:Find(Parent[x]);
        }
        
        bool Union(int x,int y){
            int xset=Find(x),yset=Find(y);
            if(xset!=yset){
                Rank[xset]<Rank[yset]?Parent[xset]=yset:Parent[yset]=xset;
                Rank[xset]+=Rank[xset]==Rank[yset];
                return true;
            }
            return false;
        }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto const &a,auto const &b){
            return a[0]>b[0];
        });
        
        DSU dsua(n+1);
        DSU dsub(n+1);
        
        int removeedge=0,aliceedge=0,bobedge=0;
        for(auto edge:edges){
            if(edge[0]==3){
                if(dsua.Union(edge[1],edge[2])){
                    dsub.Union(edge[1],edge[2]);
                    aliceedge++;
                    bobedge++;
                }else{
                    removeedge++;
                }
            }
            else if(edge[0] == 2){ //Only Bob
                if(dsub.Union(edge[1], edge[2])){
                    bobedge++;
                }else{
                    removeedge++;
                }
            }
            else{
                if(dsua.Union(edge[1],edge[2])){
                    aliceedge++;
                }else{
                    removeedge++;
                }
            }
        }
        
        return (bobedge==n-1 && aliceedge==n-1)?removeedge:-1;
    }
};