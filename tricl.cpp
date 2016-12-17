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
  if (!strcmp(argv[1], "-v"))
  {
    std::cout << "Version: (0.)5.6a" << std::endl;
    exit(0);
  }

  if (argc == 2 || argc == 3)
  {
    if (!strcmp(argv[1], "install") && argc == 3)
    {
      system(std::string("rm -rf /usr/share/tricl/"+std::string(argv[2])).c_str());
      std::string command;
      ins = true;
      command = "git clone  https://github.com/"+m+"/";

      command = command + argv[2] + ".git " + " /usr/share/tricl/"+argv[2];
      std::cout << ">> Downloading... " << std::endl;

      system(command.c_str());
      std::cout << ">> Finished!" << std::endl;

      std::cout << ">> Install..." << std::endl;
      std::string path = "/usr/share/tricl/";
      path = path + std::string(argv[2]);

      install(path, ins);
      std::cout << ">> Finished!" << std::endl;

      return 0;
    }
    else if (!strcmp(argv[1], "remove") && argc == 3)
    {
      system(std::string("rm -rf /usr/share/tricl/"+std::string(argv[2])).c_str());

      std::string command;
      ins = false;
      command = "git clone --quiet https://github.com/"+m+"/";

      command = command + argv[2] + ".git " + " /usr/share/tricl/"+argv[2];
      std::cout << ">> Downloading... " << std::endl;

      system(command.c_str());
      std::cout << ">> Finished!" << std::endl;

      std::cout << ">> Removing..." << std::endl;

      std::string path = "";
      path = "/usr/share/tricl/";
      path = path + std::string(argv[2]);

      install(path, ins);
      std::cout << ">> Finished!" << std::endl;
    }
    else
    {
      std::cout << "[1] Benutzung: " << std::endl;
      std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
      std::cout << "  tricl remove <package>   = Ein Triploit Paket entfernen" << std::endl;

      std::cout << "  tricl -m <user> install <package>   = Ein Paket von einem anderen GitHub User installieren" << std::endl;
      std::cout << "  tricl -m <user> remove <package>   = Ein Paket von einem anderen GitHub User entfernen" << std::endl;
    }
  }
  else if (argc == 5)
  {
    if (!strcmp(argv[1], "-m"))
    {
       m = argv[2];

       // std::cout << argv[1] << std::endl;
       // std::cout << "m=" << m << std::endl;
       // std::cout << argv[3] << std::endl;
       // std::cout << argv[4] << std::endl;

      if (!strcmp(argv[3], "install"))
      {
        system(std::string("rm -rf /usr/share/tricl/"+std::string(argv[4])).c_str());
        std::string command;
        ins = true;
        command = "git clone --quiet https://github.com/"+m+"/";

        command = command + argv[4] + ".git " + " /usr/share/tricl/"+argv[4];
        std::cout << ">> Downloading... " << std::endl;

        system(command.c_str());
        std::cout << ">> Finished!" << std::endl;

        std::cout << ">> Install..." << std::endl;
        std::string path = "/usr/share/tricl/";
        path = path + std::string(argv[4]);

        install(path, ins);
        std::cout << ">> Finished!" << std::endl;

        return 0;
      }
      else if (!strcmp(argv[3], "remove"))
      {
        system(std::string("rm -rf /usr/share/tricl/"+std::string(argv[4])).c_str());
        std::string command;
        ins = false;
        command = "git clone --quiet https://github.com/"+m+"/";

        command = command + argv[4] + ".git " + " /usr/share/tricl/"+argv[4];
        std::cout << ">> Downloading... " << std::endl;

        system(command.c_str());
        std::cout << ">> Finished!" << std::endl;

        std::cout << ">> Removing..." << std::endl;
        std::string path = "/usr/share/tricl/";
        path = path + std::string(argv[4]);

        install(path, ins);
        std::cout << ">> Finished!" << std::endl;
      }
      else
      {
        std::cout << "[2] Benutzung: " << std::endl;
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
    std::cout << "[3] Benutzung: " << std::endl;
    std::cout << "  tricl install <package>   = Ein Triploit Paket installieren" << std::endl;
    std::cout << "  tricl remove <package>   = Ein Triploit Paket entfernen" << std::endl;

    std::cout << "  tricl -m <user> install <package>   = Ein Paket von einem anderen GitHub User installieren" << std::endl;
    std::cout << "  tricl -m <user> remove <package>   = Ein Paket von einem anderen GitHub User entfernen" << std::endl;
  }

  return 0;
}
