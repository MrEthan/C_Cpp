//
// Created by wxm_e on 2021/7/31.
//

#ifndef C_CPP_TEST_TIMING_TEST_H
#define C_CPP_TEST_TIMING_TEST_H

#include "gtest/gtest.h"
#include <sys/time.h>

class TimingTest : public testing::Test {
  protected:
    // Remember that SetUp() is run immediately before a test starts.
    // This is a good place to record the start time.
    void SetUp() override
    {
        gettimeofday(&start_time_, nullptr);
    }

    // TearDown() is invoked immediately after a test finishes.  Here we
    // check if the test was too slow.
    void TearDown() override
    {
        // Gets the time when the test finishes
        struct timeval end_time;

        gettimeofday(&end_time, nullptr);

        // Asserts that the test took no more than ~5 seconds.  Did you
        // know that you can use assertions in SetUp() and TearDown() as
        // well?
        EXPECT_TRUE(end_time.tv_sec - start_time_.tv_sec <= 5) << "The test took too long.";
        if (end_time.tv_usec >= start_time_.tv_usec) {
            printf("time cost: %ld.%06lds\n", end_time.tv_sec - start_time_.tv_sec,
                   end_time.tv_usec - start_time_.tv_usec);
        } else {
            printf("time cost: %ld.%06lds\n", end_time.tv_sec - start_time_.tv_sec - 1,
                   end_time.tv_usec + 1 * 1000 * 1000 - start_time_.tv_usec);
        }
    }

    // The UTC time (in seconds) when the test starts
    struct timeval start_time_;
};

#endif // C_CPP_TEST_TIMING_TEST_H