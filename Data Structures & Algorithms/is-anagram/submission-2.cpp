class Solution {
public:
    bool isAnagram(string s, string t) {
     unordered_map<char,int> s1;
     unordered_map<char,int> t1;
     int i=0,j=0;

     if(s.length()!=t.length()){
        return false;
     }

     while(s[i]!= '\0'){
        s1[s[i]]++;
        i++;
     }
     while(t[j]!= '\0'){
        t1[t[j]]++;
        j++;
     }
     if(s1==t1) return true;
     else return false;
    }
};
