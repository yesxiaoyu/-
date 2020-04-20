// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// lintcode-208 实现 Trie (前缀树)
// 思路：
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)
			    root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)
			    return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)
			    return false;
			root = root->next[p - 'a'];
		}
		return true;
    }

private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// TODO：

int main(){
    Trie *trie = new Trie();

    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // 返回 true
    cout<<trie->search("app")<<endl;     // 返回 false
    cout<<trie->startsWith("app")<<endl; // 返回 true
    trie->insert("app");
    cout<<trie->search("app")<<endl;     // 返回 true
    return 0;
}