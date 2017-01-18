/*******************************************************************************
 * Name            : filter_saturation.cc
 * Project         : Flashphoto
 * Module          : Filter
 * Description     : Implementation of FilterSaturation class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/filter_saturation.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterSaturation::FilterSaturation(void) {}
FilterSaturation::FilterSaturation(float saturation) {
  set_saturation(saturation);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void FilterSaturation::set_saturation(float saturation) {
  saturation_ = saturation;
  return;
}

float FilterSaturation::get_saturation(void) {
  return saturation_;
}

void FilterSaturation::set_color_data(ColorData * pixel) {
  float lumin = pixel->luminance();
  float diff_red = pixel->red() - lumin;
  float diff_green = pixel->green() - lumin;
  float diff_blue = pixel->blue() - lumin;
  pixel->red(lumin + diff_red*saturation_);
  pixel->blue(lumin + diff_blue*saturation_);
  pixel->green(lumin + diff_green*saturation_);
  return;
}
}  /* namespace image_tools */
