#ifndef BIT_TOOLS_H
#define BIT_TOOLS_H

#include <bitset>

/*
 Namespace that contains all bit manipulation utilities.
*/
namespace bitTools
{
    std::bitset<8> setBit();     // Set one or more bits
    std::bitset<8> resetBit();   // Reset one or more bits
    std::bitset<8> flipBit();    // Flip one or more bits
    void testBit();              // Test a specific bit
    std::bitset<8> randomBit();  // Randomly flip bits
}

#endif
