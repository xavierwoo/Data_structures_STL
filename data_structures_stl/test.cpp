//
//  test.cpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/2.
//

#include "test.hpp"
#include "hbut_vector.h"
#include "hbut_forward_list.h"
#include "hbut_list.h"
#include "hbut_stack.h"
#include "hbut_queue.h"
#include "hbut_heap.h"
#include "hbut_binary_tree.h"
#include "hbut_tree.h"
#include "hbut_calculator.hpp"
#include "hbut_graph.h"
#include "hbut_algorithms.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>

using std::cout;

void test_std_vector_add_and_access(){
    cout<<"测试std::vector添加访问元素：\n\t";
    std::vector<int> vec;
    vec.push_back(1); //依次向vec末尾插入1，2，3，4
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for(auto i{0}; i<vec.size(); ++i){
        cout<<vec[i]<<' '; // 按顺序依次输出vec中的元素
    }
    cout<<"\n";
}

void test_std_vector_initialization_list(){
    cout<<"测试std::vector初始化列表\n\t";

    std::vector<int> vec {1,2,3,4};
    for(auto i{0}; i<vec.size(); ++i){
        cout<<vec[i]<<' ';
    }
    cout<<"\n";
}

void test_std_vector_iterator_traversal(){
    cout<<"测试使用迭代器遍历std::vector：\n\t";

    std::vector<int> vec {1, 2, 3, 4};
    //使用迭代器遍历元素
    for(auto it{vec.begin()}; it!=vec.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<"\n";
}

void test_std_vector_iterator_calculation(){
    cout<<"测试std::vector迭代器运算：\n";

    std::vector<int> vec {1, 2, 3, 4};
    auto it1 {vec.begin() + 2};
    cout<<"\t第3个元素为"<<*it1<<"\n";//输出3
    auto it2 {vec.end() - 2};
    cout<<"\t倒数第2个元素为"<<*it2<<"\n";//输出3
    ++it1;
    cout<<"\t第3个元素的后继为"<<*it1<<"\n"; //输出4
    --it2;
    cout<<"\t倒数第2个元素的前序为"<<*it2<<"\n"; //输出2
    cout<<"\n";
}

void test_std_vector_iterator_grammar_sugar(){
    cout<<"测试使用迭代器语法糖遍历std::vector：\n\t";

    std::vector<int> vec {1, 2, 3, 4};
    //使用迭代遍历语法糖
    for(auto e : vec){
        cout<<e<<' ';   //输出 1 2 3 4
    }
    //等同于以下代码
    for(auto it{vec.begin()}; it!=vec.end(); ++it){
        auto e {*it};
        cout<<e<<' ';
    }
    cout<<"\n";
}

void test_std_vector_erase(){
    cout<<"测试std::vector删除元素：\n\t";

    std::vector<int> vec {1, 2, 3, 4};
    auto it {vec.begin() + 2};
    auto it_after {vec.erase(it)}; //删除元素
    cout<<"删除第3个元素后，vector为{";
    for(auto e : vec) cout<<e<<' '; // 输出 1 2 4
    cout<<"}。\n\t";
    cout<<"erase返回的迭代器指向"<<*it_after<<"。\n"; //输出 4
}

void test_std_vector_insert(){
    cout<<"测试vector添加元素：\n\t";

    std::vector<int> vec {1, 2, 3, 4};
    auto it {vec.begin() + 2};
    auto it_after {vec.insert(it, 10)}; //插入元素 10
    cout<<"在第3个元素前添加10后，vector为{";
    for(auto e : vec) cout<<e<<' '; //输出 1 2 10 3 4
    cout<<"}。\n\t";
    cout<<"insert返回的迭代器指向"<<*it_after<<"。\n"; //输出10
    cout<<"\n";
}

void test_std_vector(){
    cout<<"\n\n***std::vector***\n";
    test_std_vector_add_and_access();
    test_std_vector_initialization_list();
    test_std_vector_iterator_traversal();
    test_std_vector_iterator_calculation();
    test_std_vector_iterator_grammar_sugar();
    test_std_vector_erase();
    test_std_vector_insert();
}

void test_hbut_vector_add_and_access(){
    cout<<"测试hbut::vector添加访问元素：\n\t";

    hbut::vector<int> vec;
    vec.push_back(1); //依次向vec末尾插入1，2，3，4
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for(auto i{0}; i<vec.size(); ++i){
        cout<<vec[i]<<' '; // 按顺序依次输出vec中的元素
    }
    cout<<"\n";
}

void test_hbut_vector_iterator_traversal(){
    cout<<"测试hbut::vector迭代器遍历\n\t";
    hbut::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    //使用迭代遍历语法糖
    for(auto e : vec){
        cout<<e<<' ';   //输出 1 2 3
    }
    //等同于以下代码
    for(auto it{vec.begin()}; it!=vec.end(); ++it){
        auto e {*it};
        cout<<e<<' ';
    }
    cout<<"\n";
}

void test_hbut_vector_iterator_calculation(){
    cout<<"测试hbut::vector迭代器运算\n";

    hbut::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    auto it1{vec.begin() + 2};
    cout<<"\t第3个元素为"<<*it1<<'\n';//输出3
    auto it2{vec.end() - 2};
    cout<<"\t倒数第2个元素为"<<*it2<<'\n';//输出3
    ++it1;
    cout<<"\t第3个元素的后继为"<<*it1<<'\n'; //输出4
    --it2;
    cout<<"\t倒数第2个元素的前序为"<<*it2<<'\n'; //输出2
}


void test_hbut_vector_erase(){
    cout<<"测试hbut::vector删除元素\n\t";

    hbut::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto it {vec.begin() + 2};
    auto it_after {vec.erase(it)}; //删除元素
    cout<<"删除第3个元素后，vector为{";
    for(auto e : vec) cout<<e<<' ';// 输出 1 2 4
    cout<<"}。\n\t";
    cout<<"erase返回的迭代器指向"<<*it_after<<"。\n"; //输出 4
}

void test_hbut_vector_insert(){
    cout<<"测试hbut::vector插入元素\n\t";

    hbut::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto it {vec.begin() + 2};
    auto it_after {vec.insert(it, 10)}; //插入元素 10
    cout<<"在第3个元素前添加10后，vector为{";
    for(auto e : vec) cout<<e<<' '; //输出 1 2 10 3 4
    cout<<"}。\n\t";
    cout<<"insert返回的迭代器指向"<<*it_after<<"。\n"; //输出10
}

void test_hbut_vector(){
    cout<<"\n\n***hbut::vector***\n";
    test_hbut_vector_add_and_access();
    test_hbut_vector_iterator_traversal();
    test_hbut_vector_iterator_calculation();
    test_hbut_vector_erase();
    test_hbut_vector_insert();
}

void test_std_forward_list_add_and_traversal(){
    cout<<"测试std::forward_list添加元素及遍历\n";

    std::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    cout<<"\t使用迭代器遍历：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<"\n\t使用迭代器语法糖遍历：";
    for(auto e : lst) cout<<e<<' ';
    cout<<"\n";
}

void test_std_forward_list_initialization_list(){
    cout<<"测试std::forward_list初始化列表：\n\t";

    std::forward_list<int> lst {1, 2, 3, 4};
    for(auto e : lst) {
        cout<<e<<' ';
    }
    cout<<"\n";
}

void test_std_forward_list_erase(){
    cout<<"测试forward_list::erase_after：\n";

    std::forward_list<int> lst {1, 2, 3, 4};
    cout<<"\t删除元素2后面的元素：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.erase_after(it);
            cout<<"\n\t函数返回的迭代器指向："
                <<*ret_it; //4
            break;
        }
    }
    cout<<"\n\t删除后链表元素为：";
    for(auto e : lst) cout<<e<<' ';
    // 1 2 4
    cout<<"\n";
}

