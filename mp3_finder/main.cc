#include <cstdlib>
#include <gtest/gtest.h>
#include <vector>
#include "downloader_manager.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

int Factorial(int n) {
    return n*2;
}

// Tests factorial of 0.
TEST(MainFlow, DownloadSuccess) {
    DownloaderManager downloader_manager;
    downloader_manager.add_downloader(  );
    downloader_manager.add_downloader("Avicii - Wake Me Up (Radio Edit)﻿");
  EXPECT_EQ(5, Factorial(2));
}
