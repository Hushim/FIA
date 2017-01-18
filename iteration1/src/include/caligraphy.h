/*******************************************************************************
 * Name            : caligraphy.h
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for caligraphy application.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/12/16
 * Original Author : Zhouman Wu
 ******************************************************************************/
#ifndef INCLUDE_CALIGRAPHY_H_
#define INCLUDE_CALIGRAPHY_H_
#define HEIGHT 15.0;
#define WIDTH 5.0;
#include "tools.h"
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class CaligraphyPen : public Tools{
    public:
        CaligraphyPen();
        virtual ~CaligraphyPen(void);
        // static CaligraphyPen * get_instance();

    private:
        // CaligraphyPen();
        // static CaligraphyPen caligraphypen_instance = NULL;
        float height;
        float width;
        void set_mask();
        void set_mask_size();
};
} // namespace image_tools;

#endif 