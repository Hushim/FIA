/*******************************************************************************
 * Name            : tool_factory.cc
 * Project         : image_tools
 * Module          : Tool
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Description     : Implementation of ToolFactory
 * Creation Data   : 2/6/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "tool_factory.h"
#include "include/tool.h"
#include "include/t_pen.h"
#include "include/t_stamp.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Tool* ToolFactory::CreateTool(int toolID) {
  Tool* tool = NULL;

  switch (toolID) {
    case TOOL_PEN:
      tool = new TPen();
      break;
    case TOOL_MARKER:
      tool = new TStamp();
      break;
    default:
      tool = NULL;
      break;
  }

  return tool;
}

} /* namespace image_tools */