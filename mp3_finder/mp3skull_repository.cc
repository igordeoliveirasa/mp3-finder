#include "common.h"
#include "mp3skull_repository.h"
#include "http_connection.h"

bool MP3SkullRepository::download(std::string url, std::string destiny_path) {
    return true;
}

std::string MP3SkullRepository::search(std::string name) {
    return "";
}

TEST(MainFlow, UTDownloadSuccess) {
    boost::shared_ptr<IHttpConnection> http_connection;
    http_connection.reset(new HttpConnection());

    boost::shared_ptr<IRepository> repository;
    repository.reset(new MP3SkullRepository(http_connection));
    
    bool ret = repository->download("Avicii - Wake Me Up (Radio Edit)﻿", "/tmp/music.mp3");
    EXPECT_EQ(true, ret);
}
