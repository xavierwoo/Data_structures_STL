//
//  test.cpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/2.
//

#include "test.hpp"
#include "ds_vector.h"
#include "ds_forward_list.h"
#include "ds_list.h"
#include "ds_stack.h"
#include "ds_queue.h"
#include "ds_heap.h"
#include "ds_binary_tree.h"
#include "ds_tree.h"
#include "ds_Calculator.hpp"
#include "ds_graph.h"
#include "ds_algorithms.h"
#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

using std::cout;

auto test_push_back_vector() -> ds::vector<int>{
    cout<<"测试vector::push_back函数：\n";
    ds::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout<<"\t生成的vector包含"<<vec.size()<<"个元素。\n";
    
    return vec;
}

void test_traversal_vector_iterator(){
    cout<<"测试使用迭代器遍历vector：\n\t";
    ds::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    //使用迭代器遍历元素
    for(auto it{vec.begin()}; it!=vec.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<'\n';
}

void test_traversal_vector_grammar_sugar(){
    cout<<"测试使用迭代器语法糖遍历vector：\n\t";
    ds::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    //使用迭代遍历语法糖
    for(auto e : vec){
        cout<<e<<' ';
    }
    //等同于以下代码
    for(auto it{vec.begin()}; it!=vec.end(); ++it){
        auto e {*it};
        cout<<e<<' ';
    }
    cout<<'\n';
}

void test_traversal_vector_index(){
    cout<<"测试使用下标遍历vector：\n\t";
    ds::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    for(auto i{0}; i<vec.size(); ++i){
        vec[i]++;
        cout<<vec[i]<<' ';
    }
    cout<<'\n';

}

void test_vector_iterator_calculation(){
    cout<<"测试vector迭代器运算：\n";
    ds::vector<int> vec;
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
    
    cout<<'\n';
    
}

void test_vector_erase(){
    cout<<"测试vector删除元素：\n\t";
    ds::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    auto it {vec.begin() + 2};
//    auto it {vec.end() - 1};
    auto it_after {vec.erase(it)}; //删除元素
    cout<<"删除第3个元素后，vector为{";
    for(auto e : vec) cout<<e<<' ';// 输出 1 2 4
    cout<<"}。\n\t";
    cout<<"erase返回的迭代器指向"<<*it_after<<"。\n"; //输出 4
}

void test_vector_insert(){
    cout<<"测试vector添加元素：\n\t";
    ds::vector<int> vec;
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

void test_vector_assignment(){
    cout<<"测试vector =操作符：\n\t";
    ds::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    
    ds::vector<int> vec2;
    vec2 = vec1;
    cout<<"vec2为{";
    for(auto e : vec2) cout<<e<<' ';
    cout<<"}\n\t";
    
    vec1.erase(vec1.begin());
    
    cout<<"修改vec1后：\n\t";
    cout<<"vec1为{";
    for(auto e : vec1) cout<<e<<' ';
    cout<<"}\n\t";
    cout<<"vec2为{";
    for(auto e : vec2) cout<<e<<' ';
    cout<<"}\n";
}

void test_vector_move_semantic(){
    cout<<"测试vector移动语义：\n";
    ds::vector<int> vec1 {1,2,3,4};
    ds::vector<int> vec2 {std::move(vec1)};
    
    cout<<"\t vec1.size="<<vec1.size();
    cout<<"\n\t vec2.size="<<vec2.size();
    cout<<'\n';
}

void test_vector(){
    test_traversal_vector_index();
    test_traversal_vector_iterator();
    test_traversal_vector_grammar_sugar();
    test_vector_iterator_calculation();
    test_vector_erase();
    test_vector_insert();
    test_vector_assignment();
    test_vector_move_semantic();
}

void test_forward_list_push_front_and_traversal(){
    cout<<"测试 forward_list::push_front：\n";
    ds::forward_list<int> lst;
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
    cout<<'\n';
}

void test_forward_list_insert_after(){
    cout<<"测试 forward_list::insert_after：\n";
    ds::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    
    cout<<"\t在元素2后插入10：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 2){
            auto ret_it = lst.insert_after(it, 10);
            cout<<"\n\tinsert_after函数返回的迭代器指向："<<*ret_it;
            break;
        }
    }
    
    cout<<"\n\t插入后链表元素为：";
    for(auto e : lst) cout<<e<<' ';
    cout<<'\n';
    
}

