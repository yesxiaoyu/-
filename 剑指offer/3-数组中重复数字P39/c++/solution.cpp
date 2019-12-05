// Author : lihongyu
// Time   : 2019-10-26

#include<bits/stdc++.h>
using namespace std;

//Using Index Array
//Time Complexity: O(n)
//Space Complexity: O(n)
void find_dulnum(int a[], int n){
	
	int idx[10] = {0};
	
	for(int i = 0; i < n; i++){
		idx[a[i]] += 1;
	}
	
	for(int i = 0; i < 10; i++){
		if(idx[i] > 1){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

// Using Array Index
// Time Complexity: O(n)
// Space Complexity: O(1)
// problem: Dul outputs
void find_dulnum_up(int a[], int n){
	
	if(n<2)	cout<<0<<endl;
	
	for(int i = 0; i < n; i++){
		while(a[i] != i){
			if(a[a[i]] == a[i]){
				cout<<a[i]<<" ";
				break;
			}
			else{
				swap(a[a[i]], a[i]);
			}
		}
	}
	
	cout<<endl;
}

int main(){
	
	int a[8] = {2, 3, 1, 0, 2, 5, 3, 3};
	
//	find_dulnum(a, 8);
	
	find_dulnum_up(a, 8);
	
	return 0;
} 
