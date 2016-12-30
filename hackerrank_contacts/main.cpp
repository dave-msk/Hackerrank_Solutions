#include <iostream>
#include <map>
#include <queue>

class Node {
    char content;
    bool wordMarker;
    long prefixCount;
    std::map<char,Node*> children;
public:
    Node() : content(' '), wordMarker(0), prefixCount(0) {}
    ~Node() {};
    char getContent() {return content;}
    void setContent(char content) {this->content = content;}
    bool isWordMarker() {return wordMarker;}
    void setWordMarker(bool wordMarker) {this->wordMarker = wordMarker;}
    long getPrefixCount() {return prefixCount;}
    void incrementPrefixCount() {++prefixCount;}
    void decrementPrefixCount() {--prefixCount;}
    Node* getChild(char c);
    void addChild(Node* child) {children[child->getContent()] = child;}
    void removeChild(char c) {children.erase(c);}
    bool hasChildren() {return !children.empty();}
    std::map<char,Node*> getChildren() {return children;}
};

class Trie {
    Node* root;
public:
    Trie() {root = new Node();}
    ~Trie() {delete root;}
    void addWord(std::string word);
    bool searchWord(std::string word);
    void deleteWord(std::string word);
    long countPrefix(std::string prefix);
};

Node* Node::getChild(char c) {
    auto it = children.find(c);
    return (it == children.end()) ? 0 : it->second;
}

void Trie::addWord(std::string word) {
    Node* node = root;
    if (word.size() == 0) {
        if (!root->isWordMarker()) {
            root->incrementPrefixCount();
            root->setWordMarker(true);
        }
        return;
    }
    for (std::string::size_type i = 0; i < word.size(); ++i) {
        node->incrementPrefixCount();
        if (!node->getChild(word[i])) {
            Node* tmp = new Node();
            tmp->setContent(word[i]);
            node->addChild(tmp);
            node = tmp;
        } else {
            node = node->getChild(word[i]);
        }
        if (i == word.size()-1) {
            node->incrementPrefixCount();
            node->setWordMarker(true);
        }
    }
}

bool Trie::searchWord(std::string word) {
    Node* node = root;
    if (word.size() == 0) return root->isWordMarker();
    for (std::string::size_type i = 0; i < word.size(); ++i) {
        if (!node->getChild(word[i])) return false;
        node = node->getChild(word[i]);
        if (i == word.size()-1) return node->isWordMarker();
    }
    return false;
}

void Trie::deleteWord(std::string word) {
    Node* node = root;
    if (word.size() == 0) {
        if (root->isWordMarker()) {
            root->decrementPrefixCount();
            root->setWordMarker(false);
        }
        return;
    }
    std::queue<Node*> q;
    for(std::string::size_type i = 0; i < word.size()-1; ++i) {
        q.push(node);
        if (!node->getChild(word[i])) return;
        node = node->getChild(word[i]);
        if (i == word.size()-2) {
            if (!node->getChild(word.back())) return;
            Node* tmp = node->getChild(word.back());
            if (tmp->hasChildren()) {
                q.push(tmp);
                tmp->setWordMarker(false);
            }
            else node->removeChild(word.back());
        }
    }
    while (!q.empty()) {
        node = q.front();
        q.pop();
        node->decrementPrefixCount();
    }
}

long Trie::countPrefix(std::string prefix) {
    Node* node = root;
    for (std::string::size_type i = 0; i < prefix.size(); ++i) {
        if (!node->getChild(prefix[i])) return 0;
        node = node->getChild(prefix[i]);
    }

    return node->getPrefixCount();
}

int main() {

    std::string command, value;
    long Q;
    Trie trie;
    std::cin >> Q;
    while (Q-- > 0) {
        std::cin >> command >> value;
        if (command == "add") trie.addWord(value);
        else if (command == "find") std::cout << trie.countPrefix(value) << std::endl;
    }
    return 0;
}