/* 
 * File:   mp3_url_parser.cc
 * Author: igor
 * 
 * Created on September 21, 2014, 12:08 PM
 */

#include "default_parser.h"
#include <boost/regex.hpp>

std::vector<std::string> DefaultParser::parse_lines(std::string text, std::string expression) {
    
    std::vector<std::string> ret;
    
    boost::regex e(expression);
    
    std::string::const_iterator start = text.begin();
    std::string::const_iterator end   = text.end();
    boost::match_results<std::string::const_iterator> what;

    while (boost::regex_search(start, end, what, e))
    {
        std::string word(what[1].first, what[1].second);
        // Update the beginning of the range to the character
        // following the whole match
        start = what[0].second;
        ret.push_back(word);
    }    
   return ret;
}


TEST(DefaultParser, ParseOneURL) {
    boost::shared_ptr<IParser> parser;
    parser.reset(new DefaultParser());
    std::vector<std::string> urls = parser->parse_lines("<div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div>", "(http://.+?\\.mp3)");
    EXPECT_EQ(1, urls.size());
}

TEST(DefaultParser, ParseMultiLine) {
    boost::shared_ptr<IParser> parser;
    parser.reset(new DefaultParser());
    
    std::string content = "<div style=\"float:left; height:27px; font-size:13px; padding-top:2px;\">\r\n<div style=\"float:left;\"><a href=\"http://www.ohfool.com/wp-content/uploads/2013/06/01-Wake-Me-Up-Radio-Edit.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div>\r\nteste\r\n";
    
    std::vector<std::string> urls = parser->parse_lines(content, "(http://.+?\\.mp3)");
    EXPECT_EQ(1, urls.size());
}



