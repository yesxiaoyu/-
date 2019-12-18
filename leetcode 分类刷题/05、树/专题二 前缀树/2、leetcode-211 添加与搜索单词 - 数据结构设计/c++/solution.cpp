// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// lintcode-211 添加与搜索单词 - 数据结构设计
// 思路：https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/solution/c-shen-du-sou-suo-zi-dian-shu-di-gui-shi-xian-by-s/
// 时间复杂度: O(n)
// 空间复杂度: O(1)

struct Node{
    bool isWord = false;
    Node *next[26] = {};
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node * root;
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(int i = 0;root&&i<word.size();++i){
            if(p->next[word[i]-'a'] == nullptr){
                p->next[word[i]-'a'] = new Node();
            }
            p = p->next[word[i]- 'a'];
        }
        p->isWord  = true;
    }

    static bool dfs(Node* root, string word, int i){
        if(!root) return false;
        if(i>= word.size()) return root->isWord;
        if(word[i]!='.'){
            if(root->next[word[i]-'a'])
                return dfs(root->next[word[i]-'a'],word,i+1);
            else
                return false;
        }
        for (auto & j : root->next) {
            if(j && dfs(j, word, i+1)){
                return true;
            }
        }
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// TODO：

int main(){
    auto *obj = new WordDictionary();

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout<<obj->search("pad")<<endl; // -> false
    cout<<obj->search("bad")<<endl; // -> true
    cout<<obj->search(".ad")<<endl; // -> true
    cout<<obj->search("b..")<<endl; // -> true
    return 0;
}