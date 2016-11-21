#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <random>
#include <fstream>
#include "installer.cpp"

std::string m = "Triploit-org";

int main(int argc, char* argv[])
{
  bool ins = false;
  if (argc == 2)
  {
    if (!strcmp(argv[1], "install") && argc == 3)
    {
      std::string command;
      ins = true;
      command = "git clone --quiet https://github.com/"+m+"/";

      command = command + argv[2] + ".git";
      std::cout << ">> Downloading... " << std::endl;

      system(command.c_str());
      std::cout << ">> Finished!" << std::endl;

      std::cout << ">> Install..." << std::endl;
      install(argv[2], ins);
      std::cout << ">> Finished!" << std::endl;

      return 0;
    }
    else if (!strcmp(argv[1], "remove") && argc == 3)
    {
      std::string command;
      ins = false;
      command = "git clone --quiet https://github.com/"+m+"/";

      command = command + argv[2] + ".git";
      std::cout << ">> Downloading... " << std::endl;

      system(command.c_str());
      std::cout << ">> Finished!" << std::endl;

      std::cout << ">> Removing..." << std::endl;
      install(argv[2], ins);
      std::cout << ">> Finished!" << std::endl;
    }
    else
    {
      std::cout << "Benutzung: " << std::endl;
      std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
      std::cout << "  tricl remove <package>   = Ein Triploit Paket entfernen" << std::endl;

      std::cout << "  tricl -m <user> install <package>   = Ein Paket von einem anderen GitHub User installieren" << std::endl;
      std::cout << "  tricl -m <user> remove <package>   = Ein Paket von einem anderen GitHub User entfernen" << std::endl;
    }
  }
  else if (argc == 4)
  {
    if (argv[1] == "-m")
    {
       m = argv[2];
      
      if (!strcmp(argv[2], "install") && argc == 3)
      {
        std::string command;
        ins = true;
        command = "git clone --quiet https://github.com/"+m+"/";

        command = command + argv[3] + ".git";
        std::cout << ">> Downloading... " << std::endl;

        system(command.c_str());
        std::cout << ">> Finished!" << std::endl;

        std::cout << ">> Install..." << std::endl;
        install(argv[3], ins);
        std::cout << ">> Finished!" << std::endl;

        return 0;
      }
      else if (!strcmp(argv[2], "remove") && argc == 3)
      {
        std::string command;
        ins = false;
        command = "git clone --quiet https://github.com/"+m+"/";

        command = command + argv[3] + ".git";
        std::cout << ">> Downloading... " << std::endl;

        system(command.c_str());
        std::cout << ">> Finished!" << std::endl;

        std::cout << ">> Removing..." << std::endl;
        install(argv[3], ins);
        std::cout << ">> Finished!" << std::endl;
      }
      else
      {
        std::cout << "Benutzung: " << std::endl;
        std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
        std::cout << "  tricl remove <package>   = Ein Triploit Paket entfernen" << std::endl;

        std::cout << "  tricl -m <user> install <package>   = Ein Paket von einem anderen GitHub User installieren" << std::endl;
        std::cout << "  tricl -m <user> remove <package>   = Ein Paket von einem anderen GitHub User entfernen" << std::endl;
      }
    }
    return 0;
    }
  else
  {
    std::cout << "Benutzung: " << std::endl;
    std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
    std::cout << "  tricl remove <package>   = Ein Triploit Paket entfernen" << std::endl;
    
    std::cout << "  tricl -m <user> install <package>   = Ein Paket von einem anderen GitHub User installieren" << std::endl;
    std::cout << "  tricl -m <user> remove <package>   = Ein Paket von einem anderen GitHub User entfernen" << std::endl;
  }

  return 0;
}
