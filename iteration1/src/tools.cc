/*******************************************************************************
 * Name            : tools
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for tools class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/10/16
 * Original Author : Zixiang Ma
 ******************************************************************************/
 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/tools.h"
#include <iostream>
#include <cstring>
#include <new>


/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

 namespace image_tools{

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
Tools::Tools(){
  init_mask();
  set_mask();
}

Tools::~Tools(void){
  free_mask();
}

 /*******************************************************************************
 * Member Functions
 ******************************************************************************/

int Tools::init_mask(){

  set_mask_size();
  //initialize a 41*41 raw mask 
  mask = new (std::nothrow) float* [mask_size];
  if(mask == 0){
    printf("Fialed to malloc memories for mask\n");
    return -1;
  }
  for(int col = 0 ; col < mask_size; col++){
    mask[col] = new (std::nothrow) float [mask_size];
    if(mask[col] == 0){
      printf("Failed to malloc memories for mask[%d]\n", col);
      return -1;
    }
  }

  return 0;
}

int Tools::free_mask(){
  for(int col = 0; col < mask_size; col++){
    delete [] mask[col];
  }
  delete [] mask;
  return 0;
}

void Tools::set_mask_size(){
  mask_size = MASK_SIZE;
}

void Tools::set_mask(){
  mask_center = calculate_mask_center();
}

float Tools::calculate_mask_center(){
  return (int)((this->get_mask_size() - 1)/2);
}

float Tools::calculate_distance_from_mask_center(
                                        int mask_row,
                                        int mask_col,
                                        float mask_center){
  float distance = sqrt(pow((mask_row - mask_center),2) + pow((mask_col - mask_center), 2));
  return distance;
}

int Tools::get_mask_size(){
  return mask_size;
}

//get transparent information from mask
float Tools::get_mask_data(int row, int col){
  if(row <= mask_size && row >=0 && col <= mask_size && col >= 0){
    return mask[row][col];
  }else{
    printf("row: %d, col: %d are out ouf mask size\n",row, col);
    return -1;
  }
}

void Tools::calculate_color(
                  int mask_row,
                  int mask_col,
                  int coordinate_x,
                  int coordinate_y,
                  int pixel_coodinate_x,
                  int pixel_coodinate_y,
                  const ColorData color,
                  PixelBuffer **pixel_buffer_){

  //get canvas color and adjust it accoding to principles of differnet tools
  ColorData previous_pixel = (**pixel_buffer_).get_pixel(pixel_coodinate_x, pixel_coodinate_y);
  ColorData adapted_backgroud_color = previous_pixel * (1 - this->get_mask_data(mask_row, mask_col));

  //set new color on canvas while applying tools on it
  (**pixel_buffer_).set_pixel(
                      pixel_coodinate_x, 
                      pixel_coodinate_y, 
                      adapted_backgroud_color + color * this->get_mask_data(mask_row, mask_col));

}


void Tools::apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_){
  int set_pixel_coodinate_x;
  int set_pixel_coodinate_y;

  int width = (**pixel_buffer_).width();
  int height = (**pixel_buffer_).height();

  //iterate the mask and apply color at legal coordinate
  for(int row = 0; row < mask_size; row++){
    for(int col = 0; col < mask_size; col++){
      set_pixel_coodinate_x = coordinate_x - mask_size/2 + row;
      set_pixel_coodinate_y = coordinate_y - mask_size/2 + col;

      if(set_pixel_coodinate_x < 0 || set_pixel_coodinate_y < 0 || set_pixel_coodinate_x > width || set_pixel_coodinate_y > height){
        //test information: printf("set pixel coordinate x and y are out of range\n");
      }else{
        //calculate expected color here
        calculate_color(
                    row,
                    col,
                    coordinate_x,
                    coordinate_y,
                    set_pixel_coodinate_x,
                    height - (set_pixel_coodinate_y + 1), // transform coordinates.
                    color,
                    pixel_buffer_);
      }
    }
  }
}
}
