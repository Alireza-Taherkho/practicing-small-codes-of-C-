#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
#include <random>
#include <chrono>



std::bitset<8> num{0b0000'0000};


void setBit(){
    std::cout << "Start To Setting....\n";
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

        if (SM == 1){
            std::cout << "The Place: \n";
            std::cin >> place;
            if (place <= 8 && place > 0){
                num.set(place - 1);
                std::cout << "Done!\n";
                break;
            }
            std::cout << "Try again: \n";
        }
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
}


void resetBit(){
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
}


void flipBit(){
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
}


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


void randomBit(){
    std::cout << "Start To Randoming....\n";
    std::mt19937 mt{static_cast<int>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution timesRange{1, 10};
    std::uniform_int_distribution placesRange{0, 7};
    short times{timesRange(mt)};
    short places{placesRange(mt)};


    for (short i{times}; i <= 10; i++)
    {     
        num.flip(places);
        std::cout << "Done!\n";
        places = placesRange(mt);
    }
    std::cout << "End Randoming....\n";
}


void Panel(){
    short request;
    bool Finish {false};
    while (true)
    {
        if (Finish == true){
            std::cout << "End Processing...\n";
            break;
        }

        while (true){
        std::cin >> request;
        if (request <= 7 && request > 0)
            break;

        std::cout << "Try again: \n";  
        }

        switch (request){
            case 1:
                setBit();
                break;

            case 2:
                resetBit();
                break;

            case 3:
                flipBit();
                break;
    
            case 4:
                std::cout << num << '\n';
                break;

            case 5:
                testBit();
                break;

            case 6:
                std::cout << "Operations:   Set = 1     Reset = 2     Flip = 3     Show All = 4     Show One = 5     Operations List = 6     Random Flip = 7     Exit = 8  ->\n";
                break;

            case 7:
                randomBit();
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



int main(){

    std::cout << "Your Bit number: " << num << '\n';
    std::cout << "Operations:   Set = 1     Reset = 2     Flip = 3     Show All = 4     Show One = 5     Operations List = 6     Random Flip = 7     Exit = 8  ->\n";

    Panel();

    return 0;
}








