#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <pwd.h>

void move(std::string from, std::string to, bool ins);

const char *getUserName()
{
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return "";
}

int install(std::string path, bool ins)
{
  std::string user;
  char* u = getUserName();
  user = u;

  if (user != "root")
  {
    std::cout << "Warnung: Programm muss als Root ausgefuehrt werden!" << std::endl;
    //exit(0);
  }

  chdir(std::string(path + "/").c_str());
  std::ifstream infile = std::ifstream(std::string(path + "/"+"pkgins.cfg"));
  std::string line;

  if (!infile.is_open())
  {
    std::cout << std::string(path + "/"+"pkgins.cfg") <<": error: Das Paket konnte nicht auf dem System installiert werden, da die Datei pkgins.cfg in dem Paket fehlt!" << std::endl;
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
     //std::cout << "LINE >> " << line << std::endl;

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

    move(from, to, ins);

    line = "";
    from = "";
    to = "";
  }

  //std::string cmd;
  chdir("..");

  std::cout << "REMOVE PATH: " << path << std::endl;
  remove(path.c_str());
}

void move(std::string from, std::string to, bool ins)
{
  if (ins == false)
  {
    std::string cmd = "rm -rf "+to;
    std::cout << ">> \"" << cmd << "\"" << std::endl;

    if (cmd != "rm -rf /bin/" && cmd != "rm -rf /bin" && cmd != "rm -rf /usr/bin" && cmd != "rm -rf /usr/bin/" && cmd != "rm -rf /usr" && cmd != "rm -rf /usr/")
    {
      system(cmd.c_str());
    }
    else
    {
      std::cout << "Error: Defektes/Fehlerhaftes Paket! Der Bin-Ordner darf nicht gelöscht werden!" << std::endl;
    }
  }
  else
  {
    std::string cmd = "mv "+from+" "+to;
    std::cout << ">> " << cmd << std::endl;
    system(cmd.c_str());
    system(std::string("chmod +x "+to).c_str());
  }
}

void rm(std::string to)
{
  std::string cmd = "rm "+to;
  system(cmd.c_str());
}
