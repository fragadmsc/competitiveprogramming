#pragma once

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
    bool operator ==(const ModInt& o) const { return v == o.v; }
    bool operator !=(const ModInt& o) const { return v != o.v; }
    

    ModInt& operator+=(const ModInt& o) { v = (v + o.v) % MOD; return *this; }
    ModInt& operator-=(const ModInt& o) { v = (v - o.v + MOD) % MOD; return *this; }
    ModInt& operator*=(const ModInt& o) { v = (v * o.v) % MOD; return *this; }
    ModInt& operator/=(const ModInt& o) { return *this = *this/o; }
    ModInt& operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    ModInt operator++(int) {
        ModInt temp = *this;
        ++(*this); 
        return temp;
    }
    ModInt& operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    ModInt operator--(int) {
        ModInt temp = *this;
        --(*this);
        return temp;
    }


    explicit operator long long() const { return v; }
    explicit operator int() const { return static_cast<int>(v); }

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

using m98 = ModInt<998244353>;
using m10 = ModInt<(int)(1e9 + 7)>;
