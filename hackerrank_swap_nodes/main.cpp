#include <vector>
#include <stack>
#include <queue>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int input_data) : data(input_data), left(0), right(0) {}
    ~Node() {
        if (left) delete left;
        if (right) delete right;
    }
};

void inOrder(Node* root) {
    if (!root) return;
    std::stack<Node*> stk;
    Node* ptr = root;
    while (true) {
        if (ptr->left) {
            stk.push(ptr);
            ptr = ptr->left;
            continue;
        }
        std::cout << ptr->data << " ";

        if (ptr->right) {
            ptr = ptr->right;
            continue;
        }

        while (!stk.empty() && !stk.top()->right) {
            ptr = stk.top();
            std::cout << ptr->data << " ";
            stk.pop();
        }
        if (stk.empty()) break;
        ptr = stk.top()->right;
        std::cout << stk.top()->data << " ";
        stk.pop();
    }
    std::cout << std::endl;
}

void swapNodes(Node* root, int k) {
    std::queue<Node*> q;
    q.push(root);
    Node* n, *tmp;
    int depth = 1, count = 1, N;
    while (!q.empty()) {
        N = count;
        count = 0;
        if (depth % k == 0) {
            for (int i = 0; i < N; ++i) {
                n = q.front();
                tmp = n->left;
                n->left = n->right;
                n->right = tmp;
                if (n->left) {
                    ++count;
                    q.push(n->left);
                }
                if (n->right) {
                    ++count;
                    q.push(n->right);
                }
                q.pop();
            }
        } else {
            for (int i = 0; i < N; ++i) {
                n = q.front();
                if (n->left) {
                    ++count;
                    q.push(n->left);
                }
                if (n->right) {
                    ++count;
                    q.push(n->right);
                }
                q.pop();
            }
        }
        ++depth;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, L, R, T, k;
    std::cin >> N;
    Node* root = new Node(1);
    std::vector<Node*> v;
    v.push_back(root);
    Node* n;
    for (int i = 0; i < N; ++i) {
        std::cin >> L >> R;
        if (L != -1) {
            n = new Node(L);
            v.push_back(n);
            v[i]->left = n;
        }
        if (R != -1) {
            n = new Node(R);
            v.push_back(n);
            v[i]->right = n;
        }
    }
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        std::cin >> k;
        swapNodes(root, k);
        inOrder(root);
    }
    return 0;
}
