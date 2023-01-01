class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string,char>string2char;
        unordered_map<char,string>char2string;
        
        stringstream ss(s);
        string word;
        int pat=0;
        
        while(ss >> word){
            if(pat >= pattern.length()) return false;
            if(char2string.find(pattern[pat]) == char2string.end() and string2char.find(word) == string2char.end()){
                string2char[word]=pattern[pat];
                char2string[pattern[pat]]=word;
            }else if(char2string[pattern[pat]] != word || string2char[word] != pattern[pat]) return false;
            pat++;
        }
        if(pat != pattern.length()) return false;
        return true;
    }
};