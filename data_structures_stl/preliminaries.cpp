//
//  preliminaries.cpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/3.
//

#include "preliminaries.hpp"
#include <iostream>
#include <string>
#include <utility>

using std::cout;
struct TestAssignObj{
    TestAssignObj(){cout<<"构造函数\n";}
    TestAssignObj(const TestAssignObj &other){cout<<"拷贝构造函数\n";}
    auto operator=(const TestAssignObj &other) -> TestAssignObj&{
        cout<<"=操作符\n";
        return *this;
    }
};

void explain_initial_assignment(){
    cout<<"测试拷贝构造函数与=操作符：\n";
    TestAssignObj a;     //调用构造函数
    TestAssignObj b{a};  //调用拷贝构造函数
    TestAssignObj c = b; //调用拷贝构造函数
    c = a;               //调用=操作符
}

struct ComplexInt{
    int real;
    int imaginary;
    
    auto operator+(const ComplexInt &other) -> ComplexInt{
        ComplexInt res;
        res.real = real + other.real;
        res.imaginary = imaginary + other.imaginary;
        return res;
    }
    
    auto operator++() -> ComplexInt&{
        real++;
        imaginary++;
        return *this;
    }
    
    auto operator++(int) -> ComplexInt{
        ComplexInt tmp{*this};
        real++;
        imaginary++;
        return tmp;
    }
};

void explain_operator_overloading(){
    cout<<"测试运算符重载：\n";
    ComplexInt a{2,1};
    ComplexInt b{1,3};
    
    ComplexInt c {a + b};
    cout<<"c.real="<<c.real<<", c.imaginary="<<c.imaginary<<'\n';
    ++c;
    cout<<"c.real="<<c.real<<", c.imaginary="<<c.imaginary<<'\n';
    
    auto d {c++};
    cout<<"c.real="<<c.real<<", c.imaginary="<<c.imaginary<<'\n';
    cout<<"d.real="<<d.real<<", d.imaginary="<<d.imaginary<<'\n';
}


struct A{
    int data;
    A() = default;

    A(const A &d) = delete;
//    A(A&&){
//        cout<<"move constructor";
//    };
    //    A() = delete;
    //    A(const int &d): data(d){};
};

void explain_array_limitations(){
    A arr_of_a[10]; //编译错误：Call deleted constructor of A
    arr_of_a[0].data = 9;
    //...
    
//    std::vector<A> vec;
//    vec.emplace_back();
//    
//    vec[0].data = 1;
}


void test_left_right_value(const std::string& value){
    std::cout<<"左值"<<value<<"\n";
}

void test_left_right_value(std::string&& value){
    std::cout<<"右值"<<value<<"\n";
}

void explain_move_semantic(){
    std::string a{"abcdes"};
    std::string b;
    
    b = std::move(a);
    std::cout<<"a:"<<a<<"\nb:"<<b<<'\n';
    
    test_left_right_value(b);
    test_left_right_value(std::move(b));
    test_left_right_value("abc");
}
