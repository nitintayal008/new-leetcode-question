class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int m=strs.size();
        int n=strs[0].size();
       // vector<string>temp;
        for(int i=0;i<n; i++){
            string temp="";
            for(int j=0;j<m;j++){
                temp+= strs[j][i];
            }
            string rev=temp;
            sort(temp.begin(),temp.end());
            if(rev!=temp){
                count++;
            }
        }
        
        return count;
    }
};
