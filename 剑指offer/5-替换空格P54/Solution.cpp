// Author : lihongyu
// Time   : 2019-10-27
#include<bits/stdc++.h>
using namespace std;

//Using If
//Time Complexity: O(n2)
//Space Complexity: O(n)

class Solution {
public:
	void replaceSpace(char *str,int length) {
//		for(int i = 0; i < length; i++){
//			
//			if(str[i] == ' '){
//				for(int j = length+2; j > i; j--){
//					str[j] = str[j-2];
//				}
//				length += 2;
//				str[i++] = '%';
//				str[i++] = '2';
//				str[i] = '0';
//			}
//			
//		} 
		int i = 0;
		while(str[i] != '\0'){
			if(str[i] == ' '){
				for(int j = length + 2; j > i; j--){
					str[j] = str[j-2];
				}
				length += 2;
				str[i++] = '%';
				str[i++] = '2';
				str[i++] = '0';
			}else{
				i++;
			}
		} 
	}
};

class Solution2 {
public:
	void replaceSpace(char *str,int length) {
		int space_num = 0;
		for(int i = 0; i < length; i++){
			if(str[i] == ' '){
				space_num++;
			}
		}
		int res_len = length + 2*space_num;
		
		int p1 = length, p2 = res_len;
		while(p1 >= 0){ // bug error: p1 != 0
			if(str[p1] == ' '){
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
				p1--;
			}else{
				str[p2--] = str[p1--];
			}
		}
	}
};

int main(){
	
	char str[14] = {'W', 'e', ' ', 'a', 'r', 'e', ' ', 'h', 'a', 'p', 'p', 'y', '.', '\0'};
	
	Solution2().replaceSpace(str, 14);
	
	int i = 0;
	while(str[i] != '\0'){
		cout<<str[i++]<<" ";
	}
	cout<<endl;
	
	return 0;
}
