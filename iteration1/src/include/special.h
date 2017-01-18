/*******************************************************************************
 * Name            : special tools
 * Project         : brushwork
 * Module          : utils
 * Description     : Header file for tools class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/10/18
 * Original Author : Zixiang Ma
 ******************************************************************************/

#ifndef INCLUDE_SPECIAL_H_
#define INCLUDE_SPECIAL_H_
#define RADIUS 20;
#include "include/tools.h"
#include "include/pixel_buffer.h"
#include "include/color_data.h"

namespace image_tools{
	class Special : public Tools{
	public:
		Special(void);
		~Special();
		float radius;
		void apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_);
	private:
        void set_mask();
        void set_mask_size();
	};

}// namespace image_tools;


#endif