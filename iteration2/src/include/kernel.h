/*******************************************************************************
 * Name            : Mask.h
 * Project         : image_tools
 * Module          : Mask
 * Description     : Header file for Mask base class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_KERNEL_H_
#define ITERATION2_SRC_INCLUDE_KERNEL_H_

 /*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Base class for representing the shape of a tool.
 * Mask is a wrapper for the array of floats representing the shape of a
 * tool. It does not have a shape; shapes are defined implicitly with
 * get_intensity().
 */
class Kernel {
 public:
  // Mask(float radius, float opacity);
  Kernel();
  explicit Kernel(float amount);
  ~Kernel(void);

  float const * float_array(void) const { return kernel_array_; }
  virtual void GenerateKernel(void);
  void set_array(int x, int y, float val);
  float get_array(int x, int y);

  // virtual void set_factor(int size);
  float get_factor(void);

  void set_size(int s);
  int get_size(void);
 protected:
  float * kernel_array_;
  float factor;
  int size;
};

}  /* namespace image_tools */

#endif  // ITERATION2_SRC_INCLUDE_KERNEL_H_
