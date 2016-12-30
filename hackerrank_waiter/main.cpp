#include <iostream>
#include <cmath>
#include <stack>

int getNextPrime(int currPrime) {
    if (currPrime < 2) return 2;
    ++currPrime;
    bool isPrime;
    while (1) {
        isPrime = true;
        for (int i = 2; i <= std::sqrt(currPrime); ++i)
            if (currPrime % i == 0) {isPrime=false; break;}
        if (isPrime) return currPrime;
        ++currPrime;
    }
}

int main() {

    int N, Q, value, prime = 1;
    std::cin >> N >> Q;
    std::stack<int> A1, A2;
    std::stack<int>* B = new std::stack<int>[Q];
    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        A1.push(value);
    }
    for (int i = 0; i < Q; ++i) {
        prime = getNextPrime(prime);
        if (i % 2 == 0) {
            while (!A1.empty()) {
                value = A1.top();
                if (value % prime == 0) B[i].push(value);
                else A2.push(value);
                A1.pop();
            }
        } else {
            while (!A2.empty()) {
                value = A2.top();
                if (value % prime == 0) B[i].push(value);
                else A1.push(value);
                A2.pop();
            }
        }
        while (!B[i].empty()) {
            std::cout << B[i].top() << std::endl;
            B[i].pop();
        }
    }
    if (A1.empty()) {
        while (!A2.empty()) {
            std::cout << A2.top() << std::endl;
            A2.pop();
        }
    } else {
        while (!A1.empty()) {
            std::cout << A1.top() << std::endl;
            A1.pop();
        }
    }

    return 0;
}