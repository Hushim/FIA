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

#ifndef COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_FILTER_MANAGER_H_
#define COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_FILTER_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "GL/glui.h"
/* FIXME: ADDITIONAL INCLUDES AS NECESSARY HERE :-) */
#include "ui_ctrl.h"
#include "filter_factory.h"

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
class FilterManager {
 public:
/**
 * @brief FilterManger class constructor
 */
  FilterManager();
/**
 * @brief FitlerManger class de-constructor
 */
  ~FilterManager() {}

  /**
   * @brief Apply a blur filter to the buffer, blurring sharply defined edges
   *
   * @param buffer The buffer. Updated to point to a new filtered buffer.
   */
   void ApplyBlur(PixelBuffer **buffer);

 /**
  * @brief Apply a sharpening filter to the buffer, sharpening blurry/undefined
  * edges
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplySharpen(PixelBuffer **buffer);

 /**
  * @brief Apply a motion blurring filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplyMotionBlur(PixelBuffer **buffer);

 /**
  * @brief Apply an edge detection filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplyEdgeDetect(PixelBuffer **buffer);

 /**
  * @brief Apply a threshold detection filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplyThreshold(PixelBuffer **buffer);

 /**
  * @brief Apply a channel filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplyChannel(PixelBuffer **buffer);

 /**
  * @brief Apply a channel filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplySaturate(PixelBuffer **buffer);


 /**
  * @brief Apply a quantization filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplyQuantize(PixelBuffer **buffer);

 /**
  * @brief Apply a special filter to the buffer
  *
  * @param buffer The buffer. Updated to point to a new filtered buffer.
  */
 void ApplySpecial(PixelBuffer **buffer);


  /**
   * @brief Initialize the elements of the GLUI interface required by the
   * FilterManager
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   */
  virtual GLUI_Panel* InitGlui(const GLUI *const glui,
                               void (*s_gluicallback)(int));

 protected:
/**
 * @brief Initialize blur filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddBlurToGLUI(GLUI_Panel *filter_panel, void (*s_gluicallback)(int));
/**
 * @brief Initialize motion blur filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddMotionBlurToGLUI(GLUI_Panel *filter_panel,
                           void (*s_gluicallback)(int));
/**
 * @brief Initialize sharpen filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddSharpenToGLUI(GLUI_Panel *filter_panel,
                        void (*s_gluicallback)(int));
/**
 * @brief Initialize edge detection filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddEdgeDetectToGLUI(GLUI_Panel *filter_panel,
                           void (*s_gluicallback)(int));
/**
 * @brief Initialize threshold filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddThresholdToGLUI(GLUI_Panel *filter_panel,
                          void (*s_gluicallback)(int));
/**
 * @brief Initialize saturate filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddSaturationToGLUI(GLUI_Panel *filter_panel,
                           void (*s_gluicallback)(int));
/**
 * @brief Initialize channels filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddChannelToGLUI(GLUI_Panel *filter_panel,
                        void (*s_gluicallback)(int));
/**
 * @brief Initialize quantize filter gui 
 * @param filter_panel defied in glui library and gui event handler callback function
 */
  void AddQuantizationToGLUI(GLUI_Panel *filter_panel,
                             void (*s_gluicallback)(int));

 private:
  float channel_color_red_;
  float channel_color_green_;
  float channel_color_blue_;
  float saturation_amount_;
  float threshold_amount_;
  float blur_amount_;
  float sharpen_amount_;
  float motion_blur_amount_;
  enum UICtrl::MotionBlurDirection motion_blur_direction_;
  int quantize_bins_;
};

}  /* namespace image_tools */

#endif  /* COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_FILTER_MANAGER_H_ */
