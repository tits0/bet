#include <stdio.h>
#include "pgdbcommon.h"
#include "ConfigLocal.h"
#include <boost/program_options.hpp>
namespace po = boost::program_options;
int testdbmain(int argc, char **argv)
{
	printf("hello world\n");
    testpgdbcommon  test;  
    test.testCreateScheme();
	return 0;
}

int main(int argc, char **argv)
{
    int initdb=0;
    int dryrun=0;
    ConfigLocal::Instance()->readConfigFile();
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("initdb", "Initialize database")
        ("dryrun", "dry run");
 
    po::variables_map vm; 
    testpgdbcommon  test;
    try 
    { 
      po::store(po::parse_command_line(argc, argv, desc),  vm); // can throw 
      po::notify(vm);
      /** --help option 
       */ 
      if ( vm.count("help")  ) 
      { 
        std::cout << "Command Line " << std::endl 
                  << desc << std::endl; 
        return ERROR_OK; 
      } 
 
      /** --initdb option 
       */ 
      std::cout << "initdb " << vm.count("initdb")  << std::endl ;
      if ( vm.count("initdb")  ) 
      {
        std::cout << "initdb test.testCreateInitialScheme()" << map_error(test.testCreateInitialScheme()) << std::endl;
        return ERROR_OK;
      }

       /** --test option 
       */ 
      std::cout << "dryrun " << vm.count("dryrun")  << std::endl ;
      if ( vm.count("dryrun")  ) 
      {
        std::cout << "dryrun\n"  << std::endl;
        std::cout << "test.testCreateInitialScheme()" << map_error(test.testCreateInitialScheme()) << std::endl;
        std::cout << "test.testCreateScheme()" << map_error(test.testCreateScheme()) << std::endl;
        std::cout << "test.testGetSchemeOptList()" << map_error(test.testGetSchemeOptList()) << std::endl;
        std::cout << "test.testCreateBet()" << map_error(test.testCreateBet()) << std::endl;
        std::cout << "test.testCreateUser()" << map_error(test.testCreateUser()) << std::endl;
        std::cout << "test.testCreateBet()" << map_error(test.testCreateBet()) << std::endl;
        return ERROR_OK;
      }

      po::notify(vm); // throws on error, so do after help in case 
                      // there are any problems 
    } 
    catch(po::error& e) 
    { 
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
      std::cerr << desc << std::endl; 
      return ERROR_IN_COMMAND_LINE; 
    }

	printf("hello world\n");
	return 0;
}
