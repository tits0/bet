#include <stdio.h>
#include "pgdbcommon.h"
#include "ConfigLocal.h"

int testdbmain(int argc, char **argv)
{
	printf("hello world\n");
    testpgdbcommon  test;  
    test.testCreateScheme();

	return 0;
}

int main(int argc, char **argv)
{
    ConfigLocal::Instance()->readConfigFile();
    testpgdbcommon  test;
    test.testCreateInitialScheme();
    test.testCreateScheme();
    test.testCreateBet();
    test.testGetSchemeOptList();
	printf("hello world\n");
	return 0;
}
