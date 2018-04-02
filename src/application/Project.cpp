#include "Project.hpp"
#include <sstream>

namespace Workflow {

	std::ostream& operator<<(std::ostream& stream, const Version& rhs)
    {
        std::stringstream result;
        result << rhs.major << "." << rhs.minor << "." << rhs.revision;
        stream << result.str();
    
    }

    void Project::write_form(std::ostream& stream) const
    {
        stream << "<Name> " << title;
        stream << "\n<Version> " << ver;
    }
            
    void read_form(std::istream& stream)
    {
    
    }

}
