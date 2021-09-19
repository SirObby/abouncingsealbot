#include "versions.hpp"

namespace OB {

        void Version::setVersion(int x, int y, int z, std::string sub) {
            Version::v1 = x;
            Version::v2 = y;
            Version::v3 = z;
            Version::subv = sub;
        }
        /**
         * @brief Setting Github Commit.
         * @param commit Commit to set.
        */
        void Version::setCommit(std::string commit) {
            Version::commit = commit;
        }
        /**
         * @brief Setting version for class. 
         * @param name Version name.
        */
        void Version::setName(std::string name) {
            Version::versionname = name;
        }
        /**
         * @brief Generate text from Version. 
         * 
        */
        std::string Version::getText() {
            std::string x = fmt::format("Version: `{}.{}.{}{} - {}`\nCommit: `{}`\n", Version::v1, Version::v2, Version::v3, Version::subv, Version::versionname, Version::commit);

            return x;
        }

    OB::Version getV () {
        OB::Version v;
        v.setVersion(1, 0, 2, "a");
        v.setName("The Major Update");
        v.setCommit("Unknown"); // This is updated AFTER pushed into Github.

        return v;
    }

}