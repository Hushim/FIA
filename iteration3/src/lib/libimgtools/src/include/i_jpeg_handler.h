/*******************************************************************************
 * Name            : i_jpeg_handler.h
 * Project         : image_tools
 * Module          : io_handler
 * Description     : Header file for JPEG I/O handler
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/2/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_I_JPEG_HANDLER_H_
#define SRC_INCLUDE_I_JPEG_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <jpeglib.h>
#include <setjmp.h>
#include <string>
#include "include/image_handler.h"
#include "include/pixel_buffer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Handles JPEG image loading/saving using the libjpeg library. This is a
 * static class, serving as more of a namespace for grouping common
 * functionality.
 *
 */
class IJPEGHandler : public ImageHandler {
 public:

  /**
   * @brief Load the image.
   *
   * @param file_name Pathname of the file
   *
   * @return PixelBuffer which stores information of the image
   */
  static PixelBuffer* LoadImage(const std::string file_name);

  /**
   * @brief Save the image file. 
   *
   * @param file_name Pathname of the file
   * @param buffer Pixelbuffer of the file
   * @return TRUE if save successfully
   */
  static bool SaveImage(const std::string file_name,
                        const PixelBuffer* buffer);

 private:
  struct my_error_mgr {
    jpeg_error_mgr pub; /* "public" fields */
    jmp_buf setjmp_buffer; /* for return to caller */
  };
};

} /* namespace image_tools */

#endif  /* SRC_INCLUDE_I_JPEG_HANDLER_H_ */
