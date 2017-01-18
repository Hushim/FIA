/*******************************************************************************
 * Name            : highter.cc
 * Project         : BrushWork
 * Module          : App
 * Description     : Implementation of Highlighter
 * Copyright       : 2016 CSCI3081W Group C04. All rights reserved.
 * Creation Date   : 10/11/2016
 * Original Author : Zhouman Wu
 *
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
  #include "include/highlighter.h"
  #include <iostream>

/*******************************************************************************
   * Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/
	Highlighter :: Highlighter() {
		height = HEIGHT;
		width = WIDTH;
    set_mask();
	}

	Highlighter :: ~Highlighter(void) {
	}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 	void Highlighter::set_mask() {
 		Tools :: set_mask();
    printf("This is highlighter\n");
 		for (int row = 0; row < mask_size; row++) {
      for (int col = 0; col < mask_size; col++) {
        if (
          abs(col - mask_center) <= height/2
          && abs(row - mask_center) <= width/2) {
          mask[row][col] = 0.4;
        } else {
          mask[row][col] = 0;
        }         
      }
    }
 	}

  void Highlighter::set_mask_size() {}
  void Highlighter::calculate_color(
                    int mask_row,
                    int mask_col,
                    int coordinate_x,
                    int coordinate_y,
                    int pixel_coodinate_x,
                    int pixel_coodinate_y,
                    const ColorData color,
                    PixelBuffer **pixel_buffer_) {
    // get backgorund color and adapt it accoding to principles of differnet tools
    ColorData previous_pixel = (**pixel_buffer_).get_pixel(pixel_coodinate_x, pixel_coodinate_y);
    float intensity = get_mask_data(mask_row, mask_col) * previous_pixel.luminance();
    ColorData adapted_backgroud_color = previous_pixel * (1.0 - intensity);



    // set new color on canvas while applying tools on it
    (**pixel_buffer_).set_pixel(
                        pixel_coodinate_x,
                        pixel_coodinate_y,
                        adapted_backgroud_color + color * intensity);
  }
}  // namespace image_tools
