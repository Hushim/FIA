/*******************************************************************************
 * Name            : tool_factory.h
 * Project         : image_tools
 * Module          : Tool
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Description     : Header file for ToolFactoryppp
  * Creation Data   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_TOOL_FACTORY_H_
#define ITERATION2_SRC_INCLUDE_TOOL_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "include/tool.h"
#include "include/t_pen.h"
#include "include/t_eraser.h"
#include "include/t_calligraphy_pen.h"
#include "include/t_highlighter.h"
#include "include/t_spray_can.h"
#include "include/t_chalk.h"
#include "include/t_stamp.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Implementation of factory pattern to handle tool creation
 * This enables easy extension/addition of new tools.
 */
class ToolFactory {
 public:
  /**
   * @brief The list of tools that can be created by the factory and used by the
   * application
   */
  enum TOOLS {
    TOOL_PEN = 0,
    TOOL_ERASER = 1,
    TOOL_SPRAYCAN = 2,
    TOOL_CALLIGRAPHYPEN = 3,
    TOOL_HIGHLIGHTER = 4,
    TOOL_CHALK = 5,
    TOOL_STAMP = 6,
    TOOL_BLUR = 7,
    NUMTOOLS = 8
  };

  /**
   * @brief Return the total # of tools in the application
   */
  static int num_tools(void) { return NUMTOOLS; }

  /**
   * @brief Create a tool from the list of defined tools
   * @return The initialized tool, or nullptr if an invalid index was passed
   */
  static Tool* CreateTool(int tool_id);
};

}  /* namespace image_tools */

#endif  // ITERATION2_SRC_INCLUDE_TOOL_FACTORY_H_
