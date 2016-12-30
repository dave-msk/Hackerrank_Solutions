#include <iostream>

class Hackonacci {
    const bool hackons[7] = {false, false, true, false, true, true, false};
    long* orientationCount;

    bool getElement(long i, long j) {
        return hackons[(i*i*j*j) % 7];
    }

    bool isDifferent(long i1, long j1, long i2, long j2) {
        return getElement(i1, j1) != getElement(i2, j2);
    }
public:
    Hackonacci(long n) {

        orientationCount = new long[3]{0};

        for (long i = 1; i <= n; ++i) {
            for (long j = 1; j <= n; ++j) {
                if (isDifferent(i,j,j,n-i+1)) ++orientationCount[0];
                if (isDifferent(i,j,n-i+1,n-j+1)) ++orientationCount[1];
                if (isDifferent(i,j,n-j+1,i)) ++orientationCount[2];
            }
        }
    }

    long getCount(long orientation) {
        orientation = (orientation/90) % 4;
        if (orientation == 0) return 0;
        else return orientationCount[orientation-1];
    }
};

int main() {

    long n, q, orientation;
    std::cin >> n >> q;
    Hackonacci hackonacci(n);
    for (long i = 0; i < q; ++i) {
        std::cin >> orientation;
        std::cout << hackonacci.getCount(orientation) << std::endl;
    }

    return 0;
}