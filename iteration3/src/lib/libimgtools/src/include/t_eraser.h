/*******************************************************************************
 * Name            : t_eraser.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for Eraserclass
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_T_ERASER_H_
#define SRC_INCLUDE_T_ERASER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "include/tool.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This tool simulates the usage of an Eraser.
 * It has a constant mask with a radius of 10.0 (diameter of 21) and an
 * opacity of 1.0 Eraser overrides the color_blend_math() function to provide its
 * special eraser functionality.
 */
class TEraser : public Tool {
 public:
 /**
  * @brief A constructor to construct TEraser
  */
  TEraser(void);
  /**
   * @brief Override the implementation in tool class
   */
  ColorData color_blend_math(
      float mask_pixel_amount,
      ColorData tool_color,
      ColorData current_color,
      ColorData background_color);
  /**
   * @brief Get the name of the specific tool
   * @return the name of the specific tool 
   */
  std::string name(void) { return "Eraser"; }
};

}  /* namespace image_tools */

#endif  /* SRC_INCLUDE_T_ERASER_H_ */