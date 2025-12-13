#include <iostream>
#include <cstdint>
#include <bitset>
#include <random>
#include <chrono>
#include "bitTools.h"

/*
 Stores the final result returned from bitTools operations.
*/
std::bitset<8> result{0b0000'0000};

/*
 Main control panel that receives user commands
 and calls the appropriate bitTools function.
*/
void Panel(){
    short request;        // User menu selection
    bool Finish {false};  // Exit flag

    while (true)
    {
        if (Finish == true){
            std::cout << "End Processing...\n";
            break;
        }

        // Validate menu input
        while (true){
            std::cin >> request;
            if (request <= 8 && request > 0)
                break;

            std::cout << "Try again: \n";
        }

        switch (request){
            case 1:
                result = bitTools::setBit();
                break;

            case 2:
                result = bitTools::resetBit();
                break;

            case 3:
                result = bitTools::flipBit();
                break;

            case 4:
                std::cout << result << '\n';
                break;

            case 5:
                bitTools::testBit();
                break;

            case 6:
                std::cout << "Operations:   Set = 1     Reset = 2     Flip = 3     Show All = 4     Show One = 5     Operations List = 6     Random Flip = 7     Exit = 8  ->\n";
                break;

            case 7:
                result = bitTools::randomBit();
                break;

            case 8:
                Finish = true;
                break;

            default:
                std::cout << "Try Again !\n";
                break;
        }
    }
}

/*
 Program entry point.
 Displays initial information and starts the panel.
*/
int main(){

    std::cout << "Your Bit number: 00000000\n";
    std::cout << "Operations:   Set = 1     Reset = 2     Flip = 3     Show All = 4     Show One = 5     Operations List = 6     Random Flip = 7     Exit = 8  ->\n";

    Panel();

    return 0;
}