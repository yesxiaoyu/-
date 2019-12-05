// Author : lihongyu
// Time   : 2019-10-26


//从右到左，从上到下
//Time Complexity: O(n)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;


void print_array_vec(int (*a)[4], int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool is_num_in_matrix(int a[][4], int m, int n, int t){
	 int r = 0, c = n - 1;
	 while(r < m && c >=0){
	 	if(t == a[r][c])	return true;
	 	else if(t < a[r][c])	c--;
	 	else	r++;
	 }
	 return false;
}

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int r = 0, c = array[0].size() - 1;
        while(r < array.size() && c >=0){
	 	if(target == array[r][c])	return true;
	 	else if(target < array[r][c])	c--;
	 	else	r++;
	 	}
	 return false;
    }
};

int main(){
//	int a[4][4] = { {1, 2, 8, 9},
//					{2, 4, 9, 12},
//					{4, 7, 10, 13},
//					{6, 8, 11, 15} };
	
	vector<vector<int> > a = { {1, 2, 8, 9},
					{2, 4, 9, 12},
					{4, 7, 10, 13},
					{6, 8, 11, 15} };
	
//	print_array_vec(a, 4, 4);
	
//	cout<<is_num_in_matrix(a, 4, 4, 17)<<endl;
	cout<<Solution().Find(11, a)<<endl;
	
	return 0;
}