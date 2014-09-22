#ifndef MP3SKULL_DOWNLOADER_H
#define	MP3SKULL_DOWNLOADER_H

#include "irepository.h"
#include "ihttp_connection.h"
#include "iparser.h"


class MP3SkullRepository : public IRepository {

    public:
        MP3SkullRepository(const boost::shared_ptr<IHttpConnection> & http_connection, const boost::shared_ptr<IParser> & parser) : http_connection_(http_connection), parser_(parser) {}
        
        bool download(std::string url, std::string destiny_path);
        std::string search(std::string name);
        std::string convert_to_restfull_style(std::string terms);

    private:
        const boost::shared_ptr<IHttpConnection> & http_connection_;
        const boost::shared_ptr<IParser> & parser_;

};

#endif	/* MP3SKULL_DOWNLOADER_H */

