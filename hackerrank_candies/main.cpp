#include <iostream>

int main() {
    long n, prevRate, rate;
    std::cin >> n;
    std::cin >> rate;
    bool sameCount = false;
    long lastCandy = 0;
    long decreCount = 1;
    long count = 0;
    for (long i = 1; i < n; ++i) {
        prevRate = rate;
        std::cin >> rate;
        if (prevRate > rate) {
            ++decreCount;
            if (sameCount) lastCandy = 1;
            sameCount = false;
        } else if (prevRate < rate) {
            if (sameCount) {
                count += 1;
                lastCandy = 1;
                decreCount = 1;
                sameCount = false;
                continue;
            }
            count += decreCount * (decreCount + 1)/2;
            if (lastCandy >= decreCount) count += lastCandy - decreCount + 1;

            if (decreCount == 1) ++lastCandy;
            else lastCandy = 1;
            decreCount = 1;
        } else {
            if (sameCount) {
                count += 1;
                lastCandy = 1;
            } else {
                sameCount = true;
                count += decreCount * (decreCount + 1)/2;
                if (lastCandy >= decreCount) count += lastCandy - decreCount + 1;
                if (decreCount == 1) ++lastCandy;
                else lastCandy = 1;
                decreCount = 1;
            }
        }
    }

    if (sameCount) count += 1;
    else {
        count += decreCount * (decreCount + 1)/2;
        if (lastCandy >= decreCount) count += lastCandy - decreCount + 1;
    }

    std::cout << count << std::endl;

    return 0;
}