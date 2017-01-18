/*******************************************************************************
 * Name            : filter_threshold.cc
 * Project         : Flashphoto
 * Module          : Filter
 * Description     : Implementation of FilterThreshold class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/filter_special.h"
#include <stdio.h>
#include <iostream>
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterSpecial::FilterSpecial(void) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/


void FilterSpecial::set_color_data(ColorData * pixel) {
  pixel->red(1 - pixel->red());
  pixel->blue(1 - pixel->blue());
  pixel->green(1 - pixel->green());
  return;
}

void FilterSpecial::apply_filter_to_photo(PixelBuffer * display_buffer) {
  for (int row = 0; row < display_buffer->width(); row++) {
    for (int col = 0; col < display_buffer->height(); col++) {
      ColorData current_color = display_buffer->get_pixel(row, col);
      set_color_data(&current_color);
      display_buffer->set_pixel(row, col, current_color);
    }
  }
  return;
}

}  /* namespace image_tools */
