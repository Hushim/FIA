/*******************************************************************************
 * Name            : blur_kernel.cc
 * Project         : FlashPhoto
 * Module          : Tool
 * Description     : Implementation of BlurKernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 
 * Original Author : 
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/blur_kernel.h"
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
BlurKernel::BlurKernel() {}

BlurKernel::BlurKernel(float amount) {
  // set_size((amount / 2) * 2 + 1);
  size = (static_cast<int>(amount) / 2) * 2 + 1;
  set_factor(size);
  GenerateKernel();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void BlurKernel::GenerateKernel(void) {
  int size = size;
  kernel_array_ = new float[size * size];
  int left = size / 2;
  int right = size / 2;
  for (int row = 0; row < size; row += 1) {
    for (int col = 0; col < size; col += 1) {
    // upper half
      if (row <= size / 2) {
          if (col >= left && col <= right) {
           set_array(row, col, 1);
        } else {
            set_array(row, col, 0);
        }
        // lower half
    } else {
        if (col >= left && col <= right) {
            set_array(row, col, 1);
        } else {
            set_array(row, col, 0);
           }
        }
    }
    if (row < size/2) {
        left -= 1;
        right += 1;
    } else if (row > size/2) {
        left += 1;
        right -= 1;
    }
  }
}


void BlurKernel::set_factor(int size) {
    factor = size+0.0;
    for (int i = size-2; i > 0; i -= 2) {
       factor += size * 2.0;
    }
    factor = 1.0 / factor;
    return;
}

// void set_size(int s) {
//   size = s;
//   return;
// }

} /* namespace image_tools */
