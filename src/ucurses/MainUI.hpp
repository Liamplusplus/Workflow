/*
 * Calls wmake
 */

#include <ucurses/ucurses.hpp>
#include "ProjectView.hpp"
#include "BuildView.hpp"

using namespace ucurses;

namespace Workflow {

    class MainUI : public Interface
    {
        protected:

            // UCurses GUI setup
            void Initialize();

            void RefreshClassList();
            void RefreshDependancyList();

            Checklist* dependancy_list;
            Checklist* module_list;
            Checklist* class_list;
            TextEntry* dependancy_entry;
            Menu* entry_list;
            
            Window* dependancy_view;
            Window* module_view;
            Window* class_view;

            Label* terminal_output;

            void setupDependancyView();
            void setupModuleView();
            void setupClassView();
            void setupTerminalOutput();

            ProjectView project_view;
            BuildView build_view;

    };

}
