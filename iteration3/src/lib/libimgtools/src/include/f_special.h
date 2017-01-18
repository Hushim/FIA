/*******************************************************************************
 * Name            : f_special.h
 * Project         : FlashPhoto
 * Module          : filter
 * Description     : Header file for FSpecial class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/7/15
 * Original Author : Sarit Ghildayal
 *
******************************************************************************/

#ifndef SRC_INCLUDE_F_SPECIAL_H_
#define SRC_INCLUDE_F_SPECIAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "include/filter.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Implements a "night-vision" filter
 *
 */
class FSpecial: public Filter {
/**
 * @brief process canvas PixelBuffer object with the filter. 
 * @param input_buffer  is the current canvas (PixelBuffer obejct)
 * @return Return a PixelBuffer pointer
 */
 public:
  PixelBuffer *GenerateFilteredBuffer(const PixelBuffer &input_buffer)const;

 private:
  virtual ColorData GeneratePixel(const PixelBuffer &buffer,
                                   const PixelBuffer &blurred_buffer,
                                   int x, int y) const;
};

} /* namespace image_tools */

#endif  /* SRC_INCLUDE_F_SPECIAL_H_ */
