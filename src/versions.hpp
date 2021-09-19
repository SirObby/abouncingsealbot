#pragma once
#if !defined(VERSIONS_HPP)
#define VERSIONS_HPP

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
        void setVersion(int x, int y, int z, std::string sub);
        /**
         * @brief Setting Github Commit.
         * @param commit Commit to set.
        */
        void setCommit(std::string commit);
        /**
         * @brief Setting version for class. 
         * @param name Version name.
        */
        void setName(std::string name);
        /**
         * @brief Generate text from Version. 
         * 
        */
        std::string getText();
    };

    Version getV ();

}



#endif // MACRO
