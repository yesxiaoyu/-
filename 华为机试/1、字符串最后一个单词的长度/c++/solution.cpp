#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin, s)){
        int res = 0;
        for(int i = s.length()-1; i >=0; --i){
            if(!isspace(s[i]))    res++;
            else    break;
        }
        cout<<res<<endl;
    }
    return 0;
}
/*带Bug方式也可以过：）
string str;
while(cin >> str)	cout << str.size();
return 0;*/