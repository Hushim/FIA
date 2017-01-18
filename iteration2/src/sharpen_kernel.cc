/*******************************************************************************
 * Name            : sharpen_kernel.cc
 * Project         : FlashPhoto
 * Module          : Tool
 * Description     : Implementation of SharpenKernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 
 * Original Author : 
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/sharpen_kernel.h"
#include <string>
#include "include/m_oval.h"
#include "include/color_data.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

SharpenKernel::SharpenKernel() {}

SharpenKernel::SharpenKernel(float amount) {
    // size = (amount / 2) * 2 + 1;
    set_size((amount / 2) * 2 + 1);
    set_factor(size);
    GenerateKernel();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SharpenKernel::GenerateKernel(void) {
    kernel_array_ = new float[size*size];
    for (int row = 0; row < size; row += 1) {
        for (int col = 0; col < size; col += 1) {
            if (row == size/2 && col == size/2) {
                // kernel_array_[row*size + col] = size*size -1;
                set_array(row, col, size*size);
            }    else {
                // kernel_array_[row*size + col] = -1;
                set_array(row, col, -1);
            }
        }
    }
    return;
}


void SharpenKernel::set_factor(int size) {
    factor = 1;
    return;
}


}  /* namespace image_tools */
