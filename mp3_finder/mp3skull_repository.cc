#include "common.h"
#include "mp3skull_repository.h"

bool MP3SkullRepository::download(std::string url) {
    return true;
}

std::string MP3SkullRepository::search(std::string name) {
    return "";
}

TEST(MainFlow, UTDownloadSuccess) {
    IRepository * repository = new MP3SkullRepository();
    repository->download("Avicii - Wake Me Up (Radio Edit)﻿");
  //EXPECT_EQ(4, Factorial(2));
}
