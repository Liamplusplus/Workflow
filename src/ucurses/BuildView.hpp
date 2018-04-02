#pragma once

#include <ucurses/ucurses.hpp>

namespace Workflow {

    class Project;

    class BuildView : public ucurses::State
    {
        public:

            BuildView(Project* data);

        protected:

            // Workflow project data
            Project* project;

            // UCurses GUI setup
            void Initialize();

            ucurses::Label* output;
            ucurses::Menu* target_list;

            // Uses default target name if empty
            ucurses::TextEntry* target_entry;

    };

}
