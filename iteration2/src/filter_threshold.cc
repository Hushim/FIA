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
#include "include/filter_threshold.h"
#include <stdio.h>
#include <iostream>
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
FilterThreshold::FilterThreshold(void) {}
FilterThreshold::FilterThreshold(float threshold) {
  set_threshold(threshold);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void FilterThreshold::set_threshold(float threshold) {
  threshold_ = threshold;
  return;
}

float FilterThreshold::get_threshold(void) {
  return threshold_;
}

void FilterThreshold::set_color_data(ColorData * pixel) {
  if (pixel->red() >= threshold_) {
    pixel->red(1.0);
  } else {
    pixel->red(0.0);
  }
  if (pixel->green() >= threshold_) {
    pixel->green(1.0);
  } else {
    pixel->green(0.0);
  }
  if (pixel->blue() >= threshold_) {
    pixel->blue(1.0);
  } else {
    pixel->blue(0.0);
  }
  return;
}

}  /* namespace image_tools */
