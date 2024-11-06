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

template <typename Iterator>
void selection_sort(Iterator , Iterator );

template <typename Iterator>
void heap_sort(Iterator , Iterator );

template <typename Iterator>
void insertion_sort(Iterator , Iterator );

template <typename Iterator>
void shell_sort(Iterator , Iterator );


template <typename Iterator>
void bubble_sort(Iterator , Iterator );

template <typename Iterator>
Iterator partition(Iterator , Iterator );

template <typename Iterator>
void quick_sort(Iterator , Iterator );

template <typename Iterator>
void merge(Iterator, Iterator, Iterator);

template <typename Iterator>
void merge_sort(Iterator begin, Iterator end);

}

template <typename Iterator, typename T>
auto hbut::find(
    const Iterator begin, //起始迭代器
    const Iterator end,   //终止迭代器
    const T& value        //待查元素
) -> Iterator{
    for( auto iter{begin}; iter!=end; ++iter){
        if(*iter == value) return iter;
    }
    return end;
}

template <typename Iterator, typename T>
auto hbut::binary_search(
    const Iterator begin, //起始迭代器
    const Iterator end,   //终止迭代器
    const T& value        //待查元素
) -> bool {
    auto low {begin};
    auto high {end};
    
    while(true){
        if( low > high ) return false;
        const auto mid {low + (high - low) / 2};
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

template <typename Iterator>
void hbut::selection_sort(Iterator begin, Iterator end){
    for (auto i = begin; i != end; ++i) {
        auto min_iter = i; // Assume the first element is the minimum
        for (auto j = std::next(i); j != end; ++j) {
            if (*j < *min_iter) {
                min_iter = j; // Update the minimum element
            }
        }
        if (min_iter != i) {
            std::iter_swap(i, min_iter); // Swap the found minimum with the first element
        }
    }
}

template <typename Iterator>
void hbut::heap_sort(Iterator begin, Iterator end) {
    // 在区间 [begin, end) 上建立大根堆
    std::make_heap(begin, end);

    // 依次从堆中弹出最大元素
    for (auto it = end; it != begin; --it) {
        std::pop_heap(begin, it);
    }
}


template <typename Iterator>
void hbut::insertion_sort(Iterator begin, Iterator end) {
    for (auto i = begin + 1; i != end; ++i) {
        auto temp = *i; // 记录待插入元素
        Iterator j = i - 1;

        // 若元素大于待插入元素，则向后移动一位
        while (j >= begin && *j > temp) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = temp; // 将待插入元素放到正确位置
    }
}


template <typename Iterator>
void hbut::shell_sort(Iterator begin, Iterator end) {
    // 计算元素个数
    int n = end - begin;
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        //以gap为界进行插入排序
        for (int i = gap; i < n; ++i) {
            auto temp = *(begin + i);
            int j;
            for (j = i; j >= gap && *(begin + j - gap) > temp; j -= gap) {
                *(begin + j) = *(begin + j - gap);
            }
            *(begin + j) = temp;
        }
    }
}

template <typename Iterator>
void hbut::bubble_sort(Iterator begin, Iterator end) {
    // 计算元素数量
    int n = end - begin;

    for (int i = 0; i < n - 1; ++i) {
        // 是否交换的标志
        bool swapped = false;

        for (auto j = begin; j < end - (i + 1); ++j) {
            if (*j > *(j + 1)) {
                // 若左大右小则交换
                std::iter_swap(j, j + 1);
                swapped = true; // 标记此趟有过交换
            }
        }
        // 若没有发生过交换，则说明已经有序
        if (!swapped) break;
    }
}


template <typename Iterator>
Iterator hbut::partition(Iterator begin, Iterator end) {
    // 选择最后一个元素为轴
    auto pivot = *(end - 1);
    auto i = begin; // 较小元素的插入位置

    for (auto j = begin; j < end - 1; ++j) {
        if (*j <= pivot) {
            std::iter_swap(i, j);
            ++i;
        }
    }
    std::iter_swap(i, end - 1); // 将轴交换到正确位置
    return i; // 返回轴的位置
}

template <typename Iterator>
void hbut::quick_sort(Iterator begin, Iterator end) {
    if (begin >= end) return;

    // 划分
    Iterator pivot_index = partition(begin, end);

    // 对轴左边的子序列做快速排序
    quick_sort(begin, pivot_index);
    // 对轴右边的子序列做快速排序
    quick_sort(pivot_index + 1, end);
}



template <typename Iterator>
void hbut::merge(Iterator begin, Iterator mid, Iterator end) {
    std::vector<typename Iterator::value_type> left(begin, mid);
    std::vector<typename Iterator::value_type> right(mid, end);

    Iterator left_it = left.begin();
    Iterator right_it = right.begin();
    Iterator output_it = begin;

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            *output_it++ = *left_it++;
        } else {
            *output_it++ = *right_it++;
        }
    }

    while (left_it != left.end()) {
        *output_it++ = *left_it++;
    }
    while (right_it != right.end()) {
        *output_it++ = *right_it++;
    }
}

template <typename Iterator>
void hbut::merge_sort(Iterator begin, Iterator end) {
    if (end - begin <= 1) return;
    Iterator mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
}
#endif /* hbut_algorithms_h */
