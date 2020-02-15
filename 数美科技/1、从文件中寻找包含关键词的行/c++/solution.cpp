#include<bits/stdc++.h>
using namespace std;

//题目一.文件input.txt是一个文本文件，每一行有多列（用空格分隔）。keyword.conf是一个关键词配置文件，每一行是一个词。请找出文件input.txt中第一列包含keyword.conf中任意一个关键词的文本行并输出。（25）
//
//示例
//
//输入：
//
//文件input.txt内容：
//
//abc xxx
//
//bcd xxx
//
//def xxx
//
//xyz xxx
//
//文件keyword.conf内容：
//
//bc
//
//eft
//
//输出（打印到标准输出）：
//
//abc xxx
//
//bcd xxx
//
//作者：liust15
//链接：https://www.jianshu.com/p/fedcb1163fec
//来源：简书
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

void split(const string& s, vector<string>& sv, const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
    return;
}

int main(){

    fstream inputs("input.txt");
    fstream keywords("keyword.conf");

    vector<string> data;
    vector<string> key;
    vector<string> res;
    string line;

    while (getline(inputs, line)){
        data.push_back(line);
    }

    while (getline(keywords, line)){
        key.push_back(line);
    }

    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            vector<string> sv;
            split(data[i], sv);
            for (int k = 0; k < sv.size(); ++k) {
                if (sv[k].find(key[j]) != string::npos){
                    res.emplace_back(data[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout<<data[i]<<endl;
    }

    inputs.close();
    keywords.close();

    return 0;
}