void test_forward_list_erase_after(){
    cout<<"测试 forward_list::erase_after：\n";
    ds::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    
    cout<<"\t删除元素3后面的元素：";
    for(auto it{lst.begin()}; it!=lst.end(); ++it){
        if(*it == 3){
            auto ret_it = lst.erase_after(it);
            cout<<"\n\tinsert_after函数返回的迭代器指向："<<*ret_it;
            break;
        }
    }
    
    cout<<"\n\t删除后链表元素为：";
    for(auto e : lst) cout<<e<<' ';
    cout<<'\n';
}

void test_forward_list_reverse(){
    cout<<"测试 forward_list::reverse：\n";
    ds::forward_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    
    lst.reverse();
    
    cout<<"\n\t翻转后链表元素为：";
    for(auto e : lst) cout<<e<<' ';
    cout<<'\n';
}

void test_forward_list(){
//    test_forward_list_push_front_and_traversal();
//    test_forward_list_insert_after();
    test_forward_list_erase_after();
//    test_forward_list_reverse();
}


//using ds::list;
//using std::list;
void test_list_push_back(){
    cout<<"测试 list::push_back：\n";
    ds::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    
    cout<<"\t当前list中元素个数为："<<lst.size()<<'\n';
}

void test_list_traversal(){
    cout<<"测试使用迭代器遍历list：\n\t";
    ds::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    
    for(auto it{lst.begin()}; it != lst.end(); ++it){
        cout<<*it<<' ';
    }
    
    cout<<"\n\t使用迭代器语法糖：";
    for(auto e : lst) cout<<e<<' ';

    auto it {lst.end()};
    --it;
    cout<<std::endl<<*it<<std::endl;

    cout<<'\n';
}

void test_list_insert(){
    cout<<"测试list::insert：\n\t";
    ds::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    
    auto it {lst.begin()};
    ++it;
    it = lst.insert(it, 10);
    
    cout<<"\n\t插入后迭代器指向："<<*it<<'\n';
    for(auto e : lst) cout<<e<<' ';
}

void test_list_erase(){
    cout<<"测试list::erase：\n\t";
    ds::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    
    auto it {lst.begin()};
    ++it;
    
    it = lst.erase(it);
    
    for(auto e : lst) cout<<e<<' ';
    
    cout<<"\n\t删除后迭代器指向："<<*it<<'\n';
}



void test_list(){
    test_list_push_back();
    test_list_traversal();
    test_list_insert();
    test_list_erase();
}

//using ds::stack;
//using std::stack;
void test_stack(){
    cout<<"测试stack：\n";
    ds::stack<int> stk;
    
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    
    cout<<"\t出栈顺序：";
    while(!stk.empty()){
        cout<<stk.top()<<' ';
        stk.pop();
    }
    cout<<'\n';
}

//using ds::queue;
//using std::queue;
void test_queue(){
    cout<<"测试queue：\n";
    ds::queue<int> que;
    
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    
    cout<<"\t出队列顺序：";
    while(!que.empty()){
        cout<<que.front()<<' ';
        que.pop();
    }
    cout<<'\n';
}


void test_max_heap(){
    cout<<"测试大根堆：\n\t";
    ds::vector<int> heap_vec;//
    heap_vec.push_back(0);
    ds::push_heap(heap_vec.begin(), heap_vec.end());
    heap_vec.push_back(4);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(2);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(1);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(3);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    for(auto e : heap_vec)cout<<e<<' ';
    cout<<"\n";
}


void test_heap(){;
    cout<<"测试push_heap：\n\t大根堆：";
    ds::vector<int> heap_vec;
    heap_vec.push_back(0);
    ds::push_heap(heap_vec.begin(), heap_vec.end());
    heap_vec.push_back(4);
    ds::push_heap(heap_vec.begin(), heap_vec.end());
    heap_vec.push_back(2);
    ds:: push_heap(heap_vec.begin(), heap_vec.end());
    heap_vec.push_back(1);
    ds::push_heap(heap_vec.begin(), heap_vec.end());
    heap_vec.push_back(3);
    ds::push_heap(heap_vec.begin(), heap_vec.end());
    for(auto e : heap_vec)cout<<e<<' ';
    cout<<"\n";
    
    heap_vec.clear();
    heap_vec.push_back(3);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(4);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(2);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(1);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    heap_vec.push_back(0);
    ds::push_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    cout<<"\t小根堆：";
    for(auto e : heap_vec)cout<<e<<' ';
    cout<<"\n";
   
    cout<<"测试pop_heap：\n\t";
    ds::pop_heap(heap_vec.begin(), heap_vec.end(), std::greater<int>());
    for(auto e : heap_vec)cout<<e<<' ';
    cout<<'\n';
    
    cout<<"测试make_heap：\n\t";
    ds::vector<int> heap;
    heap.push_back(3);
    heap.push_back(4);
    heap.push_back(2);
    heap.push_back(1);
    heap.push_back(0);
    ds::make_heap(heap.begin(), heap.end());
    for(auto e : heap)cout<<e<<' ';
    cout<<'\n';

}

void test_binary_tree(){
    using ds::Binary_tree;
    cout<<"测试binary_tree：\n";
    Binary_tree<char> bt(new Binary_tree<char>::Node('A',
                                                     new Binary_tree<char>::Node('B'),
                                                     new Binary_tree<char>::Node('C')));
    cout<<'\n';//在此处设置断点调试查看bt
    std::vector<char> vec {'A', 'B', 'C', '\0', 'D', '\0', 'E', '\0', '\0', 'F'};
    Binary_tree<char> bt_from_vec(vec, '\0');
    cout<<'\n';//在此处设置断点调试查看bt_from_vec
    
    cout<<"测试binary_tree层次遍历：\n\t";
    bt_from_vec.level_traversal_print();
    cout<<'\n';
    
    cout<<"测试binary_tree递归前序遍历：\n\t";
    bt_from_vec.pre_order_traversal_print_recursive();
    cout<<'\n';
    
    cout<<"测试binary_tree迭代前序遍历：\n\t";
    bt_from_vec.pre_order_traversal_print_iterative();
    cout<<'\n';
    
    cout<<"测试binary_tree递归中序遍历：\n\t";
    bt_from_vec.in_order_traversal_print_recursive();
    cout<<'\n';
    
    cout<<"测试binary_tree迭代中序遍历：\n\t";
    bt_from_vec.in_order_traversal_print_iterative();
    cout<<'\n';
    
    cout<<"测试binary_tree递归后序遍历：\n\t";
    bt_from_vec.post_order_traversal_print_recursive();
    cout<<'\n';
    
    cout<<"测试binary_tree迭代后序遍历：\n\t";
    bt_from_vec.post_order_traversal_print_iterative();
    cout<<'\n';
    
    cout<<"测试binary_tree垂直打印：\n";
    bt_from_vec.print(40);
    cout<<'\n';
}

void test_huffman_tree(){
    cout<<"测试哈夫曼树：\n";
    std::vector<int> values {7,5,2,4};
    auto huffman_tree {ds::make_huffman_tree(values)};
    huffman_tree.print(40);
    cout<<'\n';
}


void test_tree(){
    cout<<"测试tree类：\n";
    ds::Tree<char> tree(new ds::Tree<char>::Node('A', {
        ds::Tree<char>::Node('B', {
            ds::Tree<char>::Node('E', {}),
            ds::Tree<char>::Node('F', {})
        }),
        ds::Tree<char>::Node('C', {}),
        ds::Tree<char>::Node('D', {
            ds::Tree<char>::Node('G', {})
        })
    }));
    cout<<"\t在此处设置断点，使用watch查看tree的值\n";
    
    cout<<"\t递归式深度优先先根遍历：";
    tree.DFS_pre_order_print_recursive();
    cout<<"\n\t迭代式深度优先先根遍历：";
    tree.DFS_pre_order_print_iterative();
    cout<<"\n\t深度优先后根遍历：";
    tree.DFS_post_order_print_recursive();
    cout<<"\n\t广度优先遍历：";
    tree.BFS_print();
    
    cout<<'\n';
}