void test_std_forward_list_insert(){
    cout<<"测试 forward_list::insert_after：\n";
    std::forward_list<int> lst {1, 2, 3, 4};

    cout<<"\t在元素2后插入10：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.insert_after(it, 10);
            cout<<"\n\tinsert_after函数返回的迭代器指向："
                <<*ret_it; //10
            break;
        }
    }
    cout<<"\n\t插入后链表元素为：";
    for(auto e : lst) cout<<e<<' ';
    // 1 2 10 3 4
    cout<<"\n";
}

void test_std_forward_list_get_kth_element(){
    cout<<"std::forward_list获得第3个元素：\n\t";

    std::forward_list<int> lst {1, 2, 3, 4};
    auto iter {lst.begin()};
    //找到第3个元素
    for(int i=0; i<2; ++i)++iter;

    cout<<*iter;
    cout<<"\n";
}

void test_std_forward_list(){
    cout<<"\n***std::forward_list***\n";
    test_std_forward_list_add_and_traversal();
    test_std_forward_list_initialization_list();
    test_std_forward_list_erase();
    test_std_forward_list_insert();
    test_std_forward_list_get_kth_element();
}

void test_hbut_forward_list_construct_deconstruct(){
    cout<<"测试 hbut::forward_list构造与析构函数：\n\t";
    hbut::forward_list<int> lst;
    cout<<"构造函数成功执行！\n";
}

void test_hbut_forward_list_push_front(){
    cout<<"测试 hbut::forward_list::push_front：\n";
    hbut::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
}

void test_hbut_forward_list_iterator_traversal(){
    cout<<"测试hbut::forward_list遍历\n\t";
    hbut::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    *lst.begin() = 4; //测试修改第一个元素

    cout<<"使用迭代器遍历：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<"\n\t使用迭代器语法糖：";
    for(auto e : lst){
        cout<<e<<" ";
    }
    cout<<"\n";
}

void test_hbut_forward_list_erase(){
    cout<<"测试hbut::forward_list::erase_after：\n";
    hbut::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);

    cout<<"\t删除元素3后面的元素：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 3){
            auto ret_it = lst.erase_after(it);
            cout<<"\n\terase_after函数返回的迭代器指向："<<*ret_it;
            //1
            break;
        }
    }

    cout<<"\n\t删除后链表元素为：";
    for(auto e : lst) cout<<e<<' '; cout<<"\n";
    //4 3 1
}

void test_hbut_forward_list_insert(){
    cout<<"测试hbut::forward_list::insert_after\n\t";
    hbut::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    cout<<"\t在元素2后插入元素10：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.insert_after(it, 10);
            cout<<"\n\tinsert_after函数返回的迭代器指向："<<*ret_it;
            //10
            break;
        }
    }
    cout<<"\n\t插入后链表元素为：";
    for(auto e : lst) cout<<e<<' '; cout<<"\n";
    // 3 2 10 1
}

void test_hbut_forward_list_reverse(){
    cout<<"测试hbut::forward_list::reverse\n\t";
    hbut::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    lst.reverse();
    for(auto e : lst) cout<<e<<' '; cout<<"\n";
}

void test_hbut_forward_list(){
    cout<<"\n***hbut::forward_list***\n";
    test_hbut_forward_list_construct_deconstruct();
    test_hbut_forward_list_push_front();
    test_hbut_forward_list_iterator_traversal();
    test_hbut_forward_list_erase();
    test_hbut_forward_list_insert();
    test_hbut_forward_list_reverse();
}

