#include <iostream>
#include <cstdint>
#include <bitset>



std::string_view formatBinary(std::uint32_t x){

    constexpr std::uint32_t aa{0xFF000000};
    constexpr std::uint32_t bb{0x00FF0000};
    constexpr std::uint32_t cc{0x0000FF00};
    constexpr std::uint32_t dd{0x000000FF};

    std::cout << "main number: " << x << '\n';


    unsigned int aa8 {static_cast<unsigned int>(aa & x) >> 24};
    unsigned int bb8 {static_cast<unsigned int>(bb & x) >> 16};
    unsigned int cc8 {static_cast<unsigned int>(cc & x) >> 8};
    unsigned int dd8 {static_cast<unsigned int>(dd & x)};

    std::bitset<8> bit1{aa8};
    std::bitset<8> bit2{bb8};
    std::bitset<8> bit3{cc8};
    std::bitset<8> bit4{dd8};


    std::string strv1{bit1.to_string()};
    std::string strv2{bit2.to_string()};
    std::string strv3{bit3.to_string()};
    std::string strv4{bit4.to_string()};

    std::string_view result = strv1 + ' ' + strv2 + ' ' + strv3 + ' ' + strv4;
    std::cout << "transformed to binary type: ";
    
    return result;

    
}


int main(){



    std::cout << formatBinary(102154120);


    return 0;
}

