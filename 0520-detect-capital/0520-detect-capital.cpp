class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        int n=word.size();
        int i=0;
         for(int i=0; i<n; i++){
             if(word[i]-'A'>=0 && word[i]-'A'<26){
             count++;
         }}
    if(count == n || 
       count == 0 || 
       count == 1 && word[0]>='A' && word[0]<='Z'){
        return true;
    }
            return false;
        
    }
};
