class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int ans=0;
       // sort(tasks.begin(),tasks.end());
        for(int i=0;i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            int k=it.second;
            if(k==1)return -1;
            if(k%3==0)
            ans+=k/3;
            else 
            ans+=(k/3)+1;
        }
            
        return ans;
     }
 
};
