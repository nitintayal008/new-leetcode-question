class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        int n=s1.size();
        int m=s2.size();
        if(n>m)return false;
        int left=0;
        int i=0;
        for(int i=0;i<n;i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++; 
        }
        for(int i=n; i<m; i++){
            if(hash1==hash2)return true;
            
            hash2[s2[left]-'a']--;
            hash2[s2[i]-'a']++;
            left++;
        }
        if(hash1==hash2)return true;
        return false;
        
    }
};