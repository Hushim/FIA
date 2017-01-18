/*******************************************************************************
 * Name            : eraser
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for eraser class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/10/16
 * Original Author : Zhouman Wu
 ******************************************************************************/
#ifndef INCLUDE_ERASER_H_
#define INCLUDE_ERASER_H_
#define RADIUS 10.5;
#include "include/tools.h"
#include "include/pixel_buffer.h"
#include "include/color_data.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Eraser : public Tools{
    public:
        Eraser();
        virtual ~Eraser(void);
		// static Eraser * get_instance();
		// void calculate_color(                  
		// 		int mask_row,
		// 		int mask_col,
		// 		int coordinate_x,
		// 		int coordinate_y,
		// 		int pixel_coodinate_x,
		// 		int pixel_coodinate_y,
		// 		const ColorData color,
		// 		PixelBuffer **pixel_buffer_);

		void apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_);


    private:
		// Eraser();
		// static Eraser eraser_instance = NULL;
        float radius;
        void set_mask();
        void set_mask_size();

};
} // namespace image_tools;

#endif
