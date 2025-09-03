class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>ans(m+n);
        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                i++;
                k++;
            }
            else{
                ans [k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<m){
            ans[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n){
            ans[k]=nums2[j];
            j++;
            k++;
        }
        if(ans.size()%2==0){
            return (ans[ans.size()/2]+ans[(ans.size()/2)-1])/2.0;

        }
        else{
            return ans[ans.size()/2];
        }
        
        
        
    }
};