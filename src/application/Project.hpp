#pragma once
#include <ctk/io/IO.hpp>
#include <bitset>
namespace Workflow {

    struct Version
    {
        short major;
        short minor;
        short revision;

		friend std::ostream& operator<<(std::ostream& stream, const Version& rhs);
    };

    class Project : public ctk::IO<Project>
    {
        public:

            std::string title;
            Version ver;
            std::vector<std::string> modules;
            std::vector<std::string> library_search_paths;
            std::vector<std::string> linker_files;
            //std::vector<std::string> flags;
            std::bitset<8> common_flags;
            char optimization_level;

            enum STD { _98, _0x, _11, _14, _17 };
            std::bitset<5> std;

            void Build();

            void write_form(std::ostream& stream) const;
            void read_form(std::istream& stream);

    };
}
