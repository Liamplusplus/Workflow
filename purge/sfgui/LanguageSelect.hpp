//© Copyright 2016, Liam Rogers, All rights reserved.

/*
 * File description
 */

#pragma once
#include <sfapp/gui/ManagementUI.hpp>
#include <sfapp/gui/UIWindow.hpp>
namespace workflow { namespace gui {

	class LanguageSelect : public sfapp::gui::ManagementUI
	{
        friend class Main;

		public:

			LanguageSelect();

        protected:


            
            void Create(); 
            void Delete(); 
            void refreshInfo();

	};

}} // end of workflow::gui
