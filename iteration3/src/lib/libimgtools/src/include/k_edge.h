/*******************************************************************************
 * Name            : k_edge.h
 * Project         : FlashPhoto
 * Module          : kernel
 * Description     : Header file for edge kernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/3/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_K_EDGE_H_
#define SRC_INCLUDE_K_EDGE_H_

/*******************************************************************************
 * Class Definitions
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
 * @brief An edge detection kernel
 *
 * Defines a kernel that highlights edges visual edges between colors, and
 * colors non-edge areas black when convolved with an image.
 *
 */
class KEdge : public Kernel {
 public:

  /** 
   * A constructor 
   *
   * A constructor to construct KGaussian
   */
  KEdge();

 protected:

 /**
  * @brief get the intensity from a specific position of a mask
  *
  * @param x the X coordinate of current mask on canvas
  * @param y the Y coordinate of the current mask on canvas
  * @param radius of KEdge
  *
  * @return the intensity from the mask grid 
  */
  float get_intensity(int x, int y, float radius);
};

} /* namespace image_tools */

#endif  /* SRC_INCLUDE_K_EDGE_H_ */
