/**
 * @author yangjian 1171267147@qq.com
 * @brief 交换两个变量的值
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    auto swap_func = [](int& a, int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = b ^ a;
    };

    int a = 12, b = 24;
    swap_func(a, b);
    cout << "a = " << a << "\tb = " << b << endl;

    a = -12, b = 24;
    swap_func(a, b);
    cout << "a = " << a << "\tb = " << b << endl;
    
    a = 0, b = 24;
    swap_func(a, b);
    cout << "a = " << a << "\tb = " << b << endl;

    
    a = 10, b = 10;
    swap_func(a, b);
    cout << "a = " << a << "\tb = " << b << endl;

    return 0;
}