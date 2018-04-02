/*
 *
 */

#pragma once
#include <ucurses/ucurses.hpp>

namespace Workflow { 

    class Project;
	class OptimizationMenu : public ucurses::State
	{
        public:

            OptimizationMenu(Project* data);

		protected:

            // UCurses GUI setup
            void Initialize();

            ucurses::Label* header;
            ucurses::Menu* menu;  // Optimization level selection

            Project* project;
	};

}
