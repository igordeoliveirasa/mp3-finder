/* 
 * File:   mp3_url_parser.h
 * Author: igor
 *
 * Created on September 21, 2014, 12:08 PM
 */

#ifndef MP3_URL_PARSER_H
#define	MP3_URL_PARSER_H

#include "iparser.h"


class DefaultParser : public IParser {
public:
    std::vector<std::string> parse_lines(std::string text, std::string expression);
private:
};

#endif	/* MP3_URL_PARSER_H */

