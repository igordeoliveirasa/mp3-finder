/* 
 * File:   http_connection.cc
 * Author: igor
 * 
 * Created on September 21, 2014, 10:39 AM
 */

#include "http_connection.h"
#include <boost/asio.hpp>
#include <boost/iostreams/seek.hpp>
#include <boost/iostreams/device/array.hpp>


std::string HttpConnection::read(std::string url) {
    
    boost::asio::ip::tcp::iostream stream;
    stream.expires_from_now(boost::posix_time::seconds(60));
    stream.connect(url, "http");
    stream << "GET / HTTP/1.0\r\n";
    stream << "Host: " << url << "\r\n";
    stream << "Accept: */*\r\n";
    stream << "Connection: close\r\n\r\n";
    stream.flush();

    //std::cout << stream.rdbuf();    
    //std::cout << boost::iostreams::seek(stream.rdbuf(), 0, BOOST_IOS::end);
    
    std::ostringstream ret;
    ret << stream.rdbuf();
    return ret.str();
}

TEST(HttpConnection, ReadSuccess) {
    boost::shared_ptr<IHttpConnection> http_connection;
    http_connection.reset(new HttpConnection());
    
    std::string ret = http_connection->read("http://www.google.com");
    
    std::cout << ret;
    
    EXPECT_EQ("<title>", ret);
}
