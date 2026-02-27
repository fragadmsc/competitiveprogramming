//#include "algorithms/common.hpp"

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) : v((_v%MOD + MOD)%MOD) {}

    ModInt pow(long long e) const {
        ModInt res = 1, a = *this;
        while (e > 0) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    ModInt inv() const { return pow(MOD - 2); }

    ModInt operator+(const ModInt& o) const { return ModInt(v + o.v); }
    ModInt operator-(const ModInt& o) const { return ModInt(v - o.v); }
    ModInt operator*(const ModInt& o) const { return ModInt(v * o.v); }
    ModInt operator/(const ModInt& o) const { return *this * o.inv(); }
    

    ModInt& operator+=(const ModInt& o) { v = (v + o.v) % MOD; return *this; }
    ModInt& operator-=(const ModInt& o) { v = (v - o.v + MOD) % MOD; return *this; }
    ModInt& operator*=(const ModInt& o) { v = (v * o.v) % MOD; return *this; }
    ModInt& operator/=(const ModInt& o) { return *this = *this/o; }

    friend istream& operator>>(istream& is, ModInt& m) {
        long long x;
        is >> x;
        m = ModInt(x); 
        return is;
    }

    friend ostream& operator<<(ostream& os, const ModInt& m) {
        return os << m.v;
    }

};