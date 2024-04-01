#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

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
TEST(equaloperator){
    List<int> list;
    List <int> listcopy; 
    list.push_back(1);
    listcopy.push_front(3);
    listcopy.push_front(2);
    list = listcopy; 
    List<int>::Iterator it =list.begin();
    ASSERT_EQUAL(*it,2);
    ++it;
    ASSERT_EQUAL(*it,3);
    ASSERT_EQUAL(2, list.size());
    List<int> empty; 
    list = empty; 
    ASSERT_TRUE(list.empty());
}
TEST(empty){
    List<int> list; 
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(0,list.size());
    list.push_back(1);
    list.pop_back();
    ASSERT_TRUE(list.empty());
    List<int> listcopy; 
    listcopy.push_back(3);
    listcopy.push_back(2);
    listcopy.pop_front();
    ASSERT_FALSE(listcopy.empty());
    List<int> help;
    help.push_front(69);
    list=help;
    ASSERT_TRUE(list.front()==69);
    ASSERT_TRUE(list.back()==69);
    ASSERT_TRUE(list.size()==1);
}
TEST(frontandback){
    List<int> list; 
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(0,list.size());
    list.push_back(1);
    ASSERT_EQUAL(1,list.front());
    ASSERT_EQUAL(1,list.back());
    ASSERT_EQUAL(1,list.size());
    List<int> listcopy; 
    listcopy.push_back(3);
    listcopy.push_back(1);
    listcopy.push_back(2);
    ASSERT_EQUAL(2,listcopy.back());
    ASSERT_EQUAL(3, listcopy.size());
    ASSERT_EQUAL(3,listcopy.front());
    listcopy.clear();
    ASSERT_TRUE(listcopy.empty());
    ASSERT_EQUAL(0,listcopy.size());
    }
    TEST(bigthree){
    List<int> listcopy; 
     listcopy.push_back(1);
     listcopy.push_back(2);
        listcopy.push_back(3);
        List<int> list (listcopy);
        ASSERT_EQUAL(1,list.front());
        ASSERT_EQUAL(3, list.size());
        ASSERT_EQUAL(3,list.back());
        int i = 1; 
        for (List<int>::Iterator it = list.begin();it!=list.end();++i,++it){
          ASSERT_EQUAL(i, *it);
        }
    }
    TEST(iteratoroperatorpostfix){
       List<int> list; 
       list.push_back(1);
       list.push_back(2);
       list.push_back(3);
       List<int>::Iterator it = list.begin();
       List<int>::Iterator itcopy = list.begin();
       ASSERT_TRUE(it==itcopy);
       ASSERT_FALSE(it!=itcopy);
       ++it;
       it++;
       ASSERT_EQUAL(3,*it);
       ASSERT_FALSE(it==itcopy);
       --it;
       --it;
       ASSERT_EQUAL(1,*it);
       it++;
       ASSERT_FALSE(it==itcopy);
       ASSERT_TRUE(it!=itcopy);
       ASSERT_EQUAL(2,*it);
       ++it;
       ASSERT_FALSE(it==itcopy);
       ASSERT_TRUE(it!=itcopy);
       ASSERT_EQUAL(3,*it);
    }
    TEST(moreiterator){
        List<int>::Iterator help;
        List<int>::Iterator helpcopy;
        ASSERT_TRUE(help==helpcopy);
        ASSERT_FALSE(help!=helpcopy);
        List<int> lit; 
        lit.push_back(39);
        lit.push_back(24);
        lit.push_back(3);
        List<int>::Iterator list = lit.end();
        ASSERT_FALSE(list==help);
        ASSERT_TRUE(list!=helpcopy);
        --list;
        List<int>::Iterator yum = lit.begin(); 
        ASSERT_TRUE(list!= yum);
        ASSERT_FALSE(list==yum);
        ++yum;
        ++yum;
        ASSERT_TRUE(list==yum);
        ASSERT_FALSE(list!= yum);
    }
    TEST(copyconstructor){
        List<int> list;
        list.push_back(1);
        list.push_back(2);
        List<int> listcopy(list);
        ASSERT_TRUE(listcopy.front()==1);
        ASSERT_TRUE(listcopy.back()==2);
        ASSERT_TRUE(listcopy.size()==2);
        List<int> empty;
        List<int> emptycopy (empty);
        ASSERT_TRUE(emptycopy.empty());
        ASSERT_EQUAL(emptycopy.size(),0);
    }
    TEST(selfassignment){
        List<int> list; 
        list.push_back(1);
        list.push_back(3);
        list.push_back(9);
        List <int> &copy = list;
        copy=list;
        ASSERT_TRUE(list.size()==3);
        ASSERT_TRUE(list.front()==1);
        ASSERT_TRUE(list.back()==9);
        ASSERT_TRUE(copy.size()==3);
        ASSERT_TRUE(copy.front()==1);
        ASSERT_TRUE(copy.back()==9);
        List<int>::Iterator it = list.begin();
        ++it;
        ASSERT_EQUAL(*it,3);
    }
    TEST(erasetest){
        List<int> list; 
       list.push_back(1);
       list.push_back(2);
       list.push_back(3);
        List<int>::Iterator it = list.begin();
        List<int>::Iterator output = list.erase(it); //use erase on the first  
        ASSERT_EQUAL(*output,2);
        ASSERT_EQUAL(list.front(),2);
        List<int>::Iterator help = list.erase(output); // use erase first
        ASSERT_EQUAL(*help,3);
        list.erase(help);  //erase one and only 
        ASSERT_TRUE(list.empty());
    }
    TEST(inserttest){
        List<int> list; 
       list.push_back(1);
        List<int>::Iterator it = list.begin();
        List<int>::Iterator output = list.insert(it,2); //insert begin 
        ASSERT_EQUAL(*output,2);
        ASSERT_EQUAL(list.size(),2);
        List<int>::Iterator help = list.insert(output,3); //insert begin 
        ASSERT_EQUAL(*help,3);
        ASSERT_EQUAL(list.size(),3);
    }
    TEST(insertthenerase){
        List<int>list;
        List<int>::Iterator it = list.begin();
        List<int>::Iterator output = list.insert(it,1); // insert empty 
        ASSERT_EQUAL(*(list.begin()),1);
        ASSERT_EQUAL(*output,1);
        ASSERT_EQUAL(list.size(),1);
        list.erase(list.begin());// use erase on end 
        ASSERT_TRUE(list.empty());
    }
    TEST(insertthenerase2){
        List<int>list;
        List<int>::Iterator it = list.begin();
        List<int>::Iterator output = list.insert(it,1);
        ASSERT_EQUAL(*(list.begin()),1);
        ASSERT_EQUAL(*output,1);
        ASSERT_EQUAL(list.size(),1);
        list.erase(list.begin());
        ASSERT_TRUE(list.empty());
    }
    TEST(ineedhelp){
        List<int>list;
        list.push_back(3);
        list.push_back(5);
        list.push_back(9);
        list.push_back(34);
        List<int>::Iterator it = list.end();
        List<int>::Iterator in = list.insert(it,4);//insert at back 
        ASSERT_EQUAL(*in,4);
        ASSERT_EQUAL(list.back(),4);
        --it; 
        List<int>::Iterator meep = list.insert(it,4);
        ASSERT_EQUAL(*meep,4);
    }
    TEST(backwards){
        List<int> list; 
       list.push_back(1);
       list.push_back(2);
       list.push_back(3);
        list.push_back(4);
       list.push_back(5);
       list.push_back(6);
       list.push_back(7);
       list.push_back(8);
       list.push_back(9);
       List<int>::Iterator it = list.end();
       --it;
       int j = 9;
       for (;it!=list.begin();--it,--j){
            ASSERT_EQUAL(*it, j);
       }
       ASSERT_EQUAL(*it,1);
    }
TEST_MAIN()