void test_calculator(){
    cout<<"测试Calculator：\n";
    std::string expression{"add ( sub(2,4) , 2 , mul (2,6), div(4,3))"};
    cout<<"\t计算："<<expression;
    ds::Calculator calc(expression);
    cout<<"\n\t计算结果为："<<calc.get_result();
    
    cout<<"\n\n";
    std::string expression2{"add ( sub() , 2 , mul (2,6), div(4,3,5))"};
    cout<<"\t计算："<<expression2<<"\n\t";
    ds::Calculator calc2(expression2);
    cout<<"\n\t计算结果为："<<calc2.get_result();
    
    cout<<"\n\n";
    std::string expression3{"add sub() , 2 , mul (2,6), div(4,3,5))"};
    cout<<"\t计算："<<expression3<<"\n\t";
    ds::Calculator calc3(expression3);
    cout<<"\n\t计算结果为："<<calc3.get_result();
    
    cout<<"\n";
}

auto create_test_graph(){
    ds::Graph<std::string> g;
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

void test_graph(){
    cout<<"测试Graph：\n";
    ds::Graph<std::string> g{create_test_graph()};
    
    cout<<"\t边(A,B)的权值为："<<g.get_edge_weight("A", "B");
    cout<<"\n\t边(B,C)的权值为："<<g.get_edge_weight("B", "C");
    g.print();
    
    g.remove_edge("A", "B");
    g.print();
    
    g.remove_vertex("B");
    g.print();
    
    cout<<'\n';
}

void test_graph_traversal(){
    cout<<"测试Graph遍历算法：\n";
    ds::Graph<std::string> g{create_test_graph()};
    
    cout<<"\n\t广度优先遍历：";
    g.BFS_print("A");
    
    cout<<'\n';
    
    cout<<"\n\t深度优先遍历：";
    g.DFS_print_iterative("A");
    
    cout<<'\n';
}

void test_shortest_path(){
    cout<<"测试Graph最短路径：\n";
    ds::Graph<std::string> g{create_test_graph()};
    
    auto [path, weight] {g.shortest_path("A", "C")};
    cout<<"\tA到C的最短路径为：";
    for(auto& v: path) cout<<v<<" ";
    cout<<"\n\t路径长度为："<<weight<<"\n";
}

void test_min_spanning_tree(){
    cout<<"测试最小生成树：\n";
    auto g{create_test_graph()};
    
    cout<<"\tPrim算法结果：";
    auto [tree_edges_p, tree_weight_p] {g.min_spanning_tree_prim("B")};
    for(auto& e: tree_edges_p) cout<<'('<<e.from_vertex<<','<<e.to_vertex<<','<<e.weight<<") ";
    cout<<"\n\t树权值："<<tree_weight_p;
    
    cout<<"\n\tKruskal算法结果：";
    auto [tree_edges_k, tree_weight_k] {g.min_spanning_tree_kruskal()};
    for(auto& e: tree_edges_k) cout<<'('<<e.from_vertex<<','<<e.to_vertex<<','<<e.weight<<") ";
    cout<<"\n\t树权值："<<tree_weight_k;
    
    cout<<'\n';
}

auto create_test_AOE_graph() -> ds::Graph<std::string>{
    ds::Graph<std::string> g;
    
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

void test_critical_path(){
    cout<<"测试拓扑排序：";
    auto g {create_test_AOE_graph()};
    auto result {g.topology_sort()};
    for(auto& v_id : *result) cout<<*(g.get_vertex_by_id(v_id))<<' ';
    
    cout<<"\n测试关键路径：\n";
    g.critical_path_print();
    cout<<'\n';
}

void test_static_data_structure_search(){
    ds::vector<int> data {1,2,4,5,6,9,12};
    cout<<"测试顺序查找：\n";
    
    for (int value : {1,3,9,10}){
        cout<<"\t查找"<<value<<": "
        <<(ds::find(data.begin(), data.end(), value)!= data.end())<<"\n";
    }
    
    cout<<"测试二分查找：\n";
    
    for (int value : {1,3,9,10}){
        cout<<"\t查找"<<value<<": "
        <<ds::binary_search(data.begin(), data.end(), value)<<"\n";
    }
}
