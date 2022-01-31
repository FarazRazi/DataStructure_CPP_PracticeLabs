#include "pch.h"
#include "toTest.h"

TEST(small, T1) {
    EXPECT_EQ(1, smaller<int>(4, 1));
    EXPECT_EQ(2, smaller(8.0, 9.0));   //this will be false
}
TEST(small, T2) {
    EXPECT_EQ('a', smaller('a', 'c'));
    EXPECT_EQ('f', smaller('f', 'z'));
}

TEST(smaller, T1) {
    EXPECT_EQ(1, smaller(4, 1, 2));
    EXPECT_EQ(3.5, smaller(8.0, 9.0, 3.5));
}
TEST(smaller, T2) {
    EXPECT_EQ('a', smaller('a', 'c', 's'));
    EXPECT_EQ('f', smaller('f', 'z'));
}
//
//container Class

container<int> obj(5);
TEST(container, insert) {
    EXPECT_EQ(1, obj.insert(1));
    EXPECT_EQ(1, obj.insert(56));
    EXPECT_EQ(1, obj.insert(11));
    EXPECT_EQ(1, obj.insert(5));


}
TEST(container, search) {
    //EXPECT_TRUE(true, obj.insert(6));
    EXPECT_EQ(1, obj.search(11));

}

TEST(container, remove) {
    /**/
    obj.insert(3);
    EXPECT_EQ(true, obj.remove(11));
}
TEST(container, isFull) {
    EXPECT_EQ(1, obj.insert(15));
    EXPECT_EQ(true, obj.isFull());
}

/*for char you have to write test cases ::
as home task fo your own testing.. Only for task 4*/