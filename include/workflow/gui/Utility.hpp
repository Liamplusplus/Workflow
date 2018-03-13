//© Copyright 2016, Liam Rogers, All rights reserved.

/*
 * File description
 */

#pragma once
#include <sfapp/gui/UIComponent.hpp>
#include <ctk/file.hpp>

using namespace sfapp::gui;
namespace workflow { namespace gui {

	class Utility : public UIComponent
	{
		public:

			Utility();
			~Utility();


        protected:

            sfg::Box::Ptr buttons;
            sfg::Box::Ptr entries;

            sfg::Button::Ptr stash;
            sfg::Entry::Ptr stashname;

            sfg::Button::Ptr fetch;
            sfg::Entry::Ptr fetchname;

            sfg::Button::Ptr main;

            sfg::Button::Ptr copy;

            string projectDir;
	};

}} // end of workflow::gui
