//© Copyright 2016, Liam Rogers, All rights reserved.

/*
 * File description
 */

#pragma once
#include <sfapp/gui/ManagementUI.hpp>
#include <ctk/file.hpp>

namespace workflow { namespace gui {

	class ProjectManagementUI : public sfapp::gui::ManagementUI
	{
        friend class Main;

		public:

			ProjectManagementUI(string dir);
            
        protected:
            

            void Create();
            void Delete();

            void refreshInfo();



	};

}} // end of workflow::gui
