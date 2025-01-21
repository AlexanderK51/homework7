#pragma once
#include "container.hpp"
#include <vector>
#include <gtest/gtest.h>

TEST (ListCont, Create)
{
    ListCont <int> test{};
    ASSERT_EQ(test.size(), 0);
    ASSERT_FALSE(test[0]);
}

TEST (ListCont, PushBack)
{
    const size_t count = 10;
    ListCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }
    ASSERT_EQ(test.size(), count);
    ASSERT_TRUE(test[count]);
}

TEST (ListCont, InsertBegin)
{
    const size_t count = 10;
    ListCont <int> test{};
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

TEST (ListCont, InsertMiddle)
{
    const size_t count = 10;
    ListCont <int> test{};
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

TEST (ListCont, EraseEnd)
{
    const size_t count = 10;
    ListCont <int> test{};
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

TEST (ListCont, EraseBegin)
{
    const size_t count = 10;
    ListCont <int> test{};
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

TEST (ListCont, EraseMiddle)
{
    const size_t count = 10;
    ListCont <int> test{};
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

TEST (ListCont, Oper)
{
    const size_t count = 10;
    ListCont <int> test{};
    for (size_t i = 0; i < 10; i++){
        test.push_back(i);
    }    
    int j = 0;
    for (size_t i = 1; i < count; i++){
        ASSERT_EQ(test[i], j);
        j++;
    }
}

TEST (ListCont, Size)
{
    const size_t count = 10000;
    ListCont <int> test{};
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
    }    
    ASSERT_EQ(test.size(), count);
}

TEST (ListCont, Update)
{
    const size_t count = 10;
    ListCont <int> test{};
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

// TEST (ListCont, CopyConstructor)
// {
//     const size_t count = 10;
//     ListCont <int> test{};
//     for (size_t i = 0; i < count; i++){
//         test.push_back(i);
//     }
//     ListCont <int> test2{};

//     test2 = test;

//     int j = 0;
//     for (size_t i = 0; i < 10; i++){
//         ASSERT_EQ(test2[i], test[i]);
//         j++;
//     }

// }

TEST (ListCont, MoveConstructor)
{
    const size_t count = 10;
    ListCont <int> test;
    for (size_t i = 0; i < count; i++){
        test.push_back(i);
    }
    std::vector <ListCont <int>> v_test;
    v_test.push_back(test);
    int j = 0;
    for (size_t i = 0; i < count; i++){
        ASSERT_EQ(v_test[i][i], test[i]);
    }
}