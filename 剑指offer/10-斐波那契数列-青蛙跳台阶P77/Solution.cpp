// Author : lihongyu
// Time   : 2019-10-26

#include<bits/stdc++.h>
using namespace std;

vector<long long> memo; 

long long Fibonacci(unsigned int n){
	if(n <= 0)	return 0;
	if(n == 1)	return 1;
	if(memo[n] == -1)	memo[n] = Fibonacci(n-1) + Fibonacci(n-2);
	return memo[n];
} 

int main(){
	
	unsigned int n;
	while(cin>>n){
		memo = vector<long long>(n+1, -1);
	
		cout<<Fibonacci(n)<<endl;
	}
	
	
	return 0;
} 
