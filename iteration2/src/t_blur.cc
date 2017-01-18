/*******************************************************************************
 * Name            : t_spray_can.cc
 * Project         : BrushWok
 * Module          : Tool
 * Description     : Implementation of SprayCan tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>
#include "include/m_linear.h"
#include "include/t_blur.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
TBlur::TBlur(void) {
  blur_filter = new FilterBlur(3);
}

void TBlur::ApplyToBuffer(int tool_x,
                         int tool_y,
                         ColorData tool_color,
                         PixelBuffer* buffer) {
  int upper, lower, left, right;
  int size = 41;

  if (tool_x + size/2 < buffer->width()) {
    left = tool_x + size/2;
  } else {
    left = buffer->width() - 1;
  }

  if (tool_y + size/2 < buffer->height()) {
    lower = tool_y + size/2;
  } else {
    lower = buffer->height() - 1;
  }

  if (tool_x - size/2 >= 0) {
    right = tool_x - size/2;
  } else {
    right = 0;
  }

  if (tool_y - size/2 >= 0) {
    upper = tool_y - size/2;
  } else {
    upper = 0;
  }
  // std::cout << "these are left,right, upper, lower:\n";
  // std::cout << tool_x << std::endl;
  // std::cout << tool_y << std::endl;
  // std::cout << left << std::endl;
  // std::cout << right << std::endl;
  // std::cout << upper<< std::endl;
  // std::cout << lower<< std::endl;
  while (left - right > 3 && lower - upper > 3) {
    // std::cout << "left right uppper lower\n";
    // std::cout << left-right << std::endl;
    // std::cout << lower-upper << std::endl;
    // PixelBuffer * canvas_copy = new PixelBuffer(*buffer);
    blur_filter->apply_conv_filter_to_photo(buffer,
                                            buffer,
                                            right,
                                            left,
                                            upper,
                                            lower);
    // delete canvas_copy;
    left -= 1;
    right += 1;
    lower -= 1;
    upper += 1;
  }
  return;
}

}  // namespace image_tools
