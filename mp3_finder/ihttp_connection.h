/* 
 * File:   http_connection.h
 * Author: igor
 *
 * Created on September 21, 2014, 10:39 AM
 */

#ifndef IHTTP_CONNECTION_H
#define	IHTTP_CONNECTION_H

#include "common.h"

class IHttpConnection {
public:
    virtual std::string read(std::string domain, std::string page) = 0;
};

#endif	/* HTTP_CONNECTION_H */

