// Author : lihongyu
// Time   : 2019-11-01

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0,  r = rotateArray.size() - 1;
        int m = l;
        while(r >= l){
        	if(r - l == 1){
        		m = r;
        		break;
			}
        	m = (l + r) / 2;
        	
        	//如果l, m, r指向的三个数相等，则只能顺序查找
			
			if(rotateArray[l] == rotateArray[r] 
				&& rotateArray[m] == rotateArray[l])
				return MinInOrder(rotateArray, l, r);
			if(rotateArray[m] >= rotateArray[l])
				l = m;
			else if(rotateArray[m] <= rotateArray[r])
				r = m;
		}
		return rotateArray[m];
    }
    
    int MinInOrder(vector<int> rotateArray, int l, int r){
    	int res = rotateArray[l];
    	for(int i = l + 1; i <= r; i++){
    		if(res > rotateArray[i])	res = rotateArray[i];	
		}
		return res;
	}
};

int main(){
	
	vector<int> rotatedArray = {3, 4, 5, 1, 2};
	
	cout<<Solution().minNumberInRotateArray(rotatedArray)<<endl; 
	
	return 0;
} 
