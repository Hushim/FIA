/*******************************************************************************
 * Name            : filter_quantize.cc
 * Project         : Flashphoto
 * Module          : Filter
 * Description     : Implementation of FilterQuantize class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/filter_quantize.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterQuantize::FilterQuantize(void) {}
FilterQuantize::FilterQuantize(float quant) {
  set_quantize(quant);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void FilterQuantize::set_quantize(float quant) {
  quantize_ = quant;
  return;
}

float FilterQuantize::get_quantize(void) {
  return quantize_;
}

void FilterQuantize::set_color_data(ColorData * pixel) {
  float unit_bin = 1.0 / (quantize_ - 1);
  int shift_r = pixel->red() / unit_bin;
  int shift_rv = (pixel->red() - (shift_r * unit_bin)) / unit_bin;
  if (shift_rv == 0) {
    pixel->red(shift_r * unit_bin);
  } else {
    pixel->red((shift_r+1) * unit_bin);
  }
  int shift_g = pixel->green() / unit_bin;
  int shift_gv = (pixel->green() - (shift_g * unit_bin)) / unit_bin;
  if (shift_gv == 0) {
    pixel->green(shift_g * unit_bin);
  } else {
    pixel->green((shift_g+1) * unit_bin);
  }

  int shift_b = pixel->blue() / unit_bin;
  int shift_bv = (pixel->blue() - (shift_b * unit_bin)) / unit_bin;
  if (shift_bv == 0) {
    pixel->blue(shift_b * unit_bin);
  } else {
    pixel->blue((shift_b+1) * unit_bin);
  }

  return;
}
}  /* namespace image_tools */
