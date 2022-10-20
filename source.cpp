#include "PlayGround.h"
//The usage of a distinct object to handle screen and sorting operations gives 
//the chances to use multiple PlayGrounds --> useful for comparisons of complexity

int main(){
	//Main and only needed object
	PlayGround Sorting(1920, 1250, "Sorting PlayGroud", 100, 125);
	//main loop
	Sorting.play();

	return 0;
	
}

