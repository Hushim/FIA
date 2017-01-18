/*******************************************************************************
 * Name            : motion_blur_kernel.cc
 * Project         : FlashPhoto
 * Module          : Tool
 * Description     : Implementation of MotionBlurKernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   :
 * Original Author :
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <iostream>
#include "include/motion_blur_kernel.h"
#include "include/m_oval.h"
#include "include/color_data.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
MotionBlurKernel::MotionBlurKernel() {}

MotionBlurKernel::MotionBlurKernel(float amount, int direct) {
    std::cout << "start constructors\n";
    size = (amount / 2) * 2 + 1;
    set_factor(size);
    GenerateKernel();
    switch_direction(direct);
    std::cout << "end constructors\n";
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionBlurKernel::GenerateKernel(void) {
    std::cout << "start kernal matrix\n";
    kernel_array_ = new float[size*size];
    switch_direction(0);
}

void MotionBlurKernel::switch_direction(int direct) {
  std::cout << "start switch " << direct << "\n";
    switch (direct) {
      case 0 : {
        for (int row = 0; row < size; row += 1) {
          for (int col = 0; col < size; col += 1) {
                    if (col == size/2) {
                        kernel_array_[size * row + col] = 1;
                    } else {
                        kernel_array_[size * row + col] = 0;
                    }
                }
            }

            break;
        }
        case 1 : {
            for (int row = 0; row < size; row += 1) {
                for (int col = 0; col < size; col += 1) {
                    if (size/2 == row) {
                        kernel_array_[size * row + col] = 1;
                    } else {
                        kernel_array_[size * row + col] = 0;
                    }
                }
            }
            break;
        }
        case 2 : {
            int one = size -1;
            for (int row = 0; row < size; row += 1) {
                for (int col = 0; col < size; col += 1) {
                    if (col == one) {
                        kernel_array_[size * row + col] = 1;
                    } else {
                        kernel_array_[size * row + col] = 0;
                    }
                }
                one -= 1;
            }
            break;
        }
        case 3 : {
            for (int row = 0; row < size; row += 1) {
                for (int col = 0; col < size; col += 1) {
                    if (col == row) {
                        kernel_array_[size * row + col] = 1;
                    } else {
                        kernel_array_[size * row + col] = 0;
                    }
                }
            }
            break;
        }
    }
}

void MotionBlurKernel::set_factor(int size) {
    factor = 1.f / size;
    std::cout << "set factor with size " << size <<
    "and factor " << "factor " << factor << std::endl;
}

}  /* namespace image_tools */
