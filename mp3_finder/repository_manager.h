#ifndef DOWNLOADER_MANAGER_H
#define	DOWNLOADER_MANAGER_H

#include <vector>
#include "irepository.h"
#include <string>

class RepositoryManager {
public:
    void add_repository(IRepository * repository);
    bool download(std::string name, std::string dest_dir);
};

#endif