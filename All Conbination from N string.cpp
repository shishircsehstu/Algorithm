class Solution {
public:
    
    vector<char>combination;
    vector<string>ansCombination;
    
    void allCombination(vector<string>vec,int indx){
        
        if(indx>=vec.size()){
            string str;
            for(int i=0;i<combination.size();i++){
                str+=combination[i];
                cout<<combination[i];
            }
            ansCombination.push_back(str);
            cout<<endl;
            return;
        }
        for(int i=0;i<vec[indx].size();i++){
            
            combination.push_back(vec[indx][i]);
            allCombination(vec,indx+1);
            combination.pop_back();
        }
    }
};


int main() {
    
    
    vector<string>st;
    st.push_back("abc");
    st.push_back("def");
    st.push_back("ghij");
    
    Solution ob;
    ob.allCombination(st, 0);
    
    return 0;
}
