#pragma once

#include <vector>

struct sieve {
    private:
    using pii = std::pair<int, int>;
    int n;
    std::vector<std::vector<int>> divs;
    std::vector<bool> isp;
    std::vector<std::vector<pii>> prime_factorization;
    
    public:
    
    sieve(int _n) : n(_n) { }

    bool isprime(int x) {
        if((int)isp.size() != 0) return isp[x];
        
        isp.resize(n+1, true);
        for(int i = 2; i <= n; i++) {
            if(isp[i] == true) {
                for(int j = 2*i; j <= n; j += i) {
                    isp[j] = false;
                }
            }
        }

        return isp[x];
    }

    /*returns a std::vector of pair(prime factor, exponent)*/
    std::vector<pii> factorize(int x) {
        if((int)prime_factorization.size() != 0) return prime_factorization[x];

        prime_factorization.resize(n+1);
        for(int i = 2; i <= n; i++) {
            if((int)prime_factorization[i].size() == 0) {
                prime_factorization[i].push_back({i, 1});
                for(int j = 2*i; j <= n; j += i) {
                    int ax = 0, b = i;
                    while(j%b == 0) {
                        ax++;
                        b *= i;
                    }
                    prime_factorization[j].push_back({i, ax});
                }
            }
        }
        return prime_factorization[x];
    }

    std::vector<int> divisors(int x) {
        if((int)divs.size() != 0) return divs[x];

        divs.resize(n+1);
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                divs[j].push_back(i);
            }
        }

        return divs[x];
    }


};