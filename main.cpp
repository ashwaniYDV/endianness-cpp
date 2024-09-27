#include <iostream>
#include <cstdint>

// Function to check system endianness
/*
uint16_t num = 0x0001;:
    Here, a 16-bit unsigned integer num is initialized with the value 0x0001. 
    This means the least significant byte (LSB) is 1 and the most significant byte (MSB) is 0.
char* byte = (char*)&num;:
    This line takes the address of num (a uint16_t variable) and casts it to a char*. 
    This is done because: a char in C++ is always 1 byte (8 bits), and inspecting memory byte-by-byte is easier when dealing with char pointers.
    Now byte[0] will point to the first byte of the 2-byte num.
return (byte[0] == 1);:
    If the first byte (byte[0]) contains 1, the system is little-endian. 
    This is because in little-endian systems, the least significant byte (which is 1 in 0x0001) is stored first in memory.
    If the system were big-endian, byte[0] would contain 0 because the most significant byte would be stored first in memory.

Note: Apple machines are little-endian
*/
bool isLittleEndian() {
    uint16_t num = 0x0001;
    // Cast the address of num to a char pointer to inspect byte order
    char* byte = (char*)&num;
    // If the first byte is 1, it's little-endian
    return (byte[0] == 1);
}

// Function to swap endianness (Little <-> Big)
/*
The goal is to rearrange the bytes of the 32-bit number by moving the least significant byte (LSB) to the most significant byte (MSB) and vice versa.

Example:
--------
Let's assume num = 0x12345678. 

In memory (little-endian):
It is represented as:
0x78  0x56  0x34  0x12

The function swaps these bytes to produce:
0x12  0x34  0x56  0x78  (big-endian)


Here’s how each line works:
--------------------------
(num >> 24) & 0x000000FF:
    num >> 24: Shift the 32-bit number right by 24 bits, moving the 4th byte (MSB) to the least significant byte (LSB) position.
    & 0x000000FF: Mask off the upper 3 bytes, leaving only the LSB. This moves the 4th byte to the 1st byte.
    For 0x12345678, this results in 0x00000012.
    
(num >> 8) & 0x0000FF00:
    num >> 8: Shift the 32-bit number right by 8 bits, moving the 3rd byte to the 2nd byte position.
    & 0x0000FF00: Mask off the surrounding bytes, leaving only the 2nd byte.
    For 0x12345678, this results in 0x00003400.

(num << 8) & 0x00FF0000:
    num << 8: Shift the 32-bit number left by 8 bits, moving the 2nd byte to the 3rd byte position.
    & 0x00FF0000: Mask off the unwanted bits, leaving only the 3rd byte.
    For 0x12345678, this results in 0x00560000.

(num << 24) & 0xFF000000:
    num << 24: Shift the 32-bit number left by 24 bits, moving the 1st byte to the 4th byte position.
    & 0xFF000000: Mask off the lower 3 bytes, leaving only the MSB.
    For 0x12345678, this results in 0x78000000.
*/
uint32_t swapEndianness(uint32_t num) {
    return ((num >> 24) & 0x000000FF) |  // Move the 1st byte to the 4th byte
           ((num >> 8) & 0x0000FF00) |   // Move the 2nd byte to the 3rd byte
           ((num << 8) & 0x00FF0000) |   // Move the 3rd byte to the 2nd byte
           ((num << 24) & 0xFF000000);   // Move the 4th byte to the 1st byte
}


void test(uint32_t num) {
    // Print the original number
    std::cout << "Original number: 0x" << std::hex << num << "\n";

    // Swap the endianness
    uint32_t swappedNum = swapEndianness(num);

    // Print the swapped number
    std::cout << "After swapping endianness: 0x" << std::hex << swappedNum << "\n\n";
}

int main() {
    // Check system endianness
    if (isLittleEndian()) {
        std::cout << "System is Little Endian\n\n";
    } else {
        std::cout << "System is Big Endian\n\n";
    }

    uint32_t num = 0x12345678; // Example number in hex
    test(num);

    num = 0xAABBCCDD;
    test(num);
    

    return 0;
}
