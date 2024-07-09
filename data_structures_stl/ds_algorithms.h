//
//  ds_algorithms.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/21.
//

#ifndef ds_algorithms_h
#define ds_algorithms_h

namespace ds {

template <typename Iterator, typename T>
auto find(const Iterator, const Iterator, const T&) -> Iterator;

template <typename Iterator, typename T>
auto binary_search(const Iterator, const Iterator, const T&) -> bool;

}

template <typename Iterator, typename T>
auto ds::find(
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
auto ds::binary_search(
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


#endif /* ds_algorithms_h */
