/*
 *
 *
 */

#pragma once
#include <ucurses/ucurses.hpp>
#include <application/Project.hpp>

namespace Workflow { 

	class StdConfiguration : public ucurses::State
	{
        public:

            StdConfiguration(Project* project);

		protected:

            void Initialize();
        
            ucurses::Label* header;
            ucurses::Menu* menu;            // C++ Standard: std=c++..
            
            Project* project;

    };

}
