#include <iostream>
#include <string>
#include <vector>


int main(){

    std::cout << "Enter a sentence: \n";
    std::string sentence;
    std::getline(std::cin , sentence);


    int words{0};
    std::vector <int> letters_each_word{};
    int total_letters{0};
    bool start{false};
    int length{sentence.size()};
    

    for (int i{0}; i < length; i++){
        if (start == false){
            if (std::isalnum(sentence[i])){
                start = true;
            }
            else
                continue;
        }

        if (!std::isspace(sentence[i]))
        {
            
            if (std::size(letters_each_word) <= words)
            {
                letters_each_word.push_back(0);
            }
            letters_each_word[words]++;
            
            if ((i < length - 1) && (std::isspace(sentence[i+1])) && (!std::isspace(sentence[i-1])) || i+1 == length)
            {
                words++;
            }

            if (std::isalpha(sentence[i]))
            {
                total_letters++;
            }
            
        }

    }
    

    std::cout << "Total Letters: " << total_letters << '\n';
    std::cout << "Total Words: " << words << '\n';

    for (int i{1}; i <= std::size(letters_each_word); i++){
        std::cout << "Word " << i << ": " << letters_each_word[i-1] << '\n';
    }


    return 0;
}
