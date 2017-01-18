/*******************************************************************************
 * Name            : filter_threshould.h
 * Project         : FlashPhoto
 * Module          : Filter
 * Description     : Header for FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_FILTER_THRESHOLD_H_
#define ITERATION2_SRC_INCLUDE_FILTER_THRESHOLD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
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
class FilterThreshold : public Filter {
 public:
     FilterThreshold(void);
     explicit FilterThreshold(float th);
     void set_threshold(float th);
     float get_threshold(void);
     void set_color_data(ColorData * pixel);

 protected:
     float threshold_;
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_FILTER_THRESHOLD_H_
