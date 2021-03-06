/*******************************************************************************
 * Name            : tool_factory.h
 * Project         : image_tools
 * Module          : Tool
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Description     : Header file for ToolFactory
 * Creation Data   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_TOOL_FACTORY_H_
#define SRC_INCLUDE_TOOL_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "include/tool.h"

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
    TOOL_MARKER = 1,
    NUMTOOLS = 2
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

#endif  /* SRC_INCLUDE_TOOL_FACTORY_H_ */
