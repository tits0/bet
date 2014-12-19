#include <stdio.h>
#include "pgdbcommon.h"

int testdbmain(int argc, char **argv)
{
	printf("hello world\n");
    testpgdbcommon  test;  
    test.testCreateScheme();

	return 0;
}

int main(int argc, char **argv)
{
    testpgdbcommon  test;  
    test.testCreateInitialScheme();
    test.testCreateScheme();
    
	printf("hello world\n");
	return 0;
}
