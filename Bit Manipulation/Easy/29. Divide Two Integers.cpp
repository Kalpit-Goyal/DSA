https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long)(dividend));
        long long dvs = llabs((long long)(divisor));
        long long quotient = 0;

        while (dvs <= dvd) {
            long long multiple = 1;
            long long temp = dvs;
            while ((temp << 1) <= dvd) {
                multiple=multiple << 1;
                temp=temp << 1;
            }
            dvd -= temp;
            quotient += multiple;
        }
        if (negative) {
            quotient = -quotient;
        }
        return int(quotient);
    }
};
