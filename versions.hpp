#pragma once

#include <iostream>
#include <dpp/fmt/format.h>

/**
 * @brief Sir Obsidian's new namespace! :O 
 * 
*/
namespace OB {

    class Version
    {
        private:
        int v1, v2, v3;
        std::string subv = "";
        std::string commit;
        std::string versionname;
        public:
        /**
         * @brief Setting version for class. 
         * @param x Set x.0.0
         * @param y Set 0.y.0
         * @param z Set 0.0.z
         * @param sub Set 0.0.0subv
        */
        void setVersion(int x, int y, int z, std::string sub) {
            Version::v1 = x;
            Version::v2 = y;
            Version::v3 = z;
            Version::subv = sub;
        }
        /**
         * @brief Setting Github Commit.
         * @param commit Commit to set.
        */
        void setCommit(std::string commit) {
            Version::commit = commit;
        }
        /**
         * @brief Setting version for class. 
         * @param name Version name.
        */
        void setName(std::string name) {
            Version::versionname = name;
        }
        /**
         * @brief Generate text from Version. 
         * 
        */
        std::string getText() {
            std::string x = fmt::format("Version: `{}.{}.{}{} - {}`\nCommit: `{}`\n", Version::v1, Version::v2, Version::v3, Version::subv, Version::versionname, Version::commit);

            return x;
        }
    };

    Version getV () {
        Version v;
        v.setVersion(1, 0, 1, "e");
        v.setName("The /info Update.");
        v.setCommit("b3f88e7"); // This is updated AFTER pushed into Github.

        return v;
    }

}