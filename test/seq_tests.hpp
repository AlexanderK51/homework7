#pragma once
#include "container.hpp"
#include <gtest/gtest.h>

TEST (SeqCont, Create)
{
    SeqCont <int> test{};
    ASSERT_EQ(test.size(), 0);
    ASSERT_FALSE(test[0]);
}

TEST (SeqCont, PushBack)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }
    ASSERT_EQ(test.size(), count);
    
    ASSERT_TRUE(test[count -1]);
}

TEST (SeqCont, InsertBegin)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }

    test.insert(50,1);

    ASSERT_EQ(test[1], 50);

    int j = 0;
    for (size_t i = 2; i <= count; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }    
}


TEST (SeqCont, InsertMiddle)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }

    test.insert(100,5);
    test.insert(101,5);
    test.insert(102,5);

    ASSERT_EQ(test[4], 3);
    ASSERT_EQ(test[5], 102);
    ASSERT_EQ(test[6], 101);
    ASSERT_EQ(test[7], 100);
    ASSERT_EQ(test[8], 4);
    ASSERT_EQ(test.size(), 13); 
}

TEST (SeqCont, EraseEnd)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }

    test.erase(9);
    
    int j = 0;
    for (size_t i = 1; i < 9; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }

    ASSERT_EQ(test.size(), 9); 
}

TEST (SeqCont, EraseBegin)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }

    test.erase(1);
    
    int j = 1;
    for (size_t i = 1; i < 9; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }

    ASSERT_EQ(test.size(), 9); 
}

TEST (SeqCont, EraseMiddle)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }

    test.erase(5);
    
    int j = 0;
    for (size_t i = 1; i < 5; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }
    j++;
    for (size_t i = 5; i < 9; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }

    ASSERT_EQ(test.size(), 9); 
}

TEST (SeqCont, Oper)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }    
    int j = 0;
    for (size_t i = 1; i < count; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }
}

TEST (SeqCont, Size)
{
    const size_t count = 10000;
    SeqCont <int> test{};
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
    }    
    ASSERT_EQ(test.size(), count);
}

TEST (SeqCont, Update)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
    }
    test.update(100,5);
    ASSERT_EQ(test[5], 100);

    int j = 0;
    for (size_t i = 1; i < 5; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }
    j++;
    for (size_t i = 6; i < 10; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }
    
}

TEST (SeqCont, CopyConstructor)
{
    const size_t count = 10;
    SeqCont <int> test{};
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
   }
   SeqCont <int> test2{};

   test2 = test;

   for (size_t i = 1; i <= 10; i++){
        ASSERT_EQ(test2[i], test[i]);
    }

}

TEST (SeqCont, MoveConstructor)
{
    const size_t count = 10;
    SeqCont <int> test;
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
    }
    SeqCont <int> test2;
    test2 = std::move(test);
    
    int j = 0;
    for (size_t i = 1; i <= count; i++){
        ASSERT_EQ(test2[i], j);
        j++;
    }
    
}