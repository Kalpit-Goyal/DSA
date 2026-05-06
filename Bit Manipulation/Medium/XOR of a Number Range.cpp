https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_medium=collab_striver_ytdescription&utm_campaign=find-xor-of-numbers-from-l-to-r&utm_source=youtube

int doxor(int n){
    if(n%4==1){
        return 1;
    }
    if(n%4==2){
        return n+1;
    }
    if(n%4==3){
        return 0;
    }
    if(n%4==0){
        return n;
    }
    return 0;
}
class Solution {
  public:
    int findXOR(int l, int r) {
        int full=doxor(r);
        int half=doxor(l-1);
        int ans=half^full;
        return ans;
    }
};
