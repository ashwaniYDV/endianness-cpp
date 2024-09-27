#include <iostream>
#include <cstdint>

// Function to swap endianness using a built-in function (GCC/Clang)
uint32_t swapEndianness(uint32_t num) {
    return __builtin_bswap32(num);  // Built-in function to swap bytes
}

void test(uint32_t num) {
    std::cout << "Original number: 0x" << std::hex << num << "\n";
    uint32_t swappedNum = swapEndianness(num);
    std::cout << "After swapping endianness: 0x" << std::hex << swappedNum << "\n";
}

int main() {
    uint32_t num = 0x12345678;
    test(num);
    return 0;
}
