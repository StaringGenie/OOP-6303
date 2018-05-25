#include <memory>
#include <iostream>
#include <functional>
#include <string>
#include <stdexcept>
#include <utility>
#include <cstddef>

#include "sharedptr.h"

using namespace stepik;

struct A
{
    int a;

    explicit A(int a) : a(a) {}
};

struct B : A
{
    int b;
    B(int a, int b) : A(a), b(b) {}
};

int main()
{
    shared_ptr<B> sp1(new B(1,2));
    shared_ptr<A> sp2 = sp1;
    sp2 = sp1;

    std::cout << (sp1 == sp2);
    std::cout << (sp1 == nullptr);
    std::cout << (nullptr == sp1);
    std::cout << std::endl;

    std::cout << (sp1 != sp2);
    std::cout << (sp1 != nullptr);
    std::cout << (nullptr != sp1);
    std::cout << std::endl;

    std::cout << (sp1 < sp2);
    std::cout << (sp1 < nullptr);
    std::cout << (nullptr < sp2);
    std::cout << std::endl;

    std::cout << (sp1 > sp2);
    std::cout << (sp1 > nullptr);
    std::cout << (nullptr > sp2);
    std::cout << std::endl;

    std::cout << (sp1 <= sp2);
    std::cout << (sp1 <= nullptr);
    std::cout << (nullptr <= sp2);
    std::cout << std::endl;

    std::cout << (sp1 >= sp2);
    std::cout << (sp1 >= nullptr);
    std::cout << (nullptr >= sp2);
    std::cout << std::endl;

    return 0;
}