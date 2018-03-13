/*
 * Calls wmake
 */

#include <ucurses/ucurses.hpp>

using namespace ucurses;

namespace workflow {

    class MainUI : public Interface
    {
        public:

            MainUI();

        protected:

            void Initialize();


            ScrollableMenu* dependancy_list;
            ScrollableMenu* module_list;

            
            Window* dependancy_view;
            Window* module_view;
            Window* class_view;

    };

}
