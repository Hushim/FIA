/*******************************************************************************
 * Name            : k_motion_blur.h
 * Project         : FlashPhoto
 * Module          : kernel
 * Description     : Header file for motion blur kernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/4/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_K_MOTION_BLUR_H_
#define SRC_INCLUDE_K_MOTION_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/kernel.h"
#include "include/ui_ctrl.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A directional motion blurring kernel
 *
 * Defines a kernel that blurs pixels along a straight line when convolved
 * with an image.
 */
class KMotionBlur : public Kernel {
 public:

  /** 
   * A constructor 
   *
   * A constructor to construct KMotionBlur
   */
  KMotionBlur(float amount, enum UICtrl::MotionBlurDirection);

 protected:

 /**
  * @brief get the intensity from a specific position of a mask
  *
  * @param x the X coordinate of current mask on canvas
  * @param y the Y coordinate of the current mask on canvas
  * @param radius the radius of KMotion
  *
  * @return the intensity from the mask grid 
  */
  float get_intensity(int x, int y, float radius);

 private:

  /**
   * @brief The value to determine the degree of bluring
   *
   * This controls how much to blur the canvas.
   *
   */
  float amount_;

  /**
   * @brief The derection when motionbluring .
   *
   * This controls how the direction of motionblur.
   *
   */
  int direction_;
};

} /* namespace image_tools */

#endif /* SRC_INCLUDE_K_MOTION_BLUR_H_ */