void test_std_list_add_traversal(){
    cout<<"测试std::list插入元素及遍历：\n";

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(3);
    lst.push_front(4);
    cout<<"\t使用迭代器遍历：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<"\n\t使用迭代器语法糖遍历：";
    for(auto e : lst) cout<<e<<' '; cout<<'\n';
}

void test_std_list_initialization_list(){
    cout<<"测试std::list初始化列表：\n\t";

    std::list<int> lst {1, 2, 3, 4};
    for(auto e : lst) cout<<e<<" ";
    cout<<"\n";
}

void test_std_list_erase(){
    cout<<"测试std::list::erase：\n\t";

    std::list<int> lst {1,2,3,4};
    auto it {lst.begin()};
    ++it;
    it = lst.erase(it);
    cout<<"删除后迭代器指向："<<*it<<"\n\t"; //3
    for(auto e : lst) cout<<e<<" ";
    // 1 3 4
    cout<<"\n";
}

void test_std_list_insert(){
    cout<<"测试std::list::insert：\n\t";

    std::list<int> lst {1,2,3,4};
    auto it {lst.begin()};
    ++it;
    it = lst.insert(it, 10);
    cout<<"插入后迭代器指向："<<*it<<"\n\t";//10
    for(auto e : lst) cout<<e<<" ";
    // 1 10 2 3 4
    cout<<" ";
}

void test_std_list(){
    cout<<"\n\n***std::list***\n";

    test_std_list_add_traversal();
    test_std_list_initialization_list();
    test_std_list_erase();
    test_std_list_insert();
}

void test_hbut_list_construct_deconstruct(){
    cout<<"测试hbut::list构造与析构函数：\n\t";
    hbut::list<int> lst;
    cout<<"构造函数成功执行！\n";
}

void test_hbut_list_add(){
    cout<<"测试hbut::list::push_back：\n";

    hbut::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
}


void test_hbut_list_iterator(){
    cout<<"测试hbut::list迭代器\n\t";

    hbut::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    auto iter {lst.end()};
    --iter;--iter; //倒数第二个元素
    *iter = 10;
    cout<<"使用迭代器遍历：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        cout<<*it<<" ";
    }// 1 10 3
    cout<<"\n\t使用迭代器语法糖：";
    for(auto e : lst) cout<<e<<" ";
    cout<<"\n";
}

void test_hbut_list_erase(){
    cout<<"测试hbut::list::erase\n\t";

    hbut::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    cout<<"删除元素2：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.erase(it);
            cout<<"\n\terase函数返回的迭代器指向："<<*ret_it;
            //3
            break;
        }
    }
    cout<<"\n\t删除后链表元素为：";
    for(auto e : lst) cout<<e<<" "; cout<<"\n";
    // 1 3
}

void test_hbut_list_insert(){
    cout<<"测试hbut::list::insert：\n";

    hbut::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    cout<<"\t在元素2前插入元素10：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.insert(it, 10);
            cout<<"\n\tinsert函数返回的迭代器指向："<<*ret_it;
            //10
            break;
        }
    }
    cout<<"\n\t插入后链表元素为：";
    for(auto e : lst) cout<<e<<" "; cout<<"\n";
    // 1 10 2 3
}

void test_hbut_list(){
    cout<<"\n\n***hbut::list***\n";
    test_hbut_list_construct_deconstruct();
    test_hbut_list_add();
    test_hbut_list_iterator();
    test_hbut_list_erase();
    test_hbut_list_insert();
}

void test_std_stack_functions(){
    cout<<"测试std::stack：\n\t";

    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout<<"栈中元素数量为："<<stk.size()<<"\n\t";//3
    while(! stk.empty()){
        int e {stk.top()}; //top函数获取栈顶元素
        cout<<e<<" ";
        stk.pop(); //弹出栈顶元素
    }
    //3 2 1
    cout<<"\n";
}

void test_brackets_matching(){
    cout<<"测试使用stack的括弧匹配算法：\n\t";

    std::string test_string1{"s(sde){sx[s]s(s)d}xxs"};
    cout<<"字符串：\""<<test_string1<<"\" 括弧匹配情况："
        <<hbut::check_brackets_matching(test_string1)
        <<"\n\t";//1
    std::string test_string2{"s(sde){sx[s{]}s(s)d}xxs"};
    cout<<"字符串：\""<<test_string2<<"\" 括弧匹配情况："
        <<hbut::check_brackets_matching(test_string2)
        <<"\n";//2
}

void test_std_stack(){
    cout<<"\n\n***std::stack***\n";
    test_std_stack_functions();
    test_brackets_matching();
}

void test_hbut_stack_functions(){
    cout<<"测试hbut::stack：\n\t";

    hbut::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout<<"栈中元素数量为："<<stk.size()<<"\n\t";//3
    while(! stk.empty()){
        int e {stk.top()}; //top函数获取栈顶元素
        cout<<e<<" ";
        stk.pop(); //弹出栈顶元素
    }
    //3 2 1
    cout<<"\n";
}

void test_hbut_stack(){
    cout<<"\n\n***hbut::stack***\n";
    test_hbut_stack_functions();
}

void test_std_queue_functions(){
    cout<<"测试std::queue：\n\t";

    std::queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << "队列中元素数量为：" << que.size() << "\n\t";//3
    while(! que.empty()){
        int e {que.front()}; //front函数获取队头元素
        cout<<e<<" ";
        que.pop(); //弹出队头元素
    }
    //1 2 3
    cout<<"\n";
}

