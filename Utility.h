#ifndef _UTILITY_
#define _UTILITY_
#include <string>


//Useful namespace to retrieve sorting algorithms names
namespace Utility {
    std::string getSortName(int sortType);
    //checks if next sorts exists
    bool hasNext(int sortType);
}

#endif

