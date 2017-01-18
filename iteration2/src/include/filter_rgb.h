/*******************************************************************************
 * Name            : filter_rgb.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterRGB class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_FILTER_RGB_H_
#define ITERATION2_SRC_INCLUDE_FILTER_RGB_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/color_data.h"
#include "include/pixel_buffer.h"
#include "include/filter.h"
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
class FilterRBG : public Filter {
 public:
  FilterRBG(void);
  FilterRBG(float red_factor, float green_factor, float blue_factor);
  void set_factors(float red_factor, float green_factor, float blue_factor);
  void set_color_data(ColorData * pixel);

 protected:
     float red_factor_;
     float blue_factor_;
     float green_factor_;
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_FILTER_RGB_H_
