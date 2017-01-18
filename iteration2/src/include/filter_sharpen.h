/*******************************************************************************
 * Name            : filter_blur.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterBlur class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_FILTER_SHARPEN_H_
#define ITERATION2_SRC_INCLUDE_FILTER_SHARPEN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/color_data.h"
#include "include/pixel_buffer.h"
#include "include/filter.h"
#include "include/sharpen_kernel.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief.
 */
class FilterSharpen : public Filter{
 public:
  FilterSharpen(void);
  explicit FilterSharpen(float amount);
  void kernel_init(float amount);
  void set_color_data(int row, int col,
                     PixelBuffer * display_buffer,
                     PixelBuffer * canvas_copy);
};

}  /* namespace image_tools */
#endif  //  ITERATION2_SRC_INCLUDE_FILTER_SHARPEN_H_
