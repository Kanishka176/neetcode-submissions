class Solution {
public:
    bool isPalindrome(string s) {
        //bool ans=false;
        int n=s.size(), l=0, r=n-1, i=0;

    
        while(l<r){
            
            while(s[l]!=s[r] && !isalnum(s[l])){
                l++;
            }
            while(s[l]!=s[r] && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])){
                //ans=false;
                //break;
                return false;
            }
            else{
                l++;
                r--;
            }
            

        }
       

        return true;
    }
};
