/*******************************************************************************
 * Name            : highlighter.h
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for highlighter application.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/12/16
 * Original Author : Zhouman Wu
 ******************************************************************************/
#ifndef INCLUDE_HIGHLIGHTER_H_
#define INCLUDE_HIGHLIGHTER_H_
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
class Highlighter : public Tools{
    public:
        Highlighter();
        virtual ~Highlighter(void);
        // static Highlighter * get_instance();
         void calculate_color(                  
                    int mask_row,
                    int mask_col,
                    int coordinate_x,
                    int coordinate_y,
                    int pixel_coodinate_x,
                    int pixel_coodinate_y,
                    const ColorData color,
                    PixelBuffer **pixel_buffer_);

    private:
        // static Highlighter highlighter_instance = NULL;
        // Highlighter();
        float height;
        float width;
        void set_mask();
        void set_mask_size();
       
};
} // namespace image_tools;

#endif 