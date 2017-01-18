/*******************************************************************************
 * Name            : tools
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for tools class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/10/16
 * Original Author : Zixiang Ma
 ******************************************************************************/
#ifndef INCLUDE_PEN_H_
#define INCLUDE_PEN_H_
#define RADIUS 1.5;
#include "tools.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Pen : public Tools{
     // static Pen pen_instance = new Pen();
    public:
       Pen();
        virtual ~Pen(void);
        // static Pen * get_instance();
        

    private:
        // Pen();
        // static int init = 0;
        // static Pen * pen_instance;;
        
        float radius;
        void set_mask();
        void set_mask_size();

};
} // namespace image_tools;

#endif
