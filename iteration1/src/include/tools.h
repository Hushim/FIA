/*******************************************************************************
 * Name            : tools
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for tools class.
 * Copyright       : 2016 CSCI3081W group C4. All rights reserved.
 * Creation Date   : 10/10/16
 * Original Author : Zixiang Ma
 ******************************************************************************/
#ifndef INCLUDE_TOOLS_H_
#define INCLUDE_TOOLS_H_
#define MASK_SIZE 41
#include "include/color_data.h"
#include "include/pixel_buffer.h"
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Tools{
    public:
        Tools();

        virtual ~Tools(void);
        // void set_transparent(float t);
        // float get_transparent();

        int init_mask();
        int free_mask();

        float ** get_mask();
        float get_mask_data(int row, int col);
        virtual void set_mask();

        int get_mask_size();
        virtual void set_mask_size();

        virtual void calculate_color(
                                  int mask_row,
                                  int mask_col,
                                  int coordinate_x,
                                  int coordinate_y,
                                  int pixel_coodinate_x,
                                  int pixel_coodinate_y,
                                  const ColorData color,
                                  PixelBuffer **pixel_buffer_);
        virtual void apply_color_to_mask(
                            int coordinate_x,
                            int coordinate_y,
                            const ColorData color,
                            PixelBuffer **pixel_buffer_);

    protected:

        int mask_size;
        float ** mask;
        float mask_center;

        float calculate_mask_center();
        float calculate_distance_from_mask_center(
                                            int mask_row,
                                            int mask_col,
                                            float mask_center);
};
} // namespace image_tools;

#endif

