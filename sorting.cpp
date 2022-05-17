#include "Dataset.h"


void Dataset::bubblesort(){
    float tempd;
    float temph;
    if(sorted) return;
    for(int i = 0 ; i < Data.length(); i++){
        for(int j = 0 ; j < Data.length(); j++){
            if(Data.get(i) <= Data.get(j)){
                temph = heights.get(i);
                heights.set(heights.get(j), i);
                heights.set(temph, j);
                tempd = Data.get(i);
                Data.set(Data.get(j), i);
                Data.set(tempd, j);
                update();
            }
        }
    }
    sorted = true;
}

void Dataset::selectionsort(){
    if(sorted) return;
    for(int i = 0; i < Data.length(); i++){
    float tempd = Data.get(i);
    float temph = heights.get(i);
    int tempj = 0;
        for(int j = i; j < Data.length(); j++){
            if(Data.get(j) <= tempd){
                tempj = j;
                tempd = Data.get(j);
                temph = heights.get(j);
            }
        }
        Data.set(Data.get(i), tempj);
        Data.set(tempd, i);
        heights.set(heights.get(i), tempj);
        heights.set(temph, i);
        update();
    }
    sorted = true;

}