#include <iostream>


template<typename T,typename U>
struct PairTwo
{
    T first;
    U second;
};


template <typename T, typename U>
auto pairTwoFunc(PairTwo<T, U> x){
    return ((x.first > x.second)? x.first : (x.second > x.first)? x.second : 0);
}


int main(){

    PairTwo<int, double> PT1{10, 22.2};
    PairTwo<int, double> PT2{57, 27.541};

    std::cout << pairTwoFunc(PT1) << '\n';
    std::cout << pairTwoFunc(PT2) << '\n';



    return 0;
}








