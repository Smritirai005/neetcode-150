class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum=0;
        int evensum=0;
        for(int i=1;i<=n;i++){
            oddsum += (2 * i - 1);
            evensum += (2 * i);
            
        }
        int ans=gcd(oddsum,evensum);

        return ans;
        
    }
};