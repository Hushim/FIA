/*******************************************************************************
 * Name            : t_rubber_stamp.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for Rubber Stamp tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_T_STAMP_H_
#define ITERATION2_SRC_INCLUDE_T_STAMP_H_

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
 * @brief This tool simulates the usage of a Pen.
 * It has a constant mask with a radius of 1.0 (diameter of 3) and an opacity
 * of 1.0
 */
class TStamp : public Tool {
 public:
  TStamp(void);
  //  { mask(new MConstant(1.0, 1.0));}

  static void SetStampBuffer(PixelBuffer * current_stamp_buffer) {
    stamp_buffer_ = current_stamp_buffer;
  }

  void ApplyToStamp(
    int tool_x,
    int tool_y,
    PixelBuffer ** display_buffer);

  std::string name(void) { return "Stamp"; }

  static PixelBuffer * stamp_buffer_;
};

}  /* namespace image_tools */

#endif  // ITERATION2_SRC_INCLUDE_T_STAMP_H_
