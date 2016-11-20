#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <random>
#include <fstream>

#define min 1
#define max 3

int main(int argc, char* argv[])
{
  if (argc >= 2)
  {
    if (!strcmp(argv[1], "install") && argc == 3)
    {
      std::string command;
      command = "git clone --quiet https://github.com/Triploit-org/";

      command = command + argv[2] + ".git";
      std::cout << ">> Downloading... " << std::endl;

      system(command.c_str());
      std::cout << ">> Finished!" << std::endl;

      std::cout << ">> Install..." << std::endl;
      install(argv[1]);
      std::cout << "Finished!" << std::endl;

      return 0;
    }
    else
    {
      std::cout << "Benutzung: " << std::endl;
      std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
    }
  }
  else
  {
    std::cout << "Benutzung: " << std::endl;
    std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
  }

  return 0;
}
