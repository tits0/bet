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
    std::cout << "test.testCreateInitialScheme()" << map_error(test.testCreateInitialScheme()) << std::endl;
    std::cout << "test.testCreateScheme()" << map_error(test.testCreateScheme()) << std::endl;
    std::cout << "test.testGetSchemeOptList()" << map_error(test.testGetSchemeOptList()) << std::endl;

    std::cout << "test.testCreateBet()" << map_error(test.testCreateBet()) << std::endl;

    std::cout << "test.testCreateUser()" << map_error(test.testCreateUser()) << std::endl;
    std::cout << "test.testCreateBet()" << map_error(test.testCreateBet()) << std::endl;

	printf("hello world\n");
	return 0;
}
