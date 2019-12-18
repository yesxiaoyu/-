// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// lintcode-677 键值映射
// 思路：https://leetcode-cn.com/problems/map-sum-pairs/solution/qian-zhui-shu-by-hareyukai/
// 时间复杂度: O(n)
// 空间复杂度: O(1)

struct Trie {
    bool is_end;
    int val;
    unordered_map<char, Trie *> links;
    void insert(const string& word, const int val) {
        Trie *cur = this;
        for (const char ch : word) {
            if (!cur->links.count(ch)) cur->links.insert({ch, new Trie()});
            cur = cur->links[ch];
        }
        cur->val = val;
        cur->is_end = true;
    }

    int eval() {
        Trie *cur = this;
        int v = cur->is_end ? cur->val : 0;
        for (const auto& l : links)
            v += l.second->eval();
        return v;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }

    void insert(string key, int val) {
        root->insert(key, val);
    }

    int sum(string prefix) {
        Trie* node = root;
        for (const char ch : prefix) {
            if (!node->links.count(ch)) return 0;
            node = node->links[ch];
        }
        return node->eval();
    }
private:
    Trie* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// TODO：

int main(){
    auto *obj = new MapSum();

    obj->insert("apple", 3); // 输出: Null
    cout<<obj->sum("ap")<<endl; // 输出: 3
    obj->insert("app", 2); // 输出: Null
    cout<<obj->sum("ap")<<endl; // 输出: 5

    return 0;
}