https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int xorall=0;
        for(int i=0;i<arr.size();i++){
            xorall^=arr[i];
        }
        int rightmost=(xorall&(xorall-1))^xorall;
        int buck1=0;
        int buck2=0;
        for(int i=0;i<arr.size();i++){
            if((arr[i]|rightmost)==arr[i]){
                buck1^=arr[i];
            }
            else{
                buck2^=arr[i];
            }
        }
        if(buck1 < buck2){
    swap(buck1, buck2);
}
        return {buck1,buck2};
    }
};
