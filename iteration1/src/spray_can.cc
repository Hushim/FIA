/*******************************************************************************
 * Name            : Spraycan
 * Project         : spraycan class
 * Module          : App
 * Description     : SprayCan implementation
 * Copyright       : 2016 CSCI3081W Group C04. All rights reserved.
 * Creation Date   : 10/11/2016
 * Original Author : Zixiang Ma
 *
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
  #include "include/spray_can.h"
  #include <iostream>

/*******************************************************************************
   * Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/
	SprayCan::SprayCan() {
      effective_radius = EFFECTIVE_RADIUS;
      set_mask();
	}

	SprayCan::~SprayCan(void) {
	}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 void SprayCan::set_mask_size() {}

  void SprayCan::set_mask() {
 		Tools :: set_mask();
 		for (int row = 0; row < mask_size; row++) {
 			for (int col = 0; col < mask_size; col++) {
        		float dist = calculate_distance_from_mask_center(row, col, mask_center);
 				if (dist < effective_radius) {
 					mask[row][col] = 0.20*(1.0 - (dist/ effective_radius));
 				} else {
 					mask[row][col] = 0;
 				}
 			}
 		}
 	}
}  // namespace image_tools
