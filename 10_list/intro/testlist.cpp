#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>

TEST_CASE("LinkedList") {
    LinkedList list;
    CHECK_EQ(list.size(), 0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    CHECK_EQ(list.size(), 3);
    CHECK_EQ(list.get(0)->data, 1);
    CHECK_EQ(list.get(1)->data, 2);
    CHECK_EQ(list.get(2)->data, 3);

    list.insert_node(4, 1);
    CHECK_EQ(list.size(), 4);
    CHECK_EQ(list.get(0)->data, 1);
    CHECK_EQ(list.get(1)->data, 4);
    CHECK_EQ(list.get(2)->data, 2);
    CHECK_EQ(list.get(3)->data, 3);

    list.delete_node(2);
    CHECK_EQ(list.size(), 3);
    CHECK_EQ(list.get(0)->data, 1);
    CHECK_EQ(list.get(1)->data, 4);
    CHECK_EQ(list.get(2)->data, 3);

    LinkedList list2(list.get(0));
    CHECK_EQ(list.get(0)->data, list2.get(0)->data);
    CHECK_EQ(list.get(1)->data, list2.get(1)->data);
    CHECK_EQ(list.get(2)->data, list2.get(2)->data);

    std::cout << "list: " << std::endl << list << std::endl;
    std::cout << "list2: " << std::endl  << list2 << std::endl;
}

