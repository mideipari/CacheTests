#include <iostream>
#include <cassert>
#include <typeinfo>
#include <cstring>
#include <stdlib.h>

#include "evictor.hh"
#include "cache.hh"
#include "fifo_evictor.hh"

#include <gtest/gtest.h>

const Cache::val_type set1 = "set1";
const Cache::val_type set2 = "set2";
const Cache::val_type set3 = "set3";
const Cache::val_type set4 = "set4";

Cache::size_type size;

Cache cache(8, 0.75, nullptr);

//Make sure cache starts at size 0
TEST(CacheNoEvicition, InitialSizeTest)
{
    EXPECT_TRUE(cache.space_used() == 0);
}

//test if you can insert and get item
TEST(CacheNoEvicition, InsertTest)
{
    cache.set("key1", set1, strlen(set1)+1);
    std::string test = cache.get("key1", size);
    EXPECT_TRUE(test.compare(set1) == 0 );
    EXPECT_TRUE(cache.space_used() == 5);
    EXPECT_TRUE(size = 5);
}

//make sure reset works
TEST(CacheNoEviction, ResetTest){
    cache.reset();
    EXPECT_TRUE(cache.space_used()==0);
}
//test that cache overflows correctly
TEST(CacheNoEviction, OverFlowTest){
    cache.set("key1", set1, strlen(set1)+1);
    cache.set("key2", set2, strlen(set2)+1);
    cache.set("key3", set3, strlen(set3)+1);
    EXPECT_TRUE(cache.space_used() == 5);
    EXPECT_TRUE(cache.get("key2", size) == nullptr);
    EXPECT_TRUE(cache.get("key3", size) == nullptr);
    cache.reset();
}

//Cache can handle 50 insertions and deletes
TEST(CacheNoEviction, FiftyInsertsandDelete){
    size = 0;
    bool deleted = false;
    for (int i = 0; i < 50; i++){
        cache.set({(char)(i+1), '\0'}, set1, size);
    }
    for (int i = 0; i < 50; i++){
        deleted = cache.del({(char)(i+1), '\0'});
    }
    EXPECT_TRUE(deleted);
    cache.reset();
}

TEST(CacheNoEviction, PermanantDeletion) {
    cache.set("key1", set1, strlen(set1) + 1);
    cache.del("key1");
    EXPECT_TRUE(cache.get("key1", size) == nullptr);
}

FifoEvictor * fifo = new FifoEvictor();
Cache cachefifo(10, 0.75, fifo);
//Cache can handle 50 insertions and deletions again
TEST(CacheEviction, FIFOWorks){


    cachefifo.set("key1", set1, strlen(set1)+1);
    cachefifo.set("key2", set2, strlen(set2)+1);
    cachefifo.set("key3", set3, strlen(set3)+1);

    EXPECT_TRUE(cachefifo.get("key1", size) == nullptr);
    EXPECT_TRUE(cachefifo.get("key2", size) != nullptr);
    EXPECT_TRUE(cachefifo.get("key3", size) != nullptr);
    EXPECT_TRUE(cachefifo.space_used() == 10);
}

TEST(CacheEviction, FiftyInsertsandDeleteFIFO){
    size = 0;
    bool deleted = false;
    for (int i = 0; i < 50; i++){
        cachefifo.set({(char)(i+1), '\0'}, set1, size);
    }
    for (int i = 0; i < 50; i++){
        deleted = cachefifo.del({(char)(i+1), '\0'});
    }
    EXPECT_TRUE(deleted);
    cachefifo.reset();

}

int main(int ac, char* av[])
{

    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}