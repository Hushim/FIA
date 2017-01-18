/*******************************************************************************
 * Name            : border_detection_kernel.cc
 * Project         : FlashPhoto
 * Module          : Tool
 * Description     : Implementation of BordreDetectionKernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 
 * Original Author : 
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/border_detection_kernel.h"
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
BorderDetectionKernel::BorderDetectionKernel(void) {}
BorderDetectionKernel::BorderDetectionKernel(float amount) {
    set_size((amount / 2) * 2 + 1);
    set_factor(size);
    GenerateKernel();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void BorderDetectionKernel::GenerateKernel(void) {
    kernel_array_ = new float[size * size];
    for (int row = 0; row < size; row += 1) {
        for (int col = 0; col < size; col += 1) {
            if (col == size/2 && row == size/2) {
                kernel_array_[size*row + col] = size*size - 1;
            } else {
                kernel_array_[size*row + col] = -1;
            }
        }
    }
}


void BorderDetectionKernel::set_factor(int size) {
    factor  = 1;
    return;
}


}  /* namespace image_tools */
