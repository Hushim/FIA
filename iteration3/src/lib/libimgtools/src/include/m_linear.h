/*******************************************************************************
 * Name            : m_linear.h
 * Project         : image_tools
 * Module          : Mask
 * Description     : Header file for Linear mask class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_M_LINEAR_H_
#define SRC_INCLUDE_M_LINEAR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/mask.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief MLinear is a Mask that is round, with a linear fall-off from full
 * intensity at the center to no intensity at the  extremity.
 */
class MLinear : public Mask {
 public:
/**
* A constructor to contruct linear mask Mlinear and set initial values 
* for member variables.
*/
  MLinear(float radius, float opacity); 

 protected:
/**
 * @brief Define the shape of the mask.
 * @param x The X coordinate of the tool/mouse location
 * @param y The Y coordinate of the tool/mouse location
 * @param radius Distance from (x,y) tool/mouse location to compute intensity
 * at
*/
  float get_intensity(int x, int y, float radius);
};

}  /* namespace image_tools */

#endif  /* SRC_INCLUDE_M_LINEAR_H_ */
