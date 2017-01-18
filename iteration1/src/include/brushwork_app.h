/*******************************************************************************
 * Name            : brushwork_app.h
 * Project         : BrushWork
 * Module          : App
 * Description     : Header file for BrushWork application.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef INCLUDE_BRUSHWORK_APP_H_
#define INCLUDE_BRUSHWORK_APP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/base_gfx_app.h"
#include "include/color_data.h"
#include "include/pixel_buffer.h"
#include "include/pen.h"
#include "include/caligraphy.h"
#include "include/highlighter.h"
#include "include/spray_can.h"
#include "include/eraser.h"
#include "include/special.h"
#include <vector>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for BrushWork.
 * It is a graphics app that derives from BaseGfxApp. It creates two graphics
 * windows, one for 2D painting and one for the buttons and other UI widgets to
 * control the brushes.
 **/
class BrushWorkApp : public BaseGfxApp {
 public:
    BrushWorkApp(
        int width,
        int height);

    virtual ~BrushWorkApp(void);

    void MouseDragged(int x, int y);
    void MouseMoved(int x, int y);
    void LeftMouseDown(int x, int y);
    void LeftMouseUp(int x, int y);
    void Display(void);
    void GluiControl(int control_id);
    void InitializeTools();

    virtual void Init(
        int argc,
        char* argv[],
        int x,
        int y,
        ColorData background_color);

 private:
    void InitGlui(void);
    void InitGraphics(void);

    /**
     * @brief Initialize the buffers for the main window
     */
    void InitializeBuffers(ColorData initial_color,
                           int width, int height);

    void connect_two_coordinates(
                                int pre_coordinate_x,
                                int pre_coordinate_y,
                                int cur_coordinate_x,
                                int cur_coordinate_y);

    /**
     * @brief Set of values used to differentiate between what radio buttons is
     * pressed by the user.
     */
    enum UIControlType {
        UI_TOOLTYPE,
        UI_COLOR_R,
        UI_COLOR_G,
        UI_COLOR_B,
        UI_PRESET_RED,
        UI_PRESET_ORANGE,
        UI_PRESET_YELLOW,
        UI_PRESET_GREEN,
        UI_PRESET_BLUE,
        UI_PRESET_PURPLE,
        UI_PRESET_WHITE,
        UI_PRESET_BLACK,
        UI_QUIT
    };

    /** Pointer to pixel data for the screen */
    PixelBuffer *display_buffer_;

    int cur_tool_; /**< Currently selected tool from UI  */
    std::vector<Tools*> brush_tools_;

    //used to record previous coodinates.  
    int pre_coordinate_x;
    int pre_coordinate_y;

    float cur_color_red_;
    float cur_color_green_;
    float cur_color_blue_;

    GLUI_Spinner *spinner_r_; /**< Hook for accessing the UI red amount  */
    GLUI_Spinner *spinner_g_; /**< Hook for accessing the UI green amount  */
    GLUI_Spinner *spinner_b_; /**< Hook for accessing the UI blue amount  */

    /* Copy/move assignment/construction disallowed */
    BrushWorkApp(const BrushWorkApp &rhs) = delete;
    BrushWorkApp& operator=(const BrushWorkApp &rhs) = delete;
};
}  // namespace image_tools

#endif  // INCLUDE_BRUSHWORK_APP_H_
