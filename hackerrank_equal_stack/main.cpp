#include <iostream>

int main(){
    int n1;
    int n2;
    int n3;
    std::cin >> n1 >> n2 >> n3;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    long height1 = 0;
    long* h1 = new long[n1];
    for(int h1_i = 0;h1_i < n1;h1_i++){
        std::cin >> h1[h1_i];
        height1 += h1[h1_i];
    }
    long height2 = 0;
    long* h2 = new long[n2];
    for(int h2_i = 0;h2_i < n2;h2_i++){
        std::cin >> h2[h2_i];
        height2 += h2[h2_i];
    }
    long height3 = 0;
    long* h3 = new long[n3];
    for(int h3_i = 0;h3_i < n3;h3_i++){
        std::cin >> h3[h3_i];
        height3 += h3[h3_i];
    }

    while (height1 != height2 || height1 != height3) {
        if (height1 >= height2 && height1 >= height3) height1 -= h1[idx1++];
        else if (height2 >= height1 && height2 >= height3) height2 -= h2[idx2++];
        else height3 -= h3[idx3++];
    }

    std::cout << height1 << std::endl;

    delete[] h1, h2, h3;

    return 0;
}