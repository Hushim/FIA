/*******************************************************************************
 * Name            : spray can
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for tools class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/13/16
 * Original Author : Zixiang Ma
 ******************************************************************************/
#ifndef INCLUDE_SPRAY_CAN_H_
#define INCLUDE_SPRAY_CAN_H_
#include "tools.h"
#define EFFECTIVE_RADIUS 20.5

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class SprayCan : public Tools{
    public:
        SprayCan();
        virtual ~SprayCan(void);
        // static SprayCan * get_instance();

    private:
        // static SprayCan spraycan_instance = NULL;
        // SprayCan();
        float radius;
        float effective_radius;
        void set_mask();
        void set_mask_size();
        // void set_radius();
};
} // namespace image_tools;

#endif
