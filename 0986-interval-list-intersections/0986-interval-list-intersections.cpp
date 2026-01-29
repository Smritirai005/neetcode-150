class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>>ans;
        int n=firstList.size();
        int m=secondList.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            int s1=firstList[i][0];
            int e1=firstList[i][1];
            int s2=secondList[j][0];
            int e2=secondList[j][1];
            if(s1<s2){
                if(e1>=s2){
                    s1=max(s1,s2);
                    e1=min(e1,e2);
                    ans.push_back({s1,e1});
                }
            }
            else{
                if(e2>=s1){
                    ans.push_back({max(s1, s2), min(e1, e2)});
                }
            }
            if(e1<e2)i++;
            else j++;
        }
        return ans;
        
    }
};