#ifndef IDOWNLOADER_H
#define	IDOWNLOADER_H

#include <vector>

class IRepository
{
   public:
      virtual bool download(std::string url) = 0;
      virtual std::string search(std::string name) = 0;
};

#endif