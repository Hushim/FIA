/*******************************************************************************
 * Name            : filter_manager.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_PNG_CONTROLLER_H_
#define ITERATION2_SRC_INCLUDE_PNG_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include <png.h>
// #include <zlib.h>
#include <cstring>;
#include <string>
#include "include/image_controller.h"
#include "include/pixel_buffer.h"
// #include <png.h>
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
class PngController : ImageController{
 public:
    PngController();
    virtual ~PngController();

    static PixelBuffer* LoadImage(const std::string &name) {
      PixelBuffer* load_buffer;
      png_image image;
      memset(&image, 0, (sizeof(png_image)));
      image.version = PNG_IMAGE_VERSION;
      if (png_image_begin_read_from_file(&image,  name.c_str())) {
        load_buffer = new
        PixelBuffer(image.width, image.height, ColorData(0.0, 0.0, 0.0));
        png_bytep buffer;
        image.format = PNG_FORMAT_RGBA;
        buffer = new png_byte[PNG_IMAGE_SIZE(image)];
        if (buffer != NULL && png_image_finish_read(&image, NULL,
          buffer, 0, NULL)) {
          int height = image.height;
          int width = image.width;
          float red;
          float green;
          float blue;
          float alpha;
          for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
              red = buffer[(row*width*4)+4*col]/255.0;
              green = buffer[(row*width*4)+4*col+1]/255.0;
              blue = buffer[(row*width*4)+4*col+2]/255.0;
              alpha = buffer[(row*width*4)+4*col+3]/255.0;
              load_buffer->set_pixel(col, height-(row+1),
              ColorData(red, green, blue, alpha));
            }
          }
        }
      }
      return load_buffer;
    }

    static void  SaveImage(const std::string &name,
      PixelBuffer ** display_buffer) {
        png_image image;
      memset(&image, 0, (sizeof image));
      image.height = (*display_buffer)->height();
      image.width = (*display_buffer)->width();
      image.version = PNG_IMAGE_VERSION;
      image.opaque = NULL;
      image.format = PNG_FORMAT_RGBA;
      png_bytep buffer = new png_byte[PNG_IMAGE_SIZE(image)];
      for (int row = image.height-1; row >= 0; row--) {
        for (int col = 0; col < image.width; col++) {
          ColorData tmp_color = (*display_buffer) -> get_pixel(col, row);
          buffer[((image.height-(row+1))*image.width+col)*4] =
          (png_byte) (tmp_color.red()*255.f);
          buffer[((image.height-(row+1))*image.width+col)*4+1] =
          (png_byte) (tmp_color.green()*255.f);
          buffer[((image.height-(row+1))*image.width+col)*4+2] =
          (png_byte) (tmp_color.blue()*255.f);
          buffer[((image.height-(row+1))*image.width+col)*4+3] =
          (png_byte) (tmp_color.alpha()*255.f);
        }
      }
      if (png_image_write_to_file(&image, name.c_str(), 0, buffer, 0, NULL)
      != 0) {
        printf("Saved successfully!\n");
      } else {
        fprintf(stderr, "Failed to save\n");
      }
    }
};
}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_PNG_CONTROLLER_H_
