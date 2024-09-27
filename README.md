# endianness-cpp

##### What is Endianness?
* Endianness refers to the order in which bytes are stored in memory for `multi-byte data types` (e.g., `integers`). 
* There are 2 types of endianness:
  * `Little Endian`: The least significant byte (LSB) is stored first (at the lowest memory address).
  * `Big Endian`: The most significant byte (MSB) is stored first (at the lowest memory address).
* For example, consider the number 0x1234 (16-bit or 2-byte integer):
  * Big Endian: The memory will store it as 12 34.
  * Little Endian: The memory will store it as 34 12.

##### Endianness Check:
  * The function `isLittleEndian()` checks whether the system is little-endian by examining the byte ordering of a uint16_t variable.
  * If the least significant byte (LSB) is stored first in memory, it's little-endian.

##### Swapping Endianness:
  * The function `swapEndianness()` swaps the byte order of a 32-bit number.
  * It shifts and masks the bytes to rearrange them from little-endian to big-endian or vice versa.

##### Example:
 ```
System is Little Endian
Original number: 0x12345678
After swapping endianness: 0x78563412
```

##### Why unsigned int is taken in examples?
* In the example, uint32_t (unsigned 32-bit integer) is used for a few important reasons:
* The code uses bitwise shift `(<<, >>)` and bitwise AND `(&)` operations to manipulate the individual bytes of the number. These operations are more predictable and safer with unsigned integers. Signed integers may introduce complications because they use two's complement representation, which can lead to unexpected results during bit shifts, especially when shifting negative numbers.
* Endianness refers to how bytes are stored in memory. It doesn't distinguish between positive and negative values—it’s simply a matter of byte order. Using unsigned integers allows you to focus purely on the byte manipulation without worrying about signedness affecting the representation. For example, 0xAABBCCDD could represent various values in signed form, but in unsigned form, it's treated as just the raw bits: 10101010101110111100110011011101.
* When working with hexadecimal literals (e.g., 0x12345678 or 0xAABBCCDD), these numbers are more intuitively treated as unsigned, since hexadecimal values are often used to represent raw binary data without considering whether they are positive or negative. In our case, these are fixed-width 32-bit numbers, and using unsigned ensures they are interpreted as 32-bit quantities, not potential negative numbers.
