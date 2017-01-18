/*******************************************************************************
 * Name            : color_data.cc
 * Project         : BrushWork
 * Module          : image_tools
 * Description     : Implementation of ColorData class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/kernel.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
Kernel::Kernel(float amount) {}
Kernel::Kernel() {}
Kernel::~Kernel(void) {}


float Kernel::get_factor() {
    return factor;
}

int Kernel::get_size() {
  return size;
}

void Kernel::set_size(int s) {
    size = s;
    return;
}

void Kernel::set_array(int x, int y, float val) {
    kernel_array_[x * size + y] = val;
    return;
}

float Kernel::get_array(int x, int y) {
  return kernel_array_[x * size + y];
}

void Kernel::GenerateKernel(void) {}
void set_factor(int size) {}

}  /* namespace image_tools */
