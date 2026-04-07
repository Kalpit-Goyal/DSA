https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1?utm_medium=collab_striver_ytdescription&utm_campaign=bit-manipulation&utm_source=youtube

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int getIth=(num>>(i-1))&1;
        
        int setIth=num|(1<<(i-1));
        
        int clearIth=num & ~(1<<(i-1));
        
        cout<<getIth<<" "<<setIth<<" "<<clearIth;
    }
};
