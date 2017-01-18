
/*******************************************************************************
 * Name            : t_rubber_stamp.cc
 * Project         : BrushWok
 * Module          : Tool
 * Description     : Implementation of SprayCan tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "include/t_stamp.h"
#include "include/io_manager.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {


PixelBuffer * TStamp::stamp_buffer_ =
new PixelBuffer(0 , 0, ColorData(0.0, 0.0, 0.0, 0.0));

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

TStamp::TStamp(void) {
}

void TStamp::ApplyToStamp(
    int tool_x,
    int tool_y,
    PixelBuffer** display_buffer) {

    int buffer_x = tool_x - TStamp::stamp_buffer_->width()/2;
    int buffer_y = tool_y - TStamp::stamp_buffer_->height()/2;

    for (int y = 0; y < TStamp::stamp_buffer_->height(); y++) {
      for (int x =0; x < TStamp::stamp_buffer_->width(); x++) {
        if (x+buffer_x >=0 && x+buffer_x < (*display_buffer) ->width()
          && y+buffer_y >=0 && y+buffer_y < (*display_buffer)->height()) {
          ColorData stamp_color = TStamp::stamp_buffer_->get_pixel(x, y);
          (*display_buffer) -> set_pixel(x+buffer_x, y+buffer_y, stamp_color);
        }
      }
    }
}


}  // namespace image_tools
