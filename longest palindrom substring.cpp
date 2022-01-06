class Solution {
public:
     string longPalindrom;
    int maxLength = 0;
    int isPalindrom(string s, int low, int high){
        
        int count=0;
        while ((low>=0 && high<s.size() && s[low]==s[high])) {
            count+=1;
            int length = high-low+1;
            if(length>maxLength){
                
                maxLength = length;
                longPalindrom.clear();
                int i;
                
                for(i=low;i<=high;i++){
                   
                    longPalindrom+=s[i];
                }
                
            }
            low--, high++;
        }
        return count;
    }
    
    string longestPalindrome(string s) {
        int totalPalindrom = 0;
        int n=s.size();
        for(int i=0;i<n;i++){
            totalPalindrom+=isPalindrom(s,i,i);
            totalPalindrom+=isPalindrom(s,i,i+1);
        }
        return longPalindrom;
    }
};
