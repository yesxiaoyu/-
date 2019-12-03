#include<bits/stdc++.h>
using namespace std;

//题目二****. input.txt中有10万个随机整数，每行一个，范围从0-99999，
// 需要分别统计[0-99]、[100-199]、[200-299]、[300-399] …… [99900, 99999]，出现的次数。
// 输出为每个范围及其中数字出现的次数，范围和数字间空格分隔，每行一个。（20）
//
//示例：
//
//输入文件input.txt:
//
//123
//12
//5
//123
//…
//
//输出（打印到标准输出）：
//
//0-99 26
//100-199 128
//200-299 3
//
//作者：liust15
//链接：https://www.jianshu.com/p/fedcb1163fec
//来源：简书
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){

    fstream inputs("inputs.txt");
    string line;
    vector<int> times = vector<int>(1000+1, 0);

    while (getline(inputs, line)){
        times[stoi(line)/100] += 1;
    }

    for (int i = 0; i < times.size(); i++) {
        cout<< i * 100 << "-" << i * 100 + 99 << " " << times[i]<<endl;
    }

    inputs.close();

    return 0;
}