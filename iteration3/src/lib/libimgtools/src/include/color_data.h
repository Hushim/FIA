/*******************************************************************************
 * Name            : color_data.h
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for ColorData class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
******************************************************************************/

#ifndef SRC_INCLUDE_COLOR_DATA_H_
#define SRC_INCLUDE_COLOR_DATA_H_

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This color data class stores color in floating point format.
 *
 * The Red, Green, Blue, and Alpha channels range from 0.0 to 1.0.
 */
class ColorData {
 public:
/**
 * @brief ColorData consctructor 
 */
  ColorData(void);
/**
 * @brief ColorData consctructor 
 * @param r variable between 0 and 1 that represents red
 * @param g variable between 0 and 1 that represents green
 * @param b variable between 0 and 1 that represents blue
 * @return ColorData object based on given input
 */
  ColorData(float r, float g, float b);
/**
 * @brief ColorData consctructor 
 * @param r variable between 0 and 1 that represents red
 * @param g variable between 0 and 1 that represents green
 * @param b variable between 0 and 1 that represents blue
 * @param a variable between 0 and 1 that represents intensity 
 * @return ColorData object based on given input
 */
  ColorData(float r, float g, float b, float a);
/**
 * @brief Mutator for red, gree, blue, and alpha
 * @param r variable between 0 - 1 to represent the color red
 * @return ColorData object based on given input
 */
  inline void red(float r) { red_ = r; }
/**
 * @brief Mutator for red, gree, blue, and alpha
 * @param g variable between 0 - 1 to represent the color green
 * @return ColorData object based on given input
 */
  inline void green(float g) { green_ = g; }
/**
 * @brief Mutator for red, gree, blue, and alpha
 * @param b variable between 0 - 1 to represent the color blue
 * @return ColorData object based on given input
 */
  inline void blue(float b) { blue_ = b; }
/**
 * @brief Mutator for red, gree, blue, and alpha
 * @param a represents the intensity
 * @return ColorData object based on given input
 */
  inline void alpha(float a) { alpha_ = a; }
/**
 * @brief Accessor for red
 * @return A float variable between 0 and 1 that represents the color
 */ 
  inline float red(void) const { return red_; }
/**
 * @brief Accessor for green
 * @return A float variable between 0 and 1 that represents the color
 */ 
  inline float green(void) const { return green_; }
/**
 * @brief Accessor blue
 * @return A float variable between 0 and 1 that represents the color
 */ 
  inline float blue(void) const { return blue_; }
/**
 * @brief Accessor for alpha
 * @return A float variable between 0 and 1 that represents the color
 */ 
  inline float alpha(void) const { return alpha_;}

  /**
   * @brief Get the "brightness" of the color according to a perceptual metric
   * that weights the red, green, and blue components of the color
   * non-uniformly.
   */
  float luminance(void) const;

  /**
   * @brief Return a clamped version of a ColorData instance
   *
   * All colors and the alpha value are restricted to [0.0,1.0]
   */
  ColorData clamped_color(void) const;

  /*
   * Arithmetic operators (friends so that non-member functions can access
   * private variables)
   */
  friend ColorData operator* (const ColorData& a, float f);
  friend ColorData operator+ (const ColorData& a, const ColorData& b);
  friend ColorData operator- (const ColorData& a, const ColorData& b);

 private:
  static inline float clamp_value(float input, float a, float b)
  { return input < a ? a : (input > b ? b : input);}

  float red_;
  float green_;
  float blue_;
  float alpha_;
};

}  /* namespace image_tools */

#endif  /* SRC_INCLUDE_COLOR_DATA_H_ */
