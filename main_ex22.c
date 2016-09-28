#include "dbg.h"
#include "ex22.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
	log_info("count is: %d", count);
	
	if(count>10){
		int count = 100;
		log_info("Count within this scope is: %d", count);	
	}

	log_info("Count is at exit: %d", count);
	count = 3000;
	log_info("Count after assignment is: %d", count);
}


int main (int argc, char* argv[])
{

	log_info("My name is %s, my age is %d", MY_NAME, get_age());
	set_age(100);
	log_info("My age now is: %d", get_age());

	log_info("THE_SIZE is: %d", THE_SIZE);
	THE_SIZE = 9;
	log_info("THE_SIZE is now: %d", THE_SIZE);

	//test ration function
	log_info("Ratio is: %f", update_ratio(2.0));
	log_info("Update ratio again to: %f", update_ratio(300.0));
	log_info("Update ratio once again: %f", update_ratio(1000.0));

	//let's test scope_demo madness
	int count = 4;
	scope_demo(count);
	scope_demo(count*20);
	log_info("Count after scope_demo: %d", count);

	return 0;
}

	
