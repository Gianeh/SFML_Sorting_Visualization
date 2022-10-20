#include "Utility.h"
std::string noSort = "<NO SORT ALGORITHM>";

 std::string Utility::getSortName(int sortType){
    switch(sortType){
        case 0:
            return "BubbleSort";

        case 1:
            return "SelectionSort";

        case 2:
            return "InserctionSort";

        case 3:
            return "CocktailSort";

        case 4:
            return "BogoSort";

        /*case 5:
            return "QuickSort";*/

        default:
            return noSort;
    }
}

bool Utility::hasNext(int sortType){
    return (getSortName(sortType+1))!=noSort;
}



