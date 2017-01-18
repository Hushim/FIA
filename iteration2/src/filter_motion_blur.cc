/*******************************************************************************
 * Name            : filter_rbg.cc
 * Project         : FlashPhoto
 * Module          : Filter
 * Description     : Implementation of FilterBlur class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/filter_motion_blur.h"
#include <stdio.h>
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterMotionBlur::FilterMotionBlur(void) {}
FilterMotionBlur::FilterMotionBlur(float amount, int direct) {
    kernel_init(amount, direct);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void FilterMotionBlur::kernel_init(float amount, int direct) {
    matrix = new MotionBlurKernel(amount, direct);
    return;
}

void FilterMotionBlur::set_color_data(int row, int col,
  PixelBuffer * display_buffer, PixelBuffer * canvas_copy) {
  float red_sum = 0.0;
  float green_sum = 0.0;
  float blue_sum = 0.0;
  float fac = matrix->get_factor();
  for (int x_inner = 0; x_inner < matrix->get_size(); x_inner++) {
      for (int y_inner = 0; y_inner < matrix->get_size(); y_inner++) {
          ColorData cur = canvas_copy->get_pixel(row+x_inner, col+y_inner);

          red_sum += cur.red() * matrix->get_array(x_inner, y_inner) * fac;
          green_sum += cur.green() * matrix->get_array(x_inner, y_inner) * fac;
          blue_sum += cur.blue() * matrix->get_array(x_inner, y_inner) * fac;
      }
  }

  // calculate new color data at center of the kernal matrix
  ColorData * filtered_color = new ColorData(red_sum, green_sum, blue_sum);
  display_buffer->set_pixel(row + matrix->get_size()/2,
                            col + matrix->get_size()/2,
                            *filtered_color);
}
}  /* namespace image_tools */
