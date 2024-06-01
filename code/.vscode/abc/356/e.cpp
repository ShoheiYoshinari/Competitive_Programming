#include <iostream>
#include <bitset>

const long long MOD = 998244353;

// Function to count the number of 1s in the binary representation of a number
int popcount(long long x) {
    return std::bitset<64>(x).count();
}

// Function to calculate the number of integers within [0, N] that have the k-th bit set
long long count_set_bits(long long N, int k) {
    long long block_size = 1LL << (k + 1);
    long long full_blocks = (N + 1) / block_size;
    long long remainder = (N + 1) % block_size;
    long long set_bits = full_blocks * (1LL << k);
    if (remainder > (1LL << k) - 1) {
        set_bits += remainder - (1LL << k) + 1;
    }
    return set_bits;
}

int main() {
    long long N, M;
    std::cin >> N >> M;
    
    long long total_sum = 0;

    // Iterate through each bit position of M
    for (int k = 0; k < 60; ++k) {
        if (M & (1LL << k)) {
            long long count = count_set_bits(N, k);
            total_sum = (total_sum + count) % MOD;
        }
    }

    std::cout << total_sum << std::endl;
    
    return 0;
}
