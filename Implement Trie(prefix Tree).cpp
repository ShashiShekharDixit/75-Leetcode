#include <iostream>
using namespace std;

class TrieNode { 
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix == false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    cout << (trie.search("apple") ? "Found\n" : "Not Found\n");
    cout << (trie.search("app") ? "Found\n" : "Not Found\n");
    cout << (trie.search("banana") ? "Found\n" : "Not Found\n");
    cout << (trie.search("ban") ? "Found\n" : "Not Found\n");

    cout << (trie.startsWith("ap") ? "Yes\n" : "No\n");
    cout << (trie.startsWith("ban") ? "Yes\n" : "No\n");
    cout << (trie.startsWith("bat") ? "Yes\n" : "No\n");

    return 0;
}
