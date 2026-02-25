https://www.geeksforgeeks.org/problems/bits-basic-operations/1
// User function Template for C++

class Solution {
  public:
    int XOR(int n, int m) {
        // code here
        return (n^m);
    }

    int check(int a, int b) {
        
        // code here
        if(b&1<<(a-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

        
    int setBit(int c, int d) {
        // code here
        return (d|1<<c);
    }
};
