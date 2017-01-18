/*******************************************************************************
 * Name            : eraser.cc
 * Project         : eraser class
 * Module          : App
 * Description     : Header file for eraser application.
 * Copyright       : 2016 CSCI3081W Group C04. All rights reserved.
 * Creation Date   : 10/11/2016
 * Original Author : Zhouman Wu
 *
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
  #include "include/eraser.h"
  #include "include/pixel_buffer.h"
  #include "include/color_data.h"
  #include "include/tools.h"
  #include <iostream>

/*******************************************************************************
   * Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/
	Eraser::Eraser() {
    radius = RADIUS;
    set_mask();
	}

	Eraser::~Eraser(void) {
	}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
  void Eraser::set_mask_size() {}
  void Eraser::set_mask() {
 		Tools :: set_mask();
 		for (int row = 0; row < mask_size; row++) {
 			for (int col = 0; col < mask_size; col++) { 
 				if (calculate_distance_from_mask_center(row, col, mask_center) <= radius) {
 					mask[row][col] = 1.0;
 				} else {
 					mask[row][col] = 0.0;
 				}
 			}
 		}
 	}

void Eraser::apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_) {
  int set_pixel_coodinate_x;
  int set_pixel_coodinate_y;

  int width = (**pixel_buffer_).width();
  int height = (**pixel_buffer_).height();

  for (int row = 0; row < mask_size; row++) {
    for (int col = 0; col < mask_size; col++) {
      set_pixel_coodinate_x = coordinate_x - mask_size/2 + row;
      set_pixel_coodinate_y = coordinate_y - mask_size/2 + col;

      if (
        set_pixel_coodinate_x < 0 
        || set_pixel_coodinate_y < 0
        || set_pixel_coodinate_x > width
        || set_pixel_coodinate_y > height) {
        printf("set pixel coordinate x and y are out of range\n");
      } else {
        calculate_color(
                    row,
                    col,
                    coordinate_x,
                    coordinate_y,
                    set_pixel_coodinate_x,
                    height - (set_pixel_coodinate_y + 1),
                    (**pixel_buffer_).background, pixel_buffer_);
      }
    }
  }
}

}  // namespace image_tools
