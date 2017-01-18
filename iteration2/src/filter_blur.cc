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
#include "include/filter_blur.h"
#include <stdio.h>
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterBlur::FilterBlur(void) {}
FilterBlur::FilterBlur(float amount) {
    kernel_init(amount);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/


void FilterBlur::kernel_init(float amount) {
    matrix = new BlurKernel(amount);
    return;
}


void FilterBlur::set_color_data(int row, int col,
  PixelBuffer * display_buffer, PixelBuffer * canvas_copy) {
  float red_sum = 0.f;
  float green_sum = 0.f;
  float blue_sum = 0.f;
  float fac = matrix->get_factor();
  for (int x_inner = 0; x_inner < matrix->get_size(); x_inner++) {
      for (int y_inner = 0; y_inner < matrix->get_size(); y_inner++) {
        ColorData cur = canvas_copy->get_pixel(row + x_inner, col + y_inner);
        red_sum += cur.red() * fac;
        green_sum += cur.green() * fac;
        blue_sum += cur.blue() * fac;
      }
  }
  ColorData * filtered_color = new ColorData(red_sum, green_sum, blue_sum);
  display_buffer->set_pixel(row + matrix->get_size()/2,
                            col + matrix->get_size()/2,
                            *filtered_color);
  return;
}


void FilterBlur::apply_conv_filter_to_photo(PixelBuffer * display_buffer,
                                            PixelBuffer * canvas_copy,
                                            int left,
                                            int right,
                                            int upper,
                                            int lower) {
  // std::cout << "left - right\n";
  // std::cout << left << std::endl;
  // std::cout << right << std::endl;
  // std::cout << "upper - lower\n";
  // std::cout << upper << std::endl;
  // std::cout << lower << std::endl;
  for (int row = left; row < right - matrix->get_size(); row ++) {
    for (int col = upper; col < lower - matrix->get_size(); col++) {
      set_color_data(row, col, display_buffer, canvas_copy);
    }
  }
}






}  /* namespace image_tools */
