/*******************************************************************************
 * Name            : MotionBlurKernel
 * Project         : image_tools
 * Module          : Filter
 * Description     : Header file for motion_blur_kernel.c
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 
 * Original Author : 
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_MOTION_BLUR_KERNEL_H_
#define ITERATION2_SRC_INCLUDE_MOTION_BLUR_KERNEL_H_

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
class MotionBlurKernel : public Kernel {
 public:
    MotionBlurKernel(void);
    explicit MotionBlurKernel(float amount, int direct);

 protected:
     void GenerateKernel(void);
     void set_factor(int size);
     void switch_direction(int direct);
     // float factor;
};

}  /* namespace image_tools */

#endif  // ITERATION2_SRC_INCLUDE_MOTION_BLUR_KERNEL_H_