void test_std_queue(){
    cout<<"\n\n***std::queue***\n";
    test_std_queue_functions();
}

void test_hbut_queue_functions(){
    cout<<"测试hbut::queue：\n\t";

    hbut::queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << "队列中元素数量为：" << que.size() << "\n\t";//3
    while(! que.empty()){
        int e {que.front()}; //front函数获取队头元素
        cout<<e<<" ";
        que.pop(); //弹出队头元素
    }
    //1 2 3
    cout<<"\n";
}

void test_hbut_queue(){
    cout<<"\n\n***hbut::queue***\n";
    test_hbut_queue_functions();
}

void test_std_push_heap(){
    cout<<"测试std::push_heap：\n\t";

    std::vector<int> heap {20, 17, 7, 12, 7, 15};
    std::push_heap(heap.begin(), heap.end());
    for(int e: heap) cout<<e<<" ";
    //20 17 15 12 7 7
    cout<<"\n";
}

void test_std_pop_heap(){
    cout<<"测试std::pop_heap：\n\t";

    std::vector<int> heap {21, 17, 20, 12, 7, 7, 1};
    std::pop_heap(heap.begin(), heap.end());
    for(int e: heap) cout<<e<<" ";
    //20 17 7 12 7 1 21
    cout<<"\n";
}

void test_std_make_heap(){
    cout<<"测试std::make_heap：\n\t";
    std::vector<int> heap {12, 8, 7, 17 ,20, 21};
    std::make_heap(heap.begin(), heap.end());
    for(int e: heap) cout<<e<<" ";
    //21 20 12 17 8 7
    cout<<"\n";
}

void test_std_min_heap(){
    cout<<"测试std min heap：\n\t";

    std::vector<int> heap {12, 8, 3, 9, 7};
    std::make_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //3 7 12 9 8
    heap.push_back(5);
    std::push_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //3 7 5 9 8 12
    std::pop_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n";
    //5 7 12 9 8 3
}

void test_std_priority_queue(){
    cout<<"测试std::priority_queue：\n\t";

    std::priority_queue<int> pq;
    pq.push(2);
    pq.push(5);
    pq.push(10);
    pq.push(0);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}

void test_std_priority_queue_min(){
    cout<<"测试std::priority_queue小值优先：\n\t";
    std::priority_queue<int,
            std::vector<int>,
            std::greater<> > pq;
    pq.push(2);
    pq.push(5);
    pq.push(10);
    pq.push(0);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }//输出 0 2 5 10
    cout<<"\n";
}

void test_std_heap(){
    cout<<"\n\n***std heap操作***\n";
    test_std_push_heap();
    test_std_pop_heap();
    test_std_make_heap();
    test_std_min_heap();
    test_std_priority_queue();
    test_std_priority_queue_min();
}

void test_hbut_heap_max(){
    cout<<"测试hbut heap大根堆操作：\n\t";

    std::vector<int> heap {12, 8, 3, 9, 7};
    hbut::make_heap(heap.begin(), heap.end());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //12 9 3 8 7
    heap.push_back(5);
    hbut::push_heap(heap.begin(), heap.end());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //12 9 5 8 7 3
    hbut::pop_heap(heap.begin(), heap.end());
    for(int e : heap) cout<<e<<" ";cout<<"\n";
    //9 8 5 3 7 12
}

void test_hbut_heap_min(){
    cout<<"测试hbut heap小根堆操作：\n\t";

    std::vector<int> heap {12, 8, 3, 9, 7};
    hbut::make_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //3 8 12 9 7
    heap.push_back(5);
    hbut::push_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n\t";
    //3 8 5 9 7 12
    hbut::pop_heap(heap.begin(), heap.end(), std::greater<>());
    for(int e : heap) cout<<e<<" ";cout<<"\n";
    //5 8 12 9 7 3
}

void test_hbut_heap(){
    cout<<"\n\n***hbut heap操作***\n";
    test_hbut_heap_max();
    test_hbut_heap_min();
}

void test_binary_tree_construction(){
    cout<<"测试hbut::Binary_tree构造：\n\t";

    using Node_char = hbut::Binary_tree<char>::Node;
    hbut::Binary_tree<char> binary_tree(
            new Node_char(
                    'A',
                    new Node_char(
                            'B',
                            new Node_char('D')
                    ),
                    new Node_char(
                            'C',
                            new Node_char('E'),
                            new Node_char('F')
                    )
            )
    );
    cout<<"\n";
}

void test_huffman_tree(){
    cout<<"测试哈夫曼树：\n";

    std::vector<int> values {7,5,2,4};
    auto tree {hbut::Binary_tree<int>::make_huffman_tree(values)};
    cout<<"\n";
}

void test_binary_tree_level_traversal(){
    cout<<"测试hbut::Binary_tree层次遍历：\n\t";
    using Node_char = hbut::Binary_tree<char>::Node;
    hbut::Binary_tree<char> binary_tree(
            new Node_char(
                    'A',
                    new Node_char(
                            'B',
                            new Node_char('D')
                    ),
                    new Node_char(
                            'C',
                            new Node_char('E'),
                            new Node_char('F')
                    )
            )
    );
    binary_tree.level_traversal_print();
    //A B C D E F
    cout<<"\n";
}

void test_vector_to_binary_tree(){
    cout<<"测试顺序存储二叉树转链式：\n\t";

    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};

    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.level_traversal_print();
    //A B C D E F
    cout<<"\n";
}

