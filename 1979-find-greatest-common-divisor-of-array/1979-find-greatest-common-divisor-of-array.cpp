class Solution {
public:
    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    
    int findGCD(vector<int>& nums) {
       int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        int ans=gcd(maxi,mini);
        return ans;
    }
};