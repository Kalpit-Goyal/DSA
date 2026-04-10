https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

class Solution {
  public:
    int countSetBits(int n) {
        // code here
        if (n == 0) return 0;

        int x = log2(n);
        int bitsUpto2x = x * (1 << (x - 1));
        int msb2xToN = n - (1 << x) + 1;
        int rest = countSetBits(n - (1 << x));

        return bitsUpto2x + msb2xToN + rest;
    }
};
