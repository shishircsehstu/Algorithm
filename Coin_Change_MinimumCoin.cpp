class Solution {
public:
    int level[10004];
    
    int DFS(vector<int>& coins, int amount){
        queue<int>myQueue;
        myQueue.push(amount);
        while (!myQueue.empty()) {
            int font = myQueue.front();
            myQueue.pop();
            if(font==0){
                return level[font];
            }
            
            for(int i=0;i<coins.size();i++){
                int newAmount = font-coins[i];
                if(newAmount>=0 && level[newAmount]==0){
                    myQueue.push(newAmount);
                    level[newAmount] = level[font]+1;
                      if(newAmount == 0){
                        return  level[newAmount];
                    }
                }
            }
        }
        return  -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        return DFS(coins,amount);
    }

};
