/*******************************************************************************
 * Name            : filter_quantize.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_FILTER_QUANTIZE_H_
#define ITERATION2_SRC_INCLUDE_FILTER_QUANTIZE_H_

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
 * @brief Manager for all aspects of filters in FlashPhoto, including
 * initialization of GLUI control elements for filters, filter creation,
 * application, deletion.
 */
class FilterQuantize : public Filter {
 public:
    FilterQuantize(void);
    explicit FilterQuantize(float quant);
    void set_quantize(float saturation);
    float get_quantize(void);
    void set_color_data(ColorData * pixel);
 protected:
    float quantize_;
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_FILTER_QUANTIZE_H_
