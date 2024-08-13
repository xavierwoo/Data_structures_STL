//
//  hbut_heap.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/25.
//

#ifndef hbut_heap_h
#define hbut_heap_h

#include <cassert>

namespace hbut {

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void push_heap(
        const Iterator, const Iterator,
        const Comparator = Comparator()
);

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void pop_heap(
        const Iterator, const Iterator,
        const Comparator = Comparator()
);

template <
    typename Iterator,
    typename Comparator = std::less<
        typename Iterator::value_type
    >
>
void make_heap(
        const Iterator, const Iterator,
        const Comparator = Comparator()
);

template <typename Iterator,typename Comparator>
void heap_percolate_down(
        const Iterator, const Iterator,Iterator, const Comparator
);

}//namespace ds

template <typename Iterator, typename Comparator>
void hbut::push_heap(
    const Iterator first,
    const Iterator last,
    const Comparator cmpr
){
    if (first == last) return;
    auto child_pos {last - 1 - first};//待插入堆的元素
    auto parent_pos {(child_pos - 1) / 2};
    auto temp {std::move(*(first + child_pos))};//暂存待插入元素
    while(child_pos > 0){
        if(!cmpr(*(first + parent_pos), temp)){
            break;
        }
        *(first + child_pos) = std::move(*(first + parent_pos));
        child_pos = parent_pos;
        parent_pos = (child_pos - 1) / 2;
    }
    *(first + child_pos) = std::move(temp);//将插入元素放到正确的位置
}


template <typename Iterator,typename Comparator>
void hbut::heap_percolate_down(
    const Iterator first,
    const Iterator last,
    Iterator iter,
    const Comparator cmpr
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
void hbut::pop_heap(
    Iterator first,
    const Iterator last,
    const Comparator cmpr
) {
    if(first == last) return;
    auto temp {std::move(*first)};
    *first = std::move(*(last - 1));
    *(last - 1) = std::move(temp);
    heap_percolate_down(first, last-1, first, cmpr);
}

template <typename Iterator, typename Comparator>
void hbut::make_heap(
    const Iterator first,
    const Iterator last,
    const Comparator cmpr
){
    if (first == last) return;
    const auto size {last - first};
    //从最后一个非叶子节点开始向下调整
    for(int i = size/2-1; i>=0; --i){
        heap_percolate_down(first, last-1, first+i, cmpr);
    }
}

#endif /* ds_heap_h */
