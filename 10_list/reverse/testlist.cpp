#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>

TEST_CASE("LinkedList") {
    LinkedList list(generate_random(10));
    LinkedList list2(list.get(0));
    std::cout << list << std::endl;
    std::cout << "===========" << std::endl;
    reverse(&list.head);
    std::cout << list << std::endl;

    reverse(&list.head);
    CHECK_EQ(list.get(0)->data, list2.get(0)->data);
    CHECK_EQ(list.get(1)->data, list2.get(1)->data);
    CHECK_EQ(list.get(2)->data, list2.get(2)->data);
    CHECK_EQ(list.get(3)->data, list2.get(3)->data);
    CHECK_EQ(list.get(9)->data, list2.get(9)->data);
}

