/*******************************************************************************
 * Name            : filter_rbg.cc
 * Project         : FlashPhoto
 * Module          : Filter
 * Description     : Implementation of FilterRBG class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/filter_rgb.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

FilterRBG::FilterRBG(void) {}
FilterRBG::FilterRBG(float red_factor, float green_factor, float blue_factor) {
    set_factors(red_factor, green_factor, blue_factor);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void FilterRBG::set_factors(float red_factor,
                            float green_factor,
                            float blue_factor) {
    red_factor_ = red_factor;
    blue_factor_ = blue_factor;
    green_factor_ = green_factor;
    return;
}

void FilterRBG::set_color_data(ColorData * pixel) {
    pixel->red(pixel->red() * red_factor_);
    pixel->green(pixel->green() * green_factor_);
    pixel->blue(pixel->blue() * blue_factor_);
    return;
}

}  /* namespace image_tools */
