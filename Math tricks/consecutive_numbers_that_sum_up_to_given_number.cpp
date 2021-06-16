long int countConsecutive(long int N)
{
    // constraint on values of L gives us the
    // time Complexity as O(N^0.5)
    long int count = 0;
    for (long int L = 1; L * (L + 1) < 2 * N; L++) {
        float a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
        if (a - (int)a == 0.0)
            count++;
    }
    return count;
}
// for more info: https://www.geeksforgeeks.org/count-ways-express-number-sum-consecutive-numbers/
