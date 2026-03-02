class Solution {
  public:
 
    int findParent(int s, vector<int> &parent) {
        if (parent[s] == s) return s;
        return parent[s] = findParent(parent[s], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> jobs;  
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

      
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

        int jobCount = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int prof = job.first;
            int ddl  = job.second;

            int slot = findParent(ddl, parent);

            if (slot > 0) {
                jobCount++;
                totalProfit += prof;

               
                parent[slot] = findParent(slot - 1, parent);
            }
        }

        return {jobCount, totalProfit};
    }
};
