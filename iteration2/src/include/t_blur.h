/*******************************************************************************
 * Name            : t_spray_can.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for SprayCan tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_T_BLUR_H_
#define ITERATION2_SRC_INCLUDE_T_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "include/tool.h"
#include "include/m_linear.h"
#include "include/filter_blur.h"
#include "include/color_data.h"
#include "include/pixel_buffer.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief SETH FILL THIS IN
 */
class TBlur : public Tool {
 public:
  TBlur(void);
  std::string name(void) { return "Blur"; }
  void ApplyToBuffer(int tool_x,
                     int tool_y,
                     ColorData tool_color,
                     PixelBuffer* buffer);
 protected:
  FilterBlur * blur_filter;
};

}  /* namespace image_tools */

#endif  // ITERATION2_SRC_INCLUDE_T_BLUR_H_
