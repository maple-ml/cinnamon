#include <iostream>
#include <stdio.h>
#include <windows.h>

namespace cinnamon {
    namespace utilities {
        bool hasEnding(std::string const& fullString, std::string const& ending) {
            if (fullString.length() >= ending.length()) {
                return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
            }
            else {
                return false;
            }
        }

        std::string getGDPath() {
            char path_c[MAX_PATH + 1];
            GetModuleFileNameA(NULL, path_c, sizeof(path_c));
            size_t pos = std::string::npos;
            std::string path = std::string(path_c);
            while ((pos = path.find("GeometryDash.exe")) != std::string::npos)
            {
                path.erase(pos, std::string("GeometryDash.exe").length());
            }
            return path;
        }

        std::string getCinnamonPath() {
            std::string path = cinnamon::utilities::getGDPath();
            path.append("cinnamon\\");
            return path;
        }

        std::string getModsPath() {
            std::string path = cinnamon::utilities::getGDPath();
            path.append("cinnamon\\mods\\");
            return path;
        }
    }
}