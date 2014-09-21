/* 
 * File:   iparser.h
 * Author: igor
 *
 * Created on September 21, 2014, 12:01 PM
 */

#ifndef IPARSER_H
#define	IPARSER_H

#include "common.h"

class IParser {
public:
    virtual std::vector<std::string> parse_lines(std::string text, std::string expression) = 0;
};

#endif	/* IPARSER_H */

