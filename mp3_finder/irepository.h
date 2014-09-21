#ifndef IDOWNLOADER_H
#define	IDOWNLOADER_H

#include "common.h"

class IRepository
{
   public:
      virtual bool download(std::string url, std::string destiny_path) = 0;
      virtual std::string search(std::string name) = 0;
};

#endif