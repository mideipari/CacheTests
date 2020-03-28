# Connor Deiparine

I use google test to unit test the caches. I have 8 separate unit tests.

# Test Descriptions:

InitialSizeTest: Tests to make sure cache is initialized to size 0.

InsertTest: Test the set() method of the cache, the get() method, and make sure space_used is updated properly.

ResetTest: Tests to make sure that cache.reset() resets the cache.

OverFlowTest: Tests to make sure cache handles overflow correctly with no evictor.

FiftyInsertsandDelete: Tests to make sure cache can handle 50 inserts and deletes properly.

PermanantDeletion: Makes sure del() actually deletes the value.

FIFOWorks: Tests to see if FIFO evictor works as expected

FFiftyInsertsandDeleteFIFO: Same as before but tests it with FIFO evictor. 

# Part 1:

Output:
```
[==========] Running 8 tests from 3 test suites.

[----------] Global test environment set-up.

[----------] 2 tests from CacheNoEvicition

[ RUN      ] CacheNoEvicition.InitialSizeTest

[       OK ] CacheNoEvicition.InitialSizeTest (0 ms)

[ RUN      ] CacheNoEvicition.InsertTest

[       OK ] CacheNoEvicition.InsertTest (0 ms)

[----------] 2 tests from CacheNoEvicition (0 ms total)


[----------] 4 tests from CacheNoEviction

[ RUN      ] CacheNoEviction.ResetTest

[       OK ] CacheNoEviction.ResetTest (0 ms)

[ RUN      ] CacheNoEviction.OverFlowTest

[       OK ] CacheNoEviction.OverFlowTest (0 ms)

[ RUN      ] CacheNoEviction.FiftyInsertsandDelete

[       OK ] CacheNoEviction.FiftyInsertsandDelete (0 ms)

[ RUN      ] CacheNoEviction.PermanantDeletion

[       OK ] CacheNoEviction.PermanantDeletion (0 ms)

[----------] 4 tests from CacheNoEviction (0 ms total)

[----------] 2 tests from CacheEviction

[ RUN      ] CacheEviction.FIFOWorks

[       OK ] CacheEviction.FIFOWorks (0 ms)

[ RUN      ] CacheEviction.FiftyInsertsandDeleteFIFO

[       OK ] CacheEviction.FiftyInsertsandDeleteFIFO (0 ms)

[----------] 2 tests from CacheEviction (0 ms total)


[----------] Global test environment tear-down

[==========] 8 tests from 3 test suites ran. (0 ms total)

[  PASSED  ] 8 tests.
```

# Part 2

## Eric and Vinay Test Results:
```
[==========] Running 8 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from CacheNoEvicition
[ RUN      ] CacheNoEvicition.InitialSizeTest
[       OK ] CacheNoEvicition.InitialSizeTest (0 ms)
[ RUN      ] CacheNoEvicition.InsertTest
[       OK ] CacheNoEvicition.InsertTest (0 ms)
[----------] 2 tests from CacheNoEvicition (7 ms total)

[----------] 4 tests from CacheNoEviction
[ RUN      ] CacheNoEviction.ResetTest
[       OK ] CacheNoEviction.ResetTest (0 ms)
[ RUN      ] CacheNoEviction.OverFlowTest
[       OK ] CacheNoEviction.OverFlowTest (0 ms)
[ RUN      ] CacheNoEviction.FiftyInsertsandDelete
[       OK ] CacheNoEviction.FiftyInsertsandDelete (0 ms)
[ RUN      ] CacheNoEviction.PermanantDeletion
[       OK ] CacheNoEviction.PermanantDeletion (0 ms)
[----------] 4 tests from CacheNoEviction (14 ms total)

[----------] 2 tests from CacheEviction
[ RUN      ] CacheEviction.FIFOWorks
unit-test.cc:87: Failure
Value of: cachefifo.space_used() == 10
  Actual: false
Expected: true
[  FAILED  ] CacheEviction.FIFOWorks (5 ms)
[ RUN      ] CacheEviction.FiftyInsertsandDeleteFIFO
[       OK ] CacheEviction.FiftyInsertsandDeleteFIFO (0 ms)
[----------] 2 tests from CacheEviction (13 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 3 test suites ran. (46 ms total)
[  PASSED  ] 7 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] CacheEviction.FIFOWorks

 1 FAILED TEST
 ```
 
Everything seems to work for this group except for their space_used updating when the FIFO evictor works. Also the class name for the Fifo evictor seems to be modified from FifoEvictor to Fifo.

## Hien and David Test Results:
```[==========] Running 8 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from CacheNoEvicition
[ RUN      ] CacheNoEvicition.InitialSizeTest
[       OK ] CacheNoEvicition.InitialSizeTest (0 ms)
[ RUN      ] CacheNoEvicition.InsertTest
[       OK ] CacheNoEvicition.InsertTest (0 ms)
[----------] 2 tests from CacheNoEvicition (7 ms total)

[----------] 4 tests from CacheNoEviction
[ RUN      ] CacheNoEviction.ResetTest
unknown file: Failure
C++ exception with description "std::bad_alloc" thrown in the test body.
[  FAILED  ] CacheNoEviction.ResetTest (5 ms)
[ RUN      ] CacheNoEviction.OverFlowTest

Process finished with exit code -1073741819 (0xC0000005)
```

The reset test seems to fail, ignoring that and testing the other tests:


```[==========] Running 6 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from CacheNoEvicition
[ RUN      ] CacheNoEvicition.InitialSizeTest
[       OK ] CacheNoEvicition.InitialSizeTest (0 ms)
[ RUN      ] CacheNoEvicition.InsertTest
[       OK ] CacheNoEvicition.InsertTest (0 ms)
[----------] 2 tests from CacheNoEvicition (6 ms total)

[----------] 2 tests from CacheNoEviction
[ RUN      ] CacheNoEviction.FiftyInsertsandDelete
unknown file: Failure
C++ exception with description "std::bad_alloc" thrown in the test body.
terminate called after throwing an instance of 'std::bad_alloc'
[  FAILED  ] CacheNoEviction.FiftyInsertsandDelete (6 ms)
  what():  std::bad_alloc
[ RUN      ] CacheNoEviction.PermanantDeletion
[       OK ] CacheNoEviction.PermanantDeletion (0 ms)
[----------] 2 tests from CacheNoEviction (12 ms total)

[----------] 2 tests from CacheEviction
[ RUN      ] CacheEviction.FIFOWorks
[       OK ] CacheEviction.FIFOWorks (0 ms)
[ RUN      ] CacheEviction.FiftyInsertsandDeleteFIFO
unknown file: Failure
C++ exception with description "std::bad_alloc" thrown in the test body.
[  FAILED  ] CacheEviction.FiftyInsertsandDeleteFIFO (2 ms)
[----------] 2 tests from CacheEviction (9 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 3 test suites ran. (41 ms total)
[  PASSED  ] 4 tests.
[  FAILED  ] 2 tests, listed below:
[  FAILED  ] CacheNoEviction.FiftyInsertsandDelete
[  FAILED  ] CacheEviction.FiftyInsertsandDeleteFIFO

 2 FAILED TESTS
```

It seems that the cache cannot handle insertion and deletion either.