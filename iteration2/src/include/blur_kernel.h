/*******************************************************************************
 * Name            : BlurKernel
 * Project         : image_tools
 * Module          : Filter
 * Description     : Header file for blur_kernel.c
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 
 * Original Author : 
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_BLUR_KERNEL_H_
#define ITERATION2_SRC_INCLUDE_BLUR_KERNEL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <string>
#include "include/kernel.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**

 */
class BlurKernel : public Kernel {
 public:
  BlurKernel();
  explicit BlurKernel(float amount);

 protected:
    void GenerateKernel(void);
    void set_factor(int size);
    // void set_size(int s);
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_BLUR_KERNEL_H_
