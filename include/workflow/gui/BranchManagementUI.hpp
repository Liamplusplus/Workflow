//© Copyright 2016, Liam Rogers, All rights reserved.

/*
 * Interface for managing branches for a project 
 * Functionality for deleting and viewing contents included.
 *
 * Note that project directory should be passed into the constructor
 * so the class is not tied to this programs application.
 */

#pragma once
#include <ctk/file/Directory.hpp>
#include <ctk/project/CppProject.hpp>
#include <sfapp/gui/ManagementUI.hpp>

#include "../application/Application.hpp"

using namespace boost::filesystem;
using namespace ctk::project;

namespace workflow { namespace gui {

	class BranchManagementUI : public sfapp::gui::ManagementUI
	{
        friend class Main;

		public:

			BranchManagementUI(string inProjectDir);

        protected:
            
            void Delete();
            void Create();

            void refreshInfo();

            sfg::ToggleButton::Ptr isClass;
            sfg::Button::Ptr createClass;
            sfg::Entry::Ptr className;

            void addClass();

            string projectDir;
            /*
             * Project directory must be kept seperate from
             * refresh as ctk::project::CppProject takes in project path 
             * in construction
             */
            

	};

}} // end of workflow::gui
