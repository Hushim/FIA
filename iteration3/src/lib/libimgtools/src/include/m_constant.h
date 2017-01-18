/*******************************************************************************
 * Name            : m_constant.h
 * Project         : image_tools
 * Module          : Mask
 * Description     : Header File for Constant Mask class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_M_CONSTANT_H_
#define SRC_INCLUDE_M_CONSTANT_H_

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
 * @brief MConstant is a Mask that is round, with a constant fill  value.
 */
class MConstant : public Mask {
 public:
/**
 * @brief A constructor to construct constant mask MConstant 
 * and set initial values for member variables.
*/
  MConstant(float radius, float opacity);

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

#endif  /* SRC_INCLUDE_M_CONSTANT_H_ */
