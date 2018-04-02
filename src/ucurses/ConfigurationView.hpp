#pragma once
/*
 * C++ std selection / Compiler flags / Optimization level
 * Dependancies
 */

#include <ucurses/ucurses.hpp>
#include <application/Project.hpp>

namespace Workflow {

    class ConfigurationView : public ucurses::State
    {
        public:

            ConfigurationView(Project* data);

        protected:

            // Workflow project data
            Project* project;

            // UCurses GUI setup
            void Initialize();

            ucurses::Menu* config_options;
            ucurses::Label* title; // Centered project title

            enum Selections { COMPILER_OPTIONS = 0, DEPENDANCIES, BUILD };

            void Escape(ucurses::Window* target);

    };

}
