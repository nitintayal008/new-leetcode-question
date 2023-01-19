class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans=0;
        int sum=0;
        int rem;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
                rem+=k;
            //we take care of this condition only that we if we get rem as negative 
            //then we will add k to that rem.
        if(mp.find(rem)!=mp.end()){
            ans+=mp[rem];
            mp[rem]++;
        }else{
            mp[rem]++;
        }
            //instead of this abpove  we can write this below code
         // if(mp.count(rem)) ans+=mp[rem];
         //    mp[rem]++;
        }
        
        return ans;
    }
};