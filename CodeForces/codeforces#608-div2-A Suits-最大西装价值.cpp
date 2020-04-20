// Author : lihongyu
// Time   : 2019-12-15

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// codeforces#608-div2-A Suits-最大西装价值
// 思路：
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution{
public:
    int maxProfits(){
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        int maxValFLargeThanE = 0, maxValELargeThanF = 0;
        // maxValFLargeThanE
        int maxBNum = min(b, min(c, d));
        if (maxBNum > 0)
            maxValFLargeThanE = f * maxBNum;
        int dLeft = d - maxBNum;
        if (dLeft > 0)
            maxValFLargeThanE += min(a, dLeft) * e;
        // maxValELargeThanF
        int maxANum = min(a, d);
        if (maxANum > 0)
            maxValELargeThanF = e * maxANum;
        int dLeft2 = d - maxANum;
        if (dLeft2 > 0)
            maxValELargeThanF += min(min(b, c), dLeft2) * f;
        return max(maxValFLargeThanE, maxValELargeThanF);
    }
};

class Solution2{
public:
    int maxProfits(){
        fast
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        long ans=0;
        if(e>=f){
            ans=min(d,a)*e;
            d-=min(a,d);
            ans+=min(b,min(c,d))*f;
        }
        else{
            ans=min(d,min(b,c))*f;
            d-=min(min(d,b),c);
            ans+=min(a,d)*e;
        }
        return ans;
    }
};

// TODO：

int main(){

    cout << Solution().maxProfits() << endl;

    return 0;
}