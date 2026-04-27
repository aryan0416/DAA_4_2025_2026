#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
    int n = deadline.size();

    vector<pair<int,int>> jobs(n);
    for (int i = 0; i < n; i++)
        jobs[i] = {profit[i], deadline[i]};
    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

    int maxDead = *max_element(deadline.begin(), deadline.end());

    
    vector<int> slot(maxDead + 1, -1);

    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int d = jobs[i].second;
        int p = jobs[i].first;

        
        for (int j = d; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i;       
                count++;
                totalProfit += p;
                break;
            }
        }
    }

    return {count, totalProfit};
}

int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit   = {20, 10, 40, 30};

    auto [jobs, prof] = jobSequencing(deadline, profit);
    cout << "Jobs: " << jobs << ", Profit: " << prof << endl;
 
    return 0;
}
