//
//  hbut_algorithms.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/21.
//

#ifndef hbut_algorithms_h
#define hbut_algorithms_h

#include <iostream>
#include <vector>
#include <string>

namespace hbut {
auto check_brackets_matching(const std::string&) -> bool;

template <typename Iterator, typename T>
auto find(const Iterator, const Iterator, const T&) -> Iterator;

template <typename Iterator, typename T>
auto binary_search(const Iterator, const Iterator, const T&) -> bool;

template <typename T>
auto get_power_set(
    const std::vector<T>&
) -> std::vector<std::vector<T>>;

template <typename T>
void power_set_recur(
    const std::vector<T>&,
    const unsigned int,
    std::vector<T>&,
    std::vector<std::vector<T>>&
);

void hanoi(const int, const char, const char, const char);
}

template <typename Iterator, typename T>
auto hbut::find(
    const Iterator begin,
    const Iterator end,
    const T& value
) -> Iterator{
    for( auto iter{begin}; iter!=end; ++iter){
        if(*iter == value) return iter;
    }
    return end;
}

template <typename Iterator, typename T>
auto hbut::binary_search(
    const Iterator begin,
    const Iterator end,
    const T& value
) -> bool {
    auto low {begin};
    auto high {end};
    
    while(true){
        if( low > high ) return false;
        auto mid {low + (high - low) / 2};
        if(*mid == value) {
            return true;
        }else if(*mid < value){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
}

template<typename T>
void hbut::power_set_recur(
    const std::vector<T>& ori_set,
    const unsigned int pos,
    std::vector<T>& curr_set,
    std::vector<std::vector<T>>& power_set
){
    if (pos == ori_set.size()){
        power_set.push_back(curr_set);
        return;
    }
    curr_set.push_back(ori_set[pos]);
    power_set_recur(ori_set, pos+1, curr_set, power_set);
    curr_set.pop_back();
    power_set_recur(ori_set, pos+1, curr_set, power_set);
}

template <typename T>
auto hbut::get_power_set(
    const std::vector<T>& ori_set
) -> std::vector<std::vector<T>>{

    std::vector<T> curr_set;
    std::vector<std::vector<T>> power_set;
    power_set_recur(ori_set, 0, curr_set, power_set);
    return power_set;
}



#endif /* ds_algorithms_h */
