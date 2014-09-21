#ifndef MP3SKULL_DOWNLOADER_H
#define	MP3SKULL_DOWNLOADER_H

#include "irepository.h"

class MP3SkullRepository : public IRepository {

    public:
      bool download(std::string url);
      std::string search(std::string name);

    private:

};

#endif	/* MP3SKULL_DOWNLOADER_H */

