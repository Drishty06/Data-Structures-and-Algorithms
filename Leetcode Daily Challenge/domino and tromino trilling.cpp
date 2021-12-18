int numTilings(int n) {
        if (n < 3) return n;
        
        int mod = pow(10, 9) + 7;
        vector<long> D(n+1, 0), T(n+1, 0);
        D[0] = 0, D[1] = 1, D[2] = 2;
        T[0] = 0, T[1] = 1, T[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            D[i] = (D[i-1] + D[i-2] + 2*T[i-2]) % mod;
            T[i] = (T[i-1] + D[i-1]) % mod;
        }
        
        return D[n];
    }
