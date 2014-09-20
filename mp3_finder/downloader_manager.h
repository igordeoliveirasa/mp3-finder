#ifndef DOWNLOADER_MANAGER_H
#define	DOWNLOADER_MANAGER_H

#include <vector>
#include "idownloader.h"

class DownloaderManager {
public:
    void add_downloader(IDownloader * downloader);
};

#endif