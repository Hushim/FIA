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
  #include "include/special.h"
  #include <iostream>
  #include "include/pixel_buffer.h"
  #include "include/color_data.h"
  #include "include/tools.h"
  #include <stdlib.h>     /* srand, rand */
  #include <time.h>       /* time */
/*******************************************************************************
* Namespaces
******************************************************************************/
namespace image_tools {
/*******************************************************************************
* Constructors/Destructors
******************************************************************************/
	Special::Special() {
    	radius = RADIUS;
    	set_mask();
	}

	Special::~Special(void) {
	}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
   void Special::set_mask_size() {}

   void Special::set_mask() {
   		Tools :: set_mask();
   		for (int row = 0; row < mask_size; row++) {
   			for (int col = 0; col < mask_size; col++) {
   				 if (
              calculate_distance_from_mask_center(row, col, mask_center) 
              <= 
              radius) {
 					  mask[row][col] = 1.0;
 				   } else {
 					  mask[row][col] = 0.0;
 				 }
   			}
   		}
   }





void Special::apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_) {
  int set_pixel_coodinate_x;
  int set_pixel_coodinate_y;

  int width = (**pixel_buffer_).width();
  int height = (**pixel_buffer_).height();
  srand(time(NULL));
  for (int row = 0; row < mask_size; row+=5) {
      float r1 = (float) rand()/(RAND_MAX);
      float r2 = (float) rand()/(RAND_MAX);
      float r3 = (float) rand()/(RAND_MAX);
      printf("special color are: %ld, %ld, %ld \n", r1, r2, r3);
      ColorData * random_color = new ColorData(r1, r2, r3);
    for (int col = 0; col < mask_size; col++) {
      set_pixel_coodinate_x = coordinate_x - mask_size/2 + row;
      set_pixel_coodinate_y = coordinate_y - mask_size/2 + col;
      if (
        set_pixel_coodinate_x < 0
        || set_pixel_coodinate_y < 0
        || set_pixel_coodinate_x > width
        || set_pixel_coodinate_y > height) {
        printf("set pixel coordinate x and y are out of range\n");
      } else {
        calculate_color(
                    row,
                    col,
                    coordinate_x,
                    coordinate_y,
                    set_pixel_coodinate_x,
                    height - (set_pixel_coodinate_y + 1),
                    // transform coordinates.
                    (*random_color), pixel_buffer_);
      }
    }
  }
}




}  // namespace image_tools
