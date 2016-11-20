#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

void move(std::string from, std::string to);

int install(std::string path)
{
  chdir(path.c_str());
  std::ifstream infile = std::ifstream("pkgins.cfg");
  std::string line;

  if (!infile.is_open())
  {
    std::cout << path <<": error: Das Paket konnte nicht auf dem System installiert werden, da die Datei pkgins.cfg in dem Paket fehlt!" << std::endl;
    exit(0);
  }

  std::string ign1 = "pls mv fio ";
  std::string ign2 = " to dir ";

  std::string from = "";
  std::string to = "";

  std::string ign3 = "pls goto dir ";
  std::string ign4 = "say err ";

  while(getline(infile, line))
  {
     int i;
     if (line.substr(0, ign1.size()) == ign1)
      {
        line = line.substr(ign1.size(), line.size());

        for (i = 0; line[i] != ' '; i++)
        {
          from = from + line[i];
        }
        //std::cout << "FROM >> " << from << std::endl;
        line = line.substr(i, line.size());
      }

      if (line.substr(0, ign2.size()) == ign2)
      {
        line = line.substr(ign2.size(), line.size());

        for (i = 0; line[i] != ' ' && i < line.size(); i++)
        {
          to = to + line[i];
        }
        //std::cout << "TO >> " << to << std::endl;
      }

    if (line.substr(0, ign3.size()) == ign3)
    {
      chdir(line.substr(ign3.size(), line.size()).c_str());
    }

    if (line.substr(0, ign4.size()) == ign4)
    {
      std::cout << line.substr(ign4.size(), line.size()) << std::endl;
      return 0;
    }

    move(from, to);
  }

}

void move(std::string from, std::string to)
{
  std::string cmd = "mv "+from+" "+to;
  std::cout << ">> " << cmd << std::endl;
  system(cmd.c_str());
}
