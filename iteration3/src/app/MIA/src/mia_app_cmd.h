/*******************************************************************************
 * Name            : mia_app_cmd.h
 * Project         : MIA
 * Module          : cmd
 * Description     : Header for MIACmdApp class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : Zixiang Ma
 *
 ******************************************************************************/

#ifndef SRC_APP_MIA_SRC_MIA_CMD_APP_H_
#define SRC_APP_MIA_SRC_MIA_CMD_APP_H_

#define MAX_FILE_NAME_LENGTH

/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include <string>
 #include <cmath>
 #include <iostream>
 #include "include/base_gfx_app.h"
 #include "include/color_data.h"
 #include "include/pixel_buffer.h"
 #include "include/ui_ctrl.h"
 //#include "include/tool_factory.h"
#include "tool_factory.h"
#include "include/image_handler.h"
#include "include/io_manager.h"
#include "include/t_stamp.h"
#include "mia_filter_manager.h"
#include "mia_io_manager.h"
#include "include/state_manager.h"
#include <vector>
#include "include/i_jpeg_handler.h"
#include "include/i_png_handler.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief image processing application without gui
 */
class MIACmdApp {
  
 public:
  /**
 * @brief construct an MIACmdApp object
 */
  MIACmdApp();


  /**
  * @brief: parse command line and execute based on flags
  * @param arvc is the number of commands
  * @param argv is the command line arguement
  * @return 0 when no error. error code otherwise. 
  */
  int parse_command_line(int argc, char* argv[]);

  private:
  void cmd_init(char * img_name);
  void display_command_lines();
   std::string flags[9] = {"-sharpen", "-edge", "-threshold", "-blur",
                          "-saturate", "-channel", "-quantize", "-compare", "-h"};

  PixelBuffer * display_buffer_;
  std::vector<PixelBuffer*> buffer_vec;
  std::vector<std::string> img_name_vec;
  std::vector<PixelBuffer*> compare_vec;
  bool is_number(char * str);
  int check_floor_ceiling(float parameter_, float floor_, float ceiling_);
  int is_flag(std::string opt);
  bool if_img_exist(std::string filename);
  int is_img_valid(std::string filename);
  void apply_filter(int flag_number, float * param);
  void save_img(std::string filename, int type);
  bool pixel_compare(ColorData p1, ColorData p2);
  void canvas_compare();
  void load_img(std::string filename, int type, bool input);
  bool load_input(std::string filename);
  bool load_compare(std::string filename);
  bool save_output(std::string filename);
  bool float_compare(float a, float b);
  std::string find_dir(std::string filename);
  MIAIOManager mia_io_manager_;
  std::string next_file_name_;
};

}  /* namespace image_tools */

#endif  /* SRC_APP_MIA_SRC_MIA_FILTER_MANAGER_H_ */
