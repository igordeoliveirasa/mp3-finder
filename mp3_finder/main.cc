#include <cstdlib>
#include <gtest/gtest.h>
#include <vector>
#include "repository_manager.h"
#include "mp3skull_repository.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

int Factorial(int n) {
    return n*2;
}

// Tests factorial of 0.
TEST(MainFlow, STDownloadSuccess) {
    RepositoryManager repository_manager;
    repository_manager.add_downloader( new MP3SkullRepository() );
    repository_manager.download("Avicii - Wake Me Up (Radio Edit)﻿", "/tmp");
  EXPECT_EQ(4, Factorial(2));
}
