
https://leetcode-cn.com/problems/friend-circles/solution/bing-cha-ji-jian-dan-cu-bao-shuang-98-by-sky-148/

class Solution {
public:
    int *fa;
    int findCircleNum(vector<vector<int>>& M) {
        int res=0;
        fa=new int[M.size()+10];//这一步忘了，懵逼了好半天
        for(int i=1;i<=M.size();++i)
        {
            fa[i]=i;
        }
        for(int i=0;i<M.size();++i)
            for(int j=0;j<M.size();++j)
            {
                if(M[i][j]==1)
                merge(i+1,j+1);
            }
            for(int i=1;i<=M.size();++i)
            {
                if(fa[i]==i)
                    res++;
            }
           
            return res;

    }
    int find(int x)
    {
        int root=x,temp;
        while(root!=fa[root])
        root=fa[root];
        while(x!=fa[x])
        {
            temp=fa[x];
            fa[x]=root;
            x=temp;
        }
        return root;
    }
    void merge(int x,int y)
    {
        int X=find(x);
        int Y=find(y);
        fa[X]=Y;
        return;
    }
    
};