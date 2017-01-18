/*******************************************************************************
<<<<<<< HEAD
 * Name            : color_data.cc
 * Project         : BrushWork
 * Module          : image_tools
 * Description     : Implementation of ColorData class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************
 * Name            : filter.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for Filter base class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Zixiang Ma
 *
 *****************************************************************************/

 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include <cmath>
#include <algorithm>
#include "include/filter.h"
#include "include/tool.h"
#include "include/color_data.h"
#include "include/mask.h"
#include "include/pixel_buffer.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
Filter::Filter(void) {}
Filter::~Filter(void) {}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void Filter::set_color_data(ColorData * pixel) {}
void Filter::set_color_data(int row, int col,
  PixelBuffer * display_buffer, PixelBuffer * canvas_copy) {}
void Filter::apply_filter_to_photo(PixelBuffer * display_buffer) {
  for (int row = 0; row < display_buffer->width(); row++) {
    for (int col = 0; col < display_buffer->height(); col++) {
      ColorData current_color = display_buffer->get_pixel(row, col);
      set_color_data(&current_color);
      display_buffer->set_pixel(row, col, current_color);
    }
  }
}


void Filter::apply_conv_filter_to_photo(PixelBuffer * display_buffer,
                                        PixelBuffer * canvas_copy,
                                        int left,
                                        int right,
                                        int upper,
                                        int lower) {}

void Filter::apply_conv_filter_to_photo(PixelBuffer * display_buffer) {
  int wid = display_buffer->width();
  int high = display_buffer->height();

  PixelBuffer canvas_copy(*display_buffer);
  // traverse photo

  float fac = matrix->get_factor();
  for (int row = 0; row < wid - matrix->get_size(); row++) {
      for (int col = 0; col < high - matrix->get_size(); col++) {
          set_color_data(row, col, display_buffer, &canvas_copy);
      }
  }
  return;
}


}  /* namespace image_tools */
