#include <iostream>
#include <cstdint>
#include <bitset>
#include <random>
#include <chrono>

/*
 Global 8-bit variable that stores the current binary state.
 All bit operations in this file work on this variable.
*/
std::bitset<8> num{0b0000'0000};

namespace bitTools
{

    /*
     Sets one or multiple bits to 1 based on user input.
     Returns the updated bitset.
    */
    std::bitset<8> setBit(){
        std::cout << "Start To Setting....\n";
        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";

        short SM;     // Single or Multiple selection
        short place;  // Bit position

        while (true)
        {
            std::cin >> SM;

            // Exit command
            if (SM == 10){
                std::cout << "Exit\n";
                break;
            }

            // Invalid input
            if (SM != 8 && SM != 1){
                std::cout << "Try again: \n";
                continue;
            }

            // Single bit set
            if (SM == 1){
                std::cout << "The Place: \n";
                std::cin >> place;

                // Valid bit range (1–8)
                if (place <= 8 && place > 0){
                    num.set(place - 1);
                    std::cout << "Done!\n";
                    break;
                }
                std::cout << "Try again: \n";
            }
            // Multiple bit set
            else{
                while (true){
                    std::cout << "(For Exit Enter: 10 ) The Place: \n";
                    std::cin >> place;

                    if (place == 10){
                        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";
                        break;
                    }

                    if (place <= 8 && place > 0){
                        num.set(place - 1);
                        std::cout << "Done!\n";
                        continue;
                    }

                    std::cout << "Try again: \n";
                }
            }
        }

        std::cout << "End Setting....\n";
        return num;
    }

    /*
     Resets (sets to 0) one or multiple bits.
     Returns the updated bitset.
    */
    std::bitset<8> resetBit(){
        std::cout << "Start To Resetting....\n";
        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";

        short SM;
        short place;

        while (true)
        {
            std::cin >> SM;

            if (SM == 10){
                std::cout << "Exit\n";
                break;
            }

            if (SM != 8 && SM != 1){
                std::cout << "Try again: \n";
                continue;
            }

            // Single bit reset
            if (SM == 1){
                std::cout << "The Place: \n";
                std::cin >> place;

                if (place <= 8 && place > 0){
                    num.reset(place - 1);
                    std::cout << "Done!\n";
                    break;
                }
                std::cout << "Try again: \n";
            }
            // Multiple bit reset
            else{
                while (true){
                    std::cout << "(For Exit Enter: 10 ) The Place: \n";
                    std::cin >> place;

                    if (place == 10){
                        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";
                        break;
                    }

                    if (place <= 8 && place > 0){
                        num.reset(place - 1);
                        std::cout << "Done!\n";
                        continue;
                    }

                    std::cout << "Try again: \n";
                }
            }
        }

        std::cout << "End Resetting....\n";
        return num;
    }

    /*
     Flips (toggles) one or multiple bits.
     Returns the updated bitset.
    */
    std::bitset<8> flipBit(){
        std::cout << "Start To Flipping....\n";
        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";

        short SM;
        short place;

        while (true)
        {
            std::cin >> SM;

            if (SM == 10){
                std::cout << "Exit\n";
                break;
            }

            if (SM != 8 && SM != 1){
                std::cout << "Try again: \n";
                continue;
            }

            // Single bit flip
            if (SM == 1){
                std::cout << "The Place: \n";
                std::cin >> place;

                if (place <= 8 && place > 0){
                    num.flip(place - 1);
                    std::cout << "Done!\n";
                    break;
                }
                std::cout << "Try again: \n";
            }
            // Multiple bit flip
            else{
                while (true){
                    std::cout << "(For Exit Enter: 10 ) The Place: \n";
                    std::cin >> place;

                    if (place == 10){
                        std::cout << "Single change = 1     Multiple change = 8     Exit = 10\n";
                        break;
                    }

                    if (place <= 8 && place > 0){
                        num.flip(place - 1);
                        std::cout << "Done!\n";
                        continue;
                    }

                    std::cout << "Try again: \n";
                }
            }
        }

        std::cout << "End Flipping....\n";
        return num;
    }

    /*
     Tests (checks) whether a specific bit is set or not.
     Prints the result (0 or 1).
    */
    void testBit(){
        std::cout << "Start To Testing....\n";
        std::cout << "Test = 1     Exit = 10\n";

        short SM;
        short place;

        while (true)
        {
            std::cin >> SM;

            if (SM == 10){
                std::cout << "Exit\n";
                break;
            }

            if (SM != 1){
                std::cout << "Try again: \n";
                continue;
            }

            while (true){
                std::cout << "(For Exit Enter: 10 ) The Place: \n";
                std::cin >> place;

                if (place == 10){
                    std::cout << "Test = 1     Exit = 10\n";
                    break;
                }

                if (place <= 8 && place > 0){
                    std::cout << num.test(place - 1) << '\n';
                    std::cout << "Done!\n";
                    continue;
                }

                std::cout << "Try again: \n";
            }
        }

        std::cout << "End Testing....\n";
    }

    /*
     Randomly flips bits a random number of times.
     Returns the updated bitset.
    */
    std::bitset<8> randomBit(){
        std::cout << "Start To Randoming....\n";

        // Random number generator seeded with current time
        std::mt19937 mt{static_cast<int>(
            std::chrono::steady_clock::now().time_since_epoch().count())};

        std::uniform_int_distribution timesRange{1, 10};  // Number of flips
        std::uniform_int_distribution placesRange{0, 7};  // Bit positions

        short times{timesRange(mt)};
        short places{placesRange(mt)};

        // Perform random flips
        for (short i{0}; i < times; i++)
        {
            num.flip(places);
            std::cout << "Done!\n";
            places = placesRange(mt);
        }

        std::cout << "End Randoming....\n";
        return num;
    }
}