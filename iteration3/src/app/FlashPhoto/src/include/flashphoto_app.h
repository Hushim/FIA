/*******************************************************************************
 * Name            : flashphoto_app.h
 * Project         : FlashPhoto
 * Module          : App
 * Description     : Header file for FlashPhotoApp class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_FLASHPHOTO_APP_H_
#define SRC_INCLUDE_FLASHPHOTO_APP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "include/color_data.h"
#include "include/base_gfx_app.h"
#include "include/pixel_buffer.h"
#include "include/filter_manager.h"
#include "include/io_manager.h"
#include "include/ui_ctrl.h"
#include "include/state_manager.h"
#include "include/tool.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class FlashPhotoApp : public BaseGfxApp {
 public:

  /** 
   * A constructor 
   *
   * A constructor to construct FlashPhotoApp
   */
  FlashPhotoApp(int width, int height);

  /** 
   * A pure virtual deconstructor 
   *
   * A pure virtual deconstructor to deconstruct FlashPhotoApp
   */
  virtual ~FlashPhotoApp(void);

  /**
   * @brief apply conrresponding tools to canvas while dragging mouse 
   *
   * @param x canvas coordinate
   * @param y canvas coordinate
   * 
   */
  void MouseDragged(int x, int y);

  /**
   * @brief do nothing when moving mouse 
   *
   * @param x canvas coordinate
   * @param y canvas coordinate
   * 
   */
  void MouseMoved(int x, int y);

  /**
   * @brief start applying tool actions to canvas 
   *
   * @param x canvas coordinate
   * @param y canvas coordinate
   * 
   */
  void LeftMouseDown(int x, int y);

  /**
   * @brief record thr previoud mouse coordinates
   * when lefing mouse up 
   *
   * @param x canvas coordinate
   * @param y canvas coordinate
   * 
   */
  void LeftMouseUp(int x, int y);

  /**
   * @brief display 
   * 
   */
  void Display(void);

  /**
   * @brief apply corresponding GUI controller 
   * action accoding to the controller id
   *
   * @param control_id ID number of corresponding GUI control
   *
   */
  void GluiControl(int control_id);

  /**
   * @brief Initialize the FlashPhotoApp
   *
   * @param[in] argc Unused--required by BaseGfxApp
   * @param[in] argv Unused--required by BaseGfxApp
   * @param[in] x Unused--required by BaseGfxApp
   * @param[in] y Unused--required by BaseGfxApp
   * @param[in] background_color The initial canvas color
   */
  void Init(
      int argc,
      char *argv[],
      int x,
      int y,
      ColorData background_color);

 private:
  /**
   * @brief Update the colors displayed on the GLUI control panel after updating
   * their values in FlashPhoto
   *
   */
  void update_colors(void);

  void InitGlui(void);
  void InitGraphics(void);

  /**
   * @brief Initialize the buffers for the main window
   */
  void InitializeBuffers(ColorData initial_color,
                         int width, int height);

  /* Copy/move assignment/construction disallowed */
  FlashPhotoApp(const FlashPhotoApp &rhs) = delete;
  FlashPhotoApp& operator=(const FlashPhotoApp &rhs) = delete;

  /**
   * @brief Manager for all filter operations
   */
  FilterManager filter_manager_;

  /**
   * @brief Manager for all I/O operations
   */
  IOManager io_manager_;

  /**
   * @brief Manager for redo/undo stack
   */
  StateManager state_manager_;

  /**
   * @brief A collection of GLUI spinners for RGB control elements.
   */
  struct {
    GLUI_Spinner *spinner_red;
    GLUI_Spinner *spinner_green;
    GLUI_Spinner *spinner_blue;
  } glui_ctrl_hooks_;

  /** Pointer to pixel data for the screen */
  PixelBuffer *display_buffer_;

  // These are used to store the selections from the GLUI user interface
  int cur_tool_;  /**< Currently selected tool from UI */

  // These are used to store the selections from the GLUI user interface
  Tool **tools_;

  // Previous mouse coordinates for interpolating mouse moves
  int mouse_last_x_, mouse_last_y_;
  
  float cur_color_red_;
  float cur_color_green_;
  float cur_color_blue_;
};

}  /* namespace image_tools */

#endif  // SRC_INCLUDE_FLASHPHOTO_APP_H_
