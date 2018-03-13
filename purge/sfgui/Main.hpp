//© Copyright 2016, Liam Rogers, All rights reserved.

/*
 * File description
 */

#pragma once
#include <sfapp/gui/UIWindow.hpp>


namespace workflow { namespace gui {

	class Main : public sfapp::gui::UIWindow
	{
		public:

			Main();

        protected:

            void Home();
            void Search(string selection);
            void Project(string project);



	};

}} // end of workflow::gui
