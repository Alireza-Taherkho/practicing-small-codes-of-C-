#include <iostream>
#include <cstdint>
#include <bitset>





int main(){

    constexpr std::uint32_t num{0xafc12460};

    constexpr std::uint32_t aa{0xFF000000};
    constexpr std::uint32_t bb{0x00FF0000};
    constexpr std::uint32_t cc{0x0000FF00};
    constexpr std::uint32_t dd{0x000000FF};

    std::cout << num << '\n';




    unsigned int aa8 {static_cast<unsigned int>(aa & num) >> 24};
    unsigned int bb8 {static_cast<unsigned int>(bb & num) >> 16};
    unsigned int cc8 {static_cast<unsigned int>(cc & num) >> 8};
    unsigned int dd8 {static_cast<unsigned int>(dd & num)};

    std::bitset<8> bit1{aa8};
    std::bitset<8> bit2{bb8};
    std::bitset<8> bit3{cc8};
    std::bitset<8> bit4{dd8};

    std::cout << bit1 << ' ' << bit2 << ' ' << bit3 << ' ' << bit4 << '\n';
    



    return 0;
}

