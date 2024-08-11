class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         vector<pair<int,int>>v;
         for(int i = 0 ; i < profits.size() ; i++){
            int cap        = capital[i];
            int pureProfit = profits[i];

            v.push_back({cap,pureProfit});
         }
         sort(v.begin(),v.end());
         priority_queue<pair<int,int>>pq;
         int idx = 0;
         while(idx < v.size()){
              while(idx < v.size() and (w >= v[idx].first)){
                  pq.push({v[idx].second,v[idx].first});
                  idx++;
              }
              if(pq.size() == 0 or k == 0){
                  return w;
              }
              w+=pq.top().first;
              pq.pop();
              k--;
         }
         while(pq.size() > 0 and k > 0) {
            w+=pq.top().first;
            pq.pop();k--;
         }
         return w;
    }
};
