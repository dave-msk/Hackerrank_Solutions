#include <iostream>
#include <vector>

class BitNode {
    bool bit;
    BitNode* left;
    BitNode* right;
public:
    BitNode(bool bit) {
        this->bit = bit;
        left = 0;
        right = 0;
    }

    BitNode* getLeft() {return left;}
    BitNode* getRight() {return right;}
    void putLeft() {
        if (!left) left = new BitNode(0);
    }
    void putRight() {
        if (!right) right = new BitNode(1);
    }
};

class BinaryBitTree {
    BitNode* root0;
    BitNode* root1;
    int maxHeight;
public:
    BinaryBitTree(int height) {
        maxHeight = height;
        root0 = 0;
        root1 = 0;
    }

    void addBitSeq(long a) {
        BitNode* node;
        if ((a >> (maxHeight-1)) & 1) {
            if (!root1) root1 = new BitNode(1);
            node = root1;
        } else {
            if (!root0) root0 = new BitNode(0);
            node = root0;
        }
        for (int i = maxHeight-2; i >= 0; --i) {
            if ((a >> i) & 1) {
                node->putRight();
                node = node->getRight();
            } else {
                node->putLeft();
                node = node->getLeft();
            }
        }
    }

    int getMatchLength(long a) {
        BitNode * node;
        if ((a >> (maxHeight-1)) & 1) {
            if (!root1) return 0;
            node = root1;
        } else {
            if (!root0) return 0;
            node = root0;
        }
        int depth = 1;
        for (int i = maxHeight-2; i >= 0; --i) {
            if ((a >> i) & 1) {
                if (!node->getRight()) return depth;
                node = node->getRight();
            } else {
                if (!node->getLeft()) return depth;
                node = node->getLeft();
            }
            ++depth;
        }
        return depth;
    }

    long getMinXorValue(long a) {
        long result = 0;
        BitNode* node;
        if ((a >> (maxHeight-1)) & 1) {
            if (!root1) {
                node = root0;
                result = 1;
            } else {
                node = root1;
            }
        } else {
            if (!root0) {
                node = root1;
                result = 1;
            } else {
                node = root0;
            }
        }
        for (int i = maxHeight-2; i >= 0; --i) {
            result <<= 1;
            if ((a >> i) & 1) {
                if (node->getRight()) node = node->getRight();
                else {
                    ++result;
                    node = node->getLeft();
                }
            } else {
                if (node->getLeft()) node = node->getLeft();
                else {
                    ++result;
                    node = node->getRight();
                }
            }
        }
        return result;
    }
};

int main() {

    int n;
    std::cin >> n;
    long* arr = new long[n];
    long min = 1000000000, max = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }

    long num = min ^ max, a;
    int count = 0;
    while (num >> ++count);
    std::vector<long> set1, set2;
    for (int i = 0; i < n; ++i) {
        a = arr[i] & ((1l << count) - 1);
        if (a >> (count-1)) set1.push_back(a);
        else set2.push_back(a);
    }
    std::vector<long> *treeSet, *checkSet;
    if (set1.size() > set2.size()) {
        treeSet = &set1;
        checkSet = &set2;
    } else {
        treeSet = &set2;
        checkSet = &set1;
    }
    BinaryBitTree tree(count-1);
    for (std::vector<long>::size_type i = 0; i < treeSet->size(); ++i) {
        a = treeSet->at(i);
        tree.addBitSeq(a & ((1l << (count-1)) -1));
    }
    int maxLength = 0, matchLength;
    long aMaxMatch = 0;
    for (std::vector<long>::size_type i = 0; i < checkSet->size(); ++i) {
        a = checkSet->at(i);
        matchLength = tree.getMatchLength(a & ((1l << (count-1)) -1));
        if (matchLength > maxLength) {
            maxLength = matchLength;
            aMaxMatch = a & ((1l << (count-1)) -1);
        }
    }
    std::cout << (tree.getMinXorValue(aMaxMatch) + ((num) ? 1l << (count-1) : 0)) << std::endl;


    return 0;
}