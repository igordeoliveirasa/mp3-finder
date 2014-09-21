/* 
 * File:   mp3_url_parser.cc
 * Author: igor
 * 
 * Created on September 21, 2014, 12:08 PM
 */

#include "mp3_url_parser.h"
#include <boost/regex.hpp>

std::vector<std::string> MP3URLParser::parse_lines(std::string text, std::string expression) {
    
    std::vector<std::string> ret;
    
    
    boost::regex e("(http://.+?\\.mp3)");
    
    std::string::const_iterator start = text.begin();
    std::string::const_iterator end   = text.end();
    boost::match_results<std::string::const_iterator> what;

    while (boost::regex_search(start, end, what, e))
    {
        std::string word(what[1].first, what[1].second);
        std::cout << word << std::endl;
        // Update the beginning of the range to the character
        // following the whole match
        start = what[0].second;
        ret.push_back(word);
    }    
   return ret;
}


TEST(MP3URLParser, ParseOneURL) {
    boost::shared_ptr<IParser> parser;
    parser.reset(new MP3URLParser());
    std::vector<std::string> urls = parser->parse_lines("<div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div>");
    EXPECT_EQ(1, urls.size());
}

TEST(MP3URLParser, ParseTwoURL) {
    boost::shared_ptr<IParser> parser;
    parser.reset(new MP3URLParser());
    std::vector<std::string> urls = parser->parse_lines("<div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div><div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix_2.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div>");
    EXPECT_EQ(2, urls.size());
}

TEST(MP3URLParser, ParseWordStylePassingExpression) {
    boost::shared_ptr<IParser> parser;
    parser.reset(new MP3URLParser());
    std::vector<std::string> urls = parser->parse_lines("<div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div><div style=\"float:left;\"><a href=\"http://promodj.com/download/2506513/Scotty_Pirates_Of_The_Caribbean_DJ_RIK_RuDe_Remix_2.mp3\" rel=\"nofollow\" target=\"_blank\" style=\"color:green;\">Download</a></div>", "style");
    EXPECT_EQ(0, urls.size());
}