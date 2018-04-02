/*
 *
 *
 */

#pragma once
#include <ucurses/ucurses.hpp>

namespace Workflow { 

    class Project;

	class FlagConfiguration : public ucurses::State
	{
        public:

            FlagConfiguration(Project* data);

		protected:
            
            // Workflow project data
            Project* project;

            // UCurses GUI setup
            void Initialize();

            ucurses::Label* header;
            ucurses::Checklist* checklist;   // Debug, warnings etc.
            ucurses::TextEntry* explicit_entry;
            ucurses::Menu* explicit_menu;

    };

}
