//
//  ds_heap.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/25.
//

#ifndef ds_heap_h
#define ds_heap_h

#include <cassert>
#include "ds_vector.h"

//此文件函数需要使用 ds::vector::iterator - ds::vector::iterator 操作符
namespace ds {

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void push_heap(Iterator, Iterator, Comparator = Comparator());

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void pop_heap(Iterator, Iterator, Comparator = Comparator());

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void make_heap(Iterator, Iterator, Comparator = Comparator());

template <typename Iterator,typename Comparator>
void heap_percolate_down(Iterator, Iterator, Iterator, Comparator);

}//namespace ds

template <typename Iterator, typename Comparator>
void ds::push_heap(
    Iterator first,
    Iterator last,
    Comparator cmpr
){
    if (first == last) return;
    
    auto child_pos {last - 1 - first};
    auto parent_pos {(child_pos - 1) / 2};
    
    auto temp {std::move(*(first + child_pos))};
    
    while(child_pos > 0){
        if(!cmpr(*(first + parent_pos), temp)){
            break;
        }
        *(first + child_pos) = std::move(*(first + parent_pos));
        child_pos = parent_pos;
        parent_pos = (child_pos - 1) / 2;
    }
    *(first + child_pos) = std::move(temp);
}


template <typename Iterator,typename Comparator>
void ds::heap_percolate_down(
    Iterator first,
    Iterator last,
    Iterator iter,
    Comparator cmpr
){
    auto parent_pos {iter - first};
    auto child_pos {parent_pos * 2 + 1};
    auto size {last - first};
    
    auto temp {std::move(*(iter))};
    while(child_pos < size){
        //取两个孩子中的大者（大根堆）
        if(child_pos + 1 < size
            && !cmpr(*(first + child_pos + 1), *(first + child_pos)) ){
            ++child_pos;
        }
        if(!cmpr(temp, *(first + child_pos))){
            break;
        }else{
            //将孩子移到亲节点
            *(first + parent_pos) = std::move(*(first + child_pos));
            parent_pos = child_pos;
            child_pos = parent_pos * 2 + 1;
        }
    }
    *(first + parent_pos) = std::move(temp);
}
//

//将处于first的元素放到last-1，同时将first到last-2的元素重新调整为堆
template <typename Iterator,typename Comparator>
void ds::pop_heap(
    Iterator first,
    Iterator last,
    Comparator cmpr
) {
    if(first == last) return;
    auto temp {std::move(*first)};
    *first = std::move(*(last - 1));
    *(last - 1) = std::move(temp);
    heap_percolate_down(first, last-1, first, cmpr);
}

template <typename Iterator, typename Comparator>
void ds::make_heap(
    Iterator first,
    Iterator last,
    Comparator cmpr
){
    if (first == last) return;
    
    const auto size {last - first};
    for(int i = size/2-1; i>=0; --i){
        heap_percolate_down(first, last-1, first+i, cmpr);
    }
}

#endif /* ds_heap_h */
