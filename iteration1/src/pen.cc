/*******************************************************************************
 * Name            : pen.h
 * Project         : pen class
 * Module          : App
 * Description     : Header file for pen application.
 * Copyright       : 2016 CSCI3081W Group C04. All rights reserved.
 * Creation Date   : 10/11/2016
 * Original Author : Zixiang Ma
 *
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
  #include "include/pen.h"
  #include <iostream>

/*******************************************************************************
   * Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/
  Pen::Pen() {
    radius = RADIUS;
    set_mask();
  }

  Pen::~Pen(void) {
  }
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
  // initialize static variable
  // Pen * Pen::pen_instance = NULL;

 //  get_instance return the single instance of pen
 // Pen * Pen::get_instance(){
 //    if(pen_instance == NULL){
 //      pen_instance = new Pen();
 //    }
 //    return pen_instance;
 // }
  void Pen::set_mask_size() {}
  void Pen::set_mask() {
    Tools :: set_mask();
    // printf("mask center %f\n", mask_center);
    for (int row = 0; row < mask_size; row++) {
      for (int col = 0; col < mask_size; col++) {
 	    if (calculate_distance_from_mask_center(row, col, mask_center) <= radius) {
 		  mask[row][col] = 1.0;
 		} else {
            mask[row][col] = 0.0;
 		}
      }
    }
  }
  // void Pen::set_mask_size(){};
}    // namespace image_tools
