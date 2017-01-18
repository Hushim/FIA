/*******************************************************************************
 * Name            : k_gaussian.h
 * Project         : FlashPhoto
 * Module          : kernel
 * Description     : Header file for Gaussian kernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/2/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_K_GAUSSIAN_H_
#define SRC_INCLUDE_K_GAUSSIAN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/kernel.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A gaussian kernel
 *
 * This is used for general blurring.
 */
class KGaussian : public Kernel {
 public:

  /** 
   * A constructor 
   *
   * A constructor to construct KGaussian
   */
  explicit KGaussian(float sigma);

  /** 
   * A constructor 
   *
   * A constructor to construct KGaussian
   */
  KGaussian(void);

 protected:
  /**
   * @brief The standard deviation of the Gaussian kernel.
   *
   * This controls how the values fall off from the center of the kernel.
   *
   */
  float sigma_;

 /**
  * @brief get the intensity from a specific position of a mask
  *
  * @param x the X coordinate of current mask on canvas
  * @param y the Y coordinate of the current mask on canvas
  * @param radius the radius of Gaussian
  *
  * @return the intensity from the mask grid 
  */
  float get_intensity(int x, int y, float radius);
};

} /* namespace image_tools */

#endif  /* SRC_INCLUDE_K_GAUSSIAN_H_ */
