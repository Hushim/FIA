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

#ifndef ITERATION2_SRC_INCLUDE_IMAGE_CONTROLLER_H_
#define ITERATION2_SRC_INCLUDE_IMAGE_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "include/pixel_buffer.h"
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
class ImageController {
 public:
     static PixelBuffer* LoadImage(const std::string &name);
    // static PixelBuffer* LoadStamp(const std::string &name);
     static void SaveImage(const std::string &name,
                        const PixelBuffer * bufferToSave);
};


}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_IMAGE_CONTROLLER_H_
