long long digitSum(long long x) {
    if (x < 10)
        return x;
    
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    
    return digitSum(sum);
}

int superDigit(string n, int k) {
    long long initialSum = 0;

    for(char c : n) {
        initialSum += (c - '0');
    }
    
    initialSum *= k;
 
    return digitSum(initialSum);
}
