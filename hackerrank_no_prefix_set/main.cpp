#include <iostream>
#include <map>

class Node {
    char content;
    bool wordMarker;
    std::map<char, Node*> children;
public:
    Node() : content(' '), wordMarker(false){}
    ~Node(){}
    char getContent() {return content;}
    void setContent(char content) {this->content = content;}
    bool isWordMarker() {return wordMarker;}
    void setWordMarker() {wordMarker = true;}
    void addChild(Node* child) {children[child->getContent()] = child;}
    bool hasChildren() {return !children.empty();}
    Node* getChild(char c) {
        auto it = children.find(c);
        return (it == children.end()) ? 0 : it->second;
    }
};

class Trie {
    Node* root;
public:
    Trie() : root(new Node()){}
    ~Trie() {delete root;}
    bool addWord(std::string word);
};

bool Trie::addWord(std::string word) {
    Node* node = root;
    for (std::string::size_type i = 0; i < word.size(); ++i) {
        if (node->isWordMarker()) return false;
        if (!node->getChild(word[i])) {
            Node* tmp = new Node();
            tmp->setContent(word[i]);
            node->addChild(tmp);
            node = tmp;
        } else {
            node = node->getChild(word[i]);
        }
        if (i == word.size()-1) {
            if (node->isWordMarker() || node->hasChildren()) return false;
            node->setWordMarker();
        }
    }
    return true;
}

int main() {
    long N;
    std::string line;
    std::cin >> N;
    Trie trie;
    for (long i = 0; i < N; ++i) {
        std::cin >> line;
        if (!trie.addWord(line)) {
            std::cout << "BAD SET" << std::endl;
            std::cout << line << std::endl;
            return 0;
        }
    }
    std::cout << "GOOD SET" << std::endl;
    return 0;
}