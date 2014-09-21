#ifndef MP3SKULL_DOWNLOADER_H
#define	MP3SKULL_DOWNLOADER_H

#include "irepository.h"
#include "ihttp_connection.h"


class MP3SkullRepository : public IRepository {

    public:
        MP3SkullRepository(const boost::shared_ptr<IHttpConnection> & http_connection) : http_connection_(http_connection) {}
        
        bool download(std::string url, std::string destiny_path);
        std::string search(std::string name);

    private:
        const boost::shared_ptr<IHttpConnection> & http_connection_;

};

#endif	/* MP3SKULL_DOWNLOADER_H */

