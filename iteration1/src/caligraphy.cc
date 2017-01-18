/*******************************************************************************
 * Name            : caligraphy.cc
 * Project         : BrushWork
 * Module          : App
 * Description     : Implementation of Caligraphy Pen
 * Copyright       : 2016 CSCI3081W Group C04. All rights reserved.
 * Creation Date   : 10/11/2016
 * Original Author : Zhouman Wu
 *
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
  #include "include/caligraphy.h"
  #include <iostream>

/*******************************************************************************
   * Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/

	CaligraphyPen :: CaligraphyPen() {
		height = HEIGHT;
		width = WIDTH;
		set_mask();
	}

	CaligraphyPen :: ~CaligraphyPen(void) {
	}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 	void CaligraphyPen::set_mask() {
 		Tools :: set_mask();
 		for (int row = 0; row < mask_size; row++) {
 			for (int col = 0; col < mask_size; col++) {
 				if (
					 abs(col - mask_center) <= height/2 
					 && abs(row - mask_center) <= width/2) {
 					mask[row][col] = 1.0;
 				} else {
 					mask[row][col] = 0;
 				}
 			}
 		}
 	}

  void CaligraphyPen::set_mask_size() {}

}  // namespace image_tools
