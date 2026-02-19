int maxMin(int k, vector<int> arr) {

    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int minU = INT_MAX;
    
    for(int i = 0; i <= n - k; i++) {
        int unf = arr[i + k - 1] - arr[i];
        minU = min(minU, unf);
    }
    
    return minU;


}
