#ifndef DOWNLOADER_MANAGER_H
#define	DOWNLOADER_MANAGER_H

#include <vector>
#include "idownloader.h"
#include <string>

class DownloaderManager {
public:
    void add_downloader(IDownloader * downloader);
    bool download(std::string name, std::string dest_dir);
};

#endif