/*******************************************************************************
<<<<<<< HEAD
 * Name            : filter_manager.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
=======
 * Name            : filter.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for Filter base class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Zixiang Ma
>>>>>>> master
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_FILTER_H_
#define ITERATION2_SRC_INCLUDE_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/color_data.h"
#include "include/pixel_buffer.h"
#include "include/kernel.h"
/*******************************************************************************
 * Namespaces
=======
#include <string>
#include "include/pixel_buffer.h"
#include "include/color_data.h"
#include "include/mask.h"

/*******************************************************************************
 * Namespace Definitions
>>>>>>> master
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief
 */
class Filter {
 public:
  Filter(void);
  ~Filter(void);
  virtual void set_color_data(ColorData * pixel);
  void apply_filter_to_photo(PixelBuffer * display_buffer);
  virtual void set_color_data(int row, int col,
                              PixelBuffer * display_buffer,
                              PixelBuffer * canvas_copy);
  void apply_conv_filter_to_photo(PixelBuffer * display_buffer);
  virtual void apply_conv_filter_to_photo(PixelBuffer * display_buffer,
                                          PixelBuffer * canvas_copy,
                                          int left,
                                          int right,
                                          int upper,
                                          int lower);
 protected:
  Kernel * matrix;
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_FILTER_H_
