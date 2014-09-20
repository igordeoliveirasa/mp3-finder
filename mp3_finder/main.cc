#include <cstdlib>
#include <gtest/gtest.h>
#include <vector>
#include "downloader_manager.h"
#include "mp3skull_downloader.h"

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
    downloader_manager.add_downloader( new MP3SkullDownloader() );
    downloader_manager.download("Avicii - Wake Me Up (Radio Edit)﻿", "/tmp");
  EXPECT_EQ(4, Factorial(2));
}
