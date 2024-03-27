#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;


TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++j, ++it) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
    for (int i = 0; i< 4; ++i){
        list.pop_back();
    }
    List<int>::Iterator he = list.begin();
    ASSERT_EQUAL(*he,0);
    list.pop_back();
    ASSERT_TRUE(list.empty());
}
TEST(test_popandpushfront) {
    List<int> list;
        list.push_front(1);
   
    int j = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++j, ++it) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(1, list.size());
    list.pop_front();
    ASSERT_TRUE(list.empty());
}
TEST_MAIN()