void test_binary_tree_pre_order_recursive(){
    cout<<"测试二叉树递归前序遍历：\n\t";

    std::vector<char> vec {'A', 'B', 'C', '\0',
                           'D', '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.pre_order_traversal_print_recursive();
    //A B D F C E
    cout<<"\n";
}

void test_binary_tree_pre_order(){
    cout<<"测试二叉树前序遍历：\n\t";

    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.pre_order_traversal_print_recursive();
    cout<<"\n\t";
    bt_from_vec.pre_order_traversal_print_iterative();
    //A B D F C E
    cout<<"\n";
}

void test_power_set(){
    cout<<"测试求幂集：\n\t";
    std::vector<char> ori_set {'a', 'b', 'c'};
    auto power_set {hbut::get_power_set(ori_set)};

    for(auto& set : power_set){
        cout<<"{";
        for(auto& e : set){
            cout<<e<<" ";
        }
        cout<<"}\n\t";
    }
    cout<<"\n";
}

void test_binary_tree_in_order_recursive(){
    cout<<"测试二叉树递归中序遍历：\n\t";
    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.in_order_traversal_print_recursive();
    //B F D A C E
    cout<<"\n";
}

void test_binary_tree_in_order(){
    cout<<"测试二叉树中序遍历：\n\t";
    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.in_order_traversal_print_recursive();
    cout<<"\n\t";
    bt_from_vec.in_order_traversal_print_iterative();
    //B F D A C E
    cout<<"\n";
}

void test_hanoi(){
    cout<<"测试汉诺塔：\n";

    hbut::hanoi(4, 'A', 'B', 'C');
    cout<<"\n";
}

void test_binary_tree_post_order_recursive(){
    cout<<"测试二叉树递归后序遍历：\n\t";
    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.post_order_traversal_print_recursive();
    cout<<"\n";
}

void test_binary_tree_post_order(){
    cout<<"测试二叉树后序遍历：\n\t";
    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.post_order_traversal_print_recursive();
    cout<<"\n\t";
    bt_from_vec.post_order_traversal_print_iterative();
    cout<<"\n";
}

void test_binary_tree_get_depth(){
    cout<<"测试计算二叉树深度：\n\t";

    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    cout<<"深度为："<<bt_from_vec.get_depth();
    //4
    cout<<"\n";
}

void test_recur(const int depth){
    cout<<depth<<"\n";
    test_recur(depth + 1);
}

void test_recursion_optimized_to_iteration(){
    cout<<"测试递归优化为循环：\n";
    test_recur(0);
}

void test_print_binary_tree(){
    cout<<"测试垂直打印二叉树：\n";

    std::vector<char> vec {'A', 'B', 'C', '\0', 'D',
                           '\0', 'E', '\0', '\0', 'F'};
    hbut::Binary_tree<char> bt_from_vec(vec, '\0');
    bt_from_vec.print(20);
    cout<<"\n";
}

void test_binary_tree(){
    cout<<"\n\n***链式存储二叉树***\n";
    test_binary_tree_construction();
    test_huffman_tree();
    test_binary_tree_level_traversal();
    test_vector_to_binary_tree();
    test_binary_tree_pre_order_recursive();
    test_binary_tree_pre_order();
    test_power_set();
    test_binary_tree_in_order_recursive();
    test_binary_tree_in_order();
    test_hanoi();
    test_binary_tree_post_order_recursive();
    test_binary_tree_post_order();
    test_binary_tree_get_depth();
//    test_recursion_optimized_to_iteration();
    test_print_binary_tree();
}

void test_tree_construct(){
    cout<<"测试hbut::Tree构造：\n";
    using Node_char = hbut::Tree<char>::Node;
    hbut::Tree<char> tree(new Node_char('A', {
            Node_char('B', {
                    Node_char('E', {}),
                    Node_char('F', {})
            }),
            Node_char('C', {}),
            Node_char('D', {
                    Node_char('G', {})
            })
    }));
    cout<<"\t在此处设置断点，查看tree的值\n";
}

void test_tree_dfs_pre_order_recursive(){
    cout<<"测试hbut::Tree深度优先递归先根遍历：\n\t";
    using Node_char = hbut::Tree<char>::Node;
    hbut::Tree<char> tree(new Node_char('A', {
            Node_char('B', {
                    Node_char('E', {}),
                    Node_char('F', {})
            }),
            Node_char('C', {}),
            Node_char('D', {
                    Node_char('G', {})
            })
    }));
    tree.DFS_pre_order_print_recursive();
    //A B E F C D G
    cout<<"\n";
}

void test_tree_dfs_pre_order(){
    cout<<"测试hbut::Tree深度优先先根遍历：\n\t";
    using Node_char = hbut::Tree<char>::Node;
    hbut::Tree<char> tree(new Node_char('A', {
            Node_char('B', {
                    Node_char('E', {}),
                    Node_char('F', {})
            }),
            Node_char('C', {}),
            Node_char('D', {
                    Node_char('G', {})
            })
    }));
    tree.DFS_pre_order_print_recursive();
    //A B E F C D G
    cout<<"\n\t";
    tree.DFS_pre_order_print_iterative();
    //A D G C B F E
    cout<<"\n";
}

void test_tree_dfs_post_order_recursive(){
    cout<<"测试hbut::Tree深度优先递归后根遍历：\n\t";
    using Node_char = hbut::Tree<char>::Node;
    hbut::Tree<char> tree(new Node_char('A', {
            Node_char('B', {
                    Node_char('E', {}),
                    Node_char('F', {})
            }),
            Node_char('C', {}),
            Node_char('D', {
                    Node_char('G', {})
            })
    }));
    tree.DFS_post_order_print_recursive();
    //E F B C G D A
    cout<<"\n";
}

void test_tree_bfs(){
    cout<<"测试hbut::Tree广度优先遍历：\n\t";
    using Node_char = hbut::Tree<char>::Node;
    hbut::Tree<char> tree(new Node_char('A', {
            Node_char('B', {
                    Node_char('E', {}),
                    Node_char('F', {})
            }),
            Node_char('C', {}),
            Node_char('D', {
                    Node_char('G', {})
            })
    }));
    tree.BFS_print();
    //A B C D E F G
    cout<<"\n";
}

void test_calculator(){
    cout<<"测试Calculator：\n";
    std::string expression{"add ( sub(2,4) , 2 , mul (2,6), div(4,3))"};
    cout<<"\t计算："<<expression;
    hbut::Calculator calc(expression);
    cout<<"\n\t计算结果为："<<calc.get_result()<<"\n\n";
    //13.3333

    std::string expression2{"add ( sub() , 2 , mul (2,6), div(4,3,5))"};
    cout<<"\t计算："<<expression2<<"\n\t";
    hbut::Calculator calc2(expression2); //报语法错误
    cout<<"\n\t计算结果为："<<calc2.get_result()<<"\n\n";

    std::string expression3{"add sub() , 2 , mul (2,6), div(4,3,5))"};
    cout<<"\t计算："<<expression3<<"\n\t";
    hbut::Calculator calc3(expression3); //报词法错误
    cout<<"\n\t计算结果为："<<calc3.get_result()<<"\n";
}

void test_tree(){
    cout<<"\n\n***树的孩子列表存储***\n";
    test_tree_construct();
    test_tree_dfs_pre_order_recursive();
    test_tree_dfs_pre_order();
    test_tree_dfs_post_order_recursive();
    test_tree_bfs();
    test_calculator();
}


auto create_test_graph(
) -> hbut::Graph<std::string>{
    hbut::Graph<std::string> g;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    g.add_vertex("F");
    
    g.add_edge("A", "B", 3);
    g.add_edge("B", "A", 3);
    g.add_edge("A", "E", 1);
    g.add_edge("E", "A", 1);
    g.add_edge("B", "C", 6);
    g.add_edge("C", "B", 6);
    g.add_edge("B", "D", 1);
    g.add_edge("D", "B", 1);
    g.add_edge("B", "E", 1);
    g.add_edge("E", "B", 1);
    g.add_edge("C", "D", 1);
    g.add_edge("D", "C", 1);
    g.add_edge("D", "E", 4);
    g.add_edge("E", "D", 4);
    g.add_edge("E", "F", 2);
    g.add_edge("F", "E", 2);
    return g;
}

void test_graph_add_vertices_edges(){
    cout<<"测试hbut::graph添加顶点和边\n";
    auto g {create_test_graph()};
    cout<<"\t顶点个数："<<g.vertex_num() //6
        <<"\n\t边个数："<<g.edge_num()   //16
        <<"\n\t编号3的顶点为"<<*g.get_vertex_by_id(3); //D

    //测试添加一个已经存在的顶点
    auto id {g.add_vertex("A")};
    cout<<"\n\t A的id="<<id<<"\n"; //0
    //测试为不存在的顶点添加边
    //g.add_edge("X", "A", 1); //运行终止，提示起点错误
    //g.add_edge("A", "X", 1); //运行终止，提示终点错误
    cout<<"\n";
}

void test_graph_get_edge_weight(){
    cout<<"测试hbut::graph查询边权\n";
    auto g {create_test_graph()};
    cout<<"\t边<D,E>的权值为："
        << *g.get_edge_weight("D", "E");  //4
    cout<<"\n";
}

void test_graph_remove_edge(){
    cout<<"测试hbut::graph删除边\n";
    auto g {create_test_graph()};
    g.remove_edge("B", "E");
    auto weight {g.get_edge_weight("B", "E")};
    if (weight.has_value()){
        cout<<"\t<B,E>边的权值为："<<*weight;
    }else{
        cout<<"\t没有<B,E>边";
    }
    cout<<"\n";
}

void test_graph_remove_vertex(){
    cout<<"测试hbut::graph删除顶点\n";
    auto g {create_test_graph()};
    g.remove_vertex("A");
    auto id {g.get_vertex_id("A")};
    if(id.has_value()){
        cout<<"\tA的id为"<<*id;
    }else{
        cout<<"\tA不存在";
    }
    cout<<"\n";
}

void test_graph_BFS(){
    cout<<"测试hbut::graph广度优先\n\t";
    auto g {create_test_graph()};
    g.BFS_print("A");
    cout<<"\n";
}

void test_graph_DFS_recursive(){
    cout<<"测试hbut::graph递归深度优先\n\t";
    auto g {create_test_graph()};
    g.DFS_print_recursive("A");
    cout<<"\n";
}

void test_graph_DFS_iterative(){
    cout<<"测试hbut::graph迭代深度优先\n\t";
    auto g {create_test_graph()};
    g.DFS_print_iterative("A");
    cout<<"\n";
}

void test_graph_BFS_tree(){
    cout<<"测试hbut::graph广度优先树\n\t";
    auto g {create_test_graph()};
    auto bfs_tree {g.get_BFS_tree("A")};

    cout<<"父亲表示树：\n\t\t顶点：";
    for(int i{0}; i<g.vertex_num(); ++i) cout<<*g.get_vertex_by_id(i)<<" ";
    cout<<"\n\t\t父亲：";
    for(int i{0}; i<g.vertex_num(); ++i){
        auto id {bfs_tree[i]};
        if (id.has_value()){
            cout<<*g.get_vertex_by_id(*id)<<" ";
        } else {
            cout<<"_ ";
        }
    }
    cout<<"\n";
}

void test_graph_DFS_tree(){
    cout<<"测试hbut::graph深度优先树\n\t";
    auto g {create_test_graph()};
    auto bfs_tree {g.get_DFS_tree("A")};

    cout<<"父亲表示树：\n\t\t顶点：";
    for(int i{0}; i<g.vertex_num(); ++i) cout<<*g.get_vertex_by_id(i)<<" ";
    cout<<"\n\t\t父亲：";
    for(int i{0}; i<g.vertex_num(); ++i){
        auto id {bfs_tree[i]};
        if (id.has_value()){
            cout<<*g.get_vertex_by_id(*id)<<" ";
        } else {
            cout<<"_ ";
        }
    }
    cout<<"\n";
}

void test_prim_algorithm(){
    cout<<"测试hbut::graph Prim算法\n\t";
    auto g {create_test_graph()};
    auto [visited, spanning_tree, tree_weight]{g.min_spanning_tree_prim("A")};

    cout<<"最小生成树权值："<<tree_weight<<"\n\t";
    cout<<"父亲表示树：\n\t\t顶点：";
    for(int i{0}; i<g.vertex_num(); ++i) cout<<*g.get_vertex_by_id(i)<<" ";
    cout<<"\n\t\t父亲：";
    for(int i{0}; i<g.vertex_num(); ++i){
        auto id {spanning_tree[i]};
        if (id.has_value()){
            cout<<*g.get_vertex_by_id(*id)<<" ";
        } else {
            cout<<"_ ";
        }
    }
    cout<<"\n\t\t访问：";
    for(int i{0}; i<g.vertex_num(); ++i) cout<<visited[i]<<" ";
    cout<<"\n";
}


void test_kruskal_algorithm(){
    cout<<"测试hbut::graph Kruskal算法\n\t";
    auto g {create_test_graph()};
    auto [edges, tree_weight] {g.min_spanning_tree_kruskal()};

    cout<<"最小生成树权值："<<tree_weight<<"\n\t";
    cout<<"生成树的边：\n";
    for(auto& edge: edges){
        cout<<"\t<"<<edge.from_vertex<<","<<edge.to_vertex<<","<<edge.weight<<">\n";
    }
    cout<<"\n";
}

void test_shortest_path_algorithm(){
    cout<<"测试hbut::graph 最短路径算法\n\t";
    auto g {create_test_graph()};
    auto [path, weight] {g.shortest_path("A", "C")};
    cout<<"A到C最短路径长："<<weight<<"\n\t";
    cout<<"路径为：";
    for(auto& v : path) cout<<v<<" ";
    cout<<"\n";
}

auto create_test_AOE_graph() -> hbut::Graph<std::string>{
    hbut::Graph<std::string> g;

    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    g.add_vertex("F");
    g.add_vertex("G");
    g.add_vertex("H");
    g.add_vertex("I");

    g.add_edge("A", "B", 60);
    g.add_edge("A", "G", 40);
    g.add_edge("A", "H", 50);
    g.add_edge("B", "C", 10);
    g.add_edge("G", "C", 10);
    g.add_edge("C", "D", 90);
    g.add_edge("C", "F", 70);
    g.add_edge("H", "I", 20);
    g.add_edge("I", "F", 40);
    g.add_edge("D", "E", 20);
    g.add_edge("F", "E", 30);
    return g;
}

void test_topology_sort_algorithm(){
    cout<<"测试hbut::graph 拓扑排序算法\n\t";
    auto g {create_test_AOE_graph()};
    auto result {g.topology_sort()};
    for(auto& v_id : *result) cout<<*(g.get_vertex_by_id(v_id))<<' ';
    cout<<"\n";
}

void test_critical_path_algorithm(){
    cout<<"测试hbut::graph 关键路径算法\n";
    auto g {create_test_AOE_graph()};
    g.critical_path_print();
    cout<<"\n";
}

void test_graph(){
    cout<<"\n\n***图***\n";
    test_graph_add_vertices_edges();
    test_graph_get_edge_weight();
    test_graph_remove_edge();
    test_graph_remove_vertex();
    test_graph_BFS();
    test_graph_DFS_recursive();
    test_graph_DFS_iterative();
    test_graph_BFS_tree();
    test_graph_DFS_tree();
    test_prim_algorithm();
    test_kruskal_algorithm();
    test_shortest_path_algorithm();
    test_topology_sort_algorithm();
    test_critical_path_algorithm();
}

void test_std_find(){
    cout<<"测试std::find\n";
    std::vector<int> v{2, 3, 5, 1, 0};
    auto ret {std::find(v.begin(), v.end(), 5)};
    if (ret != v.end()){
        cout<<"\t集合中有5\n";
    }
    ret = std::find(v.begin(), v.end(), 4);
    if (ret == v.end()){
        cout<<"\t集合中没有4\n";
    }
    cout<<"\n";
}

void test_hbut_find(){
    cout<<"测试hbut::find\n";
    std::vector<int> v{2, 3, 5, 1, 0};
    auto ret {hbut::find(v.begin(), v.end(), 5)};
    if (ret != v.end()){
        cout<<"\t集合中有5\n";
    }
    ret = hbut::find(v.begin(), v.end(), 4);
    if (ret == v.end()){
        cout<<"\t集合中没有4\n";
    }
    cout<<"\n";
}

void test_std_binary_search(){
    cout<<"测试std::binary_search\n";
    std::vector<int> v{1,4,7,9,11,12,13,16,19,20};
    auto ret {std::binary_search(v.begin(), v.end(), 16)};
    if (ret){
        cout<<"\t有序集合中有16\n";
    }
    ret = std::binary_search(v.begin(), v.end(), 8);
    if (!ret){
        cout<<"\t有序集合中没有8\n";
    }
    cout<<"\n";
}

void test_hbut_binary_search(){
    cout<<"测试hbut::binary_search\n";
    std::vector<int> v{1,4,7,9,11,12,13,16,19,20};
    auto ret {hbut::binary_search(v.begin(), v.end(), 16)};
    if (ret){
        cout<<"\t有序集合中有16\n";
    }
    ret = hbut::binary_search(v.begin(), v.end(), 8);
    if (!ret){
        cout<<"\t有序集合中没有8\n";
    }
    cout<<"\n";
}

void test_search_methods(){
    cout<<"\n\n***查找***\n";
    test_std_find();
    test_hbut_find();
    test_std_binary_search();
    test_hbut_binary_search();
}


void vector_experiment(){
    cout<<"vector实验\n";
    std::ifstream data_file("../experiment_data/linear_data_structure_experiment.txt");
    if(!data_file.is_open()){
        cout<<"打开文件失败\n";
    }

    std::vector<int> data;
    std::string value;

    auto start_time {std::clock()};
    while(std::getline(data_file, value)){
        data.push_back(std::stoi(value));
    }
    auto end_time{std::clock()};
    cout << "\t读取文件耗时："<< double (end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";

    //在所有0之前插入-1
    start_time = std::clock();
    for(auto iter{data.begin()}; iter!=data.end(); ++iter){
        if(*iter == 0){
            iter = data.insert(iter, -1);
            ++iter;
        }
    }
    end_time = std::clock();
    cout<<"\t插入操作耗时："<<(double)(end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";

    //删除所有0
    start_time = std::clock();
    for(auto iter{data.begin()}; iter!=data.end(); ++iter){
        if(*iter==0){
            iter = data.erase(iter);
            --iter;
        }
    }
    end_time = std::clock();
    cout<<"\t删除操作耗时："<<(double)(end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";
}

void list_experiment(){
    cout<<"list实验\n";
    std::ifstream data_file("../experiment_data/linear_data_structure_experiment.txt");
    if(!data_file.is_open()){
        cout<<"打开文件失败\n";
    }

    std::list<int> data;
    std::string value;

    auto start_time {std::clock()};
    while(std::getline(data_file, value)){
        data.push_back(std::stoi(value));
    }
    auto end_time{std::clock()};
    cout << "\t读取文件耗时："<< double (end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";

    //在所有0之前插入-1
    start_time = std::clock();
    for(auto iter{data.begin()}; iter!=data.end(); ++iter){
        if(*iter == 0){
            iter = data.insert(iter, -1);
            ++iter;
        }
    }
    end_time = std::clock();
    cout<<"\t插入操作耗时："<<(double)(end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";

    //删除所有0
    start_time = std::clock();
    for(auto iter{data.begin()}; iter!=data.end(); ++iter){
        if(*iter==0){
            iter = data.erase(iter);
            --iter;
        }
    }
    end_time = std::clock();
    cout<<"\t删除操作耗时："<<(double)(end_time - start_time)/CLOCKS_PER_SEC<<"秒\n";
}

void linear_data_structure_experiment(){
    cout<<"\n\n***线性结构实验示例***\n\n";
    vector_experiment();
    list_experiment();
}


void heap_sort(std::vector<int>& data){
    std::make_heap(data.begin(), data.end());

    for(auto i{data.size()-1}; i > 0; --i){
        std::pop_heap(data.begin(), data.begin() + i + 1);
    }
}

void bubble_sort(std::vector<int>& data){
    for(auto i{0}; i < data.size() - 1; ++i){
        bool swapped{false};
        for(auto j{0}; j < data.size() - 1 - i; ++j){
            if(data[j] > data[j+1]){
                std::swap(data[j], data[j+1]);
                swapped = true;
            }
        }
        if (!swapped) return;
    }
}


auto read_file_to_vector(const std::string& file) -> std::vector<int>{
    std::ifstream data_file(file);
    if(!data_file.is_open()){
        cout<<"打开文件失败\n";
    }
    std::vector<int> data;
    std::string value;
    while(std::getline(data_file, value)){
        data.push_back(std::stoi(value));
    }

    return data;
}

auto write_vector_to_file(const std::vector<int>& data, const std::string& file){
    std::ofstream  data_file(file);
    if(!data_file.is_open()){
        cout<<"打开文件失败\n";
    }
    for(auto e : data){
        data_file<<std::to_string(e)<<"\n";
    }
}

void comparing_heap_bubble_sort(){
    cout<<"对比堆排序和冒泡排序\n";

    auto heap_sort_data {read_file_to_vector("../experiment_data/heap_experiment.txt")};

    auto start {std::clock()};
    heap_sort(heap_sort_data);
    auto end {std::clock()};
    write_vector_to_file(heap_sort_data, "../experiment_data/out1.txt");
    cout<<"\t堆排序耗时："<<double(end - start)/CLOCKS_PER_SEC<<"\n";

    auto bubble_sort_data{read_file_to_vector("../experiment_data/heap_experiment.txt")};
    start = std::clock();
    bubble_sort(bubble_sort_data);
    end = std::clock();
    write_vector_to_file(heap_sort_data, "../experiment_data/out2.txt");
    cout<<"\t冒泡排序序耗时："<<double(end - start)/CLOCKS_PER_SEC<<"\n";
}

void binary_tree_experiment(){
    cout<<"\n\n***二叉树实验示例***\n\n";

    comparing_heap_bubble_sort();

}