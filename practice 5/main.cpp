#include <iostream>
#include <array>



template <typename T, std::size_t S>
auto sumArr(const std::array<T, S>& arr){

    auto sum{arr[0]};

    for (int i{1}; i < std::size(arr); i++){
        sum += arr[i];
    }
    return sum;

}



int main(){

    std::array<int, 5> intArr{1,2,3,4,5};
    std::array<double, 3> doubleArr{2.54, 81.245, 15.12};


    std::cout << sumArr(intArr) << '\n';
    std::cout << sumArr(doubleArr) << '\n';



    return 0;
}