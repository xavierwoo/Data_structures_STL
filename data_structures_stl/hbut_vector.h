//
//  hbut_vector.h
//  data_structures_stl
//  顺序表 std::vector 模拟
//
//  Created by 吴 歆韵 on 2024/4/2.
//

#ifndef hbut_vector_h
#define hbut_vector_h

#include<cassert>
#include<cstdlib>
#include<utility>

//后续课程需要的头文件
#include<initializer_list>

namespace hbut {

template <typename T>
struct vector{
private:
    T* _data {nullptr};
    unsigned int _size {0};
    unsigned int _capacity {0};
public:
    struct iterator;
    vector() = default;
    ~vector();
    
    void reserve(const unsigned int );
    void push_back(const T& );
    auto size() const -> unsigned int;
    auto operator[](const unsigned int ) -> T&;
    
    auto begin() const -> iterator;
    auto end() const -> iterator;
    auto erase(const iterator ) -> iterator;
    auto insert(const iterator, const T& ) -> iterator;
    
    
    // 如需在后续课程中使用hbut::vector，需要实现以下成员函数
    vector(const vector<T>&);
    vector(vector<T>&&); //移动构造函数，会“吃掉”参数vector，节省拷贝成本
    vector(const unsigned int);
    vector(const unsigned int , const T&);
    vector(std::initializer_list<T>);
    void operator=(const vector<T>&);
    void operator=(vector<T>&&);//移动赋值，会“吃掉”参数vector，节省拷贝成本
    auto empty() const -> bool {return _size == 0;}
    void clear();
    auto operator[](const unsigned int index) const -> const T& {return _data[index];}
};

}//namespace hbut

namespace hbut {

template <typename T>
struct vector<T>::iterator{
    friend vector<T>;
private:
    T* _ptr{nullptr};
    iterator(T *p): _ptr(p){}
public:
    auto operator++() -> iterator&;
    auto operator--() -> iterator&;
    auto operator*() -> T&;
    auto operator==(const iterator ) const -> bool;
    auto operator!=(const iterator ) const -> bool;
    auto operator+(const unsigned int ) const -> iterator;
    auto operator-(const unsigned int ) const -> iterator;
    
    // 如需在后续课程中使用hbut::vector，需要实现以下成员函数
    using value_type = T;
    auto operator-(const iterator ) const -> unsigned int;
    auto operator->() -> T*{return _ptr;};
    auto operator>(const iterator) const -> bool;
};

}//namespace hbut

//********** hbut::vector 成员函数实现********************
template <typename T>
hbut::vector<T>::~vector(){
    for(int i{0}; i<_size; i++){
        //对当前容器中每一个元素调用析构函数
        _data[i].~T();
    }

    //需要头文件<cstdlib>
    std::free(_data);
}

template <typename T>
void hbut::vector<T>::reserve(const unsigned int new_cap){
    assert(new_cap > _capacity && "新容量必须大于原容量");
    _data = (T*)std::realloc(_data, sizeof(T) * new_cap);
    //注意std::realloc函数需要头文件<cstdlib>
    _capacity = new_cap;
}

template <typename T>
void hbut::vector<T>::push_back(const T& value){
    if(_size == _capacity){//若容器已满，则进行扩容
        reserve(_capacity*2 + 1);
    }
    new (&_data[_size]) T(value);//m_data[m_size] = value;
    _size++;
}

template <typename T>
auto hbut::vector<T>::operator[](
    const unsigned int index
) -> T&{
    assert(index >= 0 && index < _size && "下标越界");
    return _data[index];
}

template <typename T>
hbut::vector<T>::vector(
    const vector<T> &other
){
    if(other.size() == 0) return;
    reserve(other.size());
    for(auto &e : other){
        push_back(e);
    }
}

template <typename T>
hbut::vector<T>::vector(
    vector<T>&& other
) {
    if(other.size() == 0) return;
    _size = other._size;
    _data = other._data;
    _capacity = other._capacity;
    other._size = 0;
    other._capacity = 0;
    other._data = nullptr;
}

template <typename T>
hbut::vector<T>::vector(
    const unsigned int capacity
){
    
    reserve(capacity);
}

template <typename T>
hbut::vector<T>::vector(
    const unsigned int number,
    const T &value
){
    reserve(number);
    for(auto i{0}; i< number; ++i){
        push_back(value);
    }
}

template <typename T>
hbut::vector<T>::vector(
    std::initializer_list<T> l
) {
    if(l.size() == 0) return;
    reserve((unsigned int)l.size());
    for(auto& e : l){
        push_back(e);
    }
}

template <typename T>
void hbut::vector<T>::operator=(
    const vector<T>& other
) {
    
    for(auto& e : *this){
        e.~T();
    }
    _size = 0;
    for(auto& e : other){
        push_back(e);
    }
}

template <typename T>
void hbut::vector<T>::operator=(vector<T>&& other){
    for(auto& e : *this){
        e.~T();
    }
    std::free(_data);
    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;
    
    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;
}

template <typename T>
auto hbut::vector<T>::size() const -> unsigned int{
    return _size;
}

template <typename T>
//typename hbut::vector<T>::iterator hbut::vector<T>::begin() const{
auto hbut::vector<T>::begin() const -> iterator{
    return iterator(_data);
}

template <typename T>
auto hbut::vector<T>::end() const -> iterator{
    return iterator(_data + _size);
}

template <typename T>
auto hbut::vector<T>::erase(
    const iterator pos
) -> iterator{
    if (pos == end()){
        return pos;
    }
    
    auto curr {pos};
    auto next {pos + 1};
    
    (*curr).~T();//删除当前元素
    while(next != end()){
        *curr = std::move(*next); //*curr = *next?
        ++curr;
        ++next;
    }
    --_size;
    
    return pos;
}

template <typename T>
auto hbut::vector<T>::insert(
    const iterator pos,
    const T& value
) -> iterator{
    if(_size == _capacity){
        reserve(_capacity*2 + 1);
    }
    auto curr {end()};
    auto prev {curr - 1};
    
    while(curr != pos){
        *curr = std::move(*prev);
        --curr;
        --prev;
    }
    ++_size;
    new (curr._ptr) T(value);

    return pos;
}

template <typename T>
void hbut::vector<T>::clear(){
    for(auto i{0}; i<_size; i++){
        _data[i].~T(); //对当前容器中每一个元素调用析构函数
    }
    _size = 0;
}

//********** hbut::vector::iterator 成员函数实现*********************
template <typename T>
auto hbut::vector<T>::iterator::operator++(
) -> iterator& {
    _ptr++;
    return *this;
}

template <typename T>
auto hbut::vector<T>::iterator::operator--(
) -> iterator& {
    _ptr--;
    return *this;
}

template <typename T>
auto hbut::vector<T>::iterator::operator*(
) -> T& {
    return *_ptr;
}

template <typename T>
auto hbut::vector<T>::iterator::operator==(
    const iterator other
) const -> bool {
    return _ptr == other._ptr;
}

template <typename T>
auto hbut::vector<T>::iterator::operator!=(
    const iterator other
) const -> bool {
    return _ptr != other._ptr;
}

template <typename T>
auto hbut::vector<T>::iterator::operator+(
    const unsigned int offset
) const -> iterator {
    return iterator(_ptr + offset);
}

template <typename T>
auto hbut::vector<T>::iterator::operator-(
    const unsigned int offset
) const -> iterator {
    return iterator(_ptr - offset);
}

template <typename T>
auto hbut::vector<T>::iterator::operator-(
    const iterator other
) const -> unsigned int{
    
    return (unsigned int)(_ptr - other._ptr);
}

template <typename T>
auto hbut::vector<T>::iterator::operator>(
    const iterator other
) const -> bool{
    return _ptr > other._ptr;
}
#endif /* hbut_vector_h */
