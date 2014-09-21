/* 
 * File:   http_connection.h
 * Author: igor
 *
 * Created on September 21, 2014, 10:39 AM
 */

#ifndef HTTP_CONNECTION_H
#define	HTTP_CONNECTION_H

#include "ihttp_connection.h"


class HttpConnection : public IHttpConnection {
public:
    std::string read(std::string url);
};


#endif	/* HTTP_CONNECTION_H */

