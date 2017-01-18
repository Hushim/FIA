/*******************************************************************************
 * Name            : main.cc
 * Project         : MIA
 * Module          : main
 * Description     : Entry point for MIA application
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 1/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
/* FIXME: ADDITIONAL INCLUDES AS NECESSARY HERE :-) */
#include <unistd.h>
#include "include/color_data.h"
#include "mia_app.h"
#include "mia_app_cmd.h"

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char** argv) {
  if (argc == 1) {
    image_tools::MIAApp *app = new image_tools::MIAApp(
        400,
        400,
        "resources/marker.png");
    //printf("~~~~~~`\n");
    app->Init(argc, argv, 50, 50,
              image_tools::ColorData(1, 1, static_cast<float>(0.95)));
    //printf("~~~~~~`\n");
    app->RunMainLoop();
    delete app;
  } else {
    /* Create command line interface */
    image_tools::MIACmdApp *app = new image_tools::MIACmdApp();
    std::string str(argv[1]);
    // std::cout << "test flag detection: " << app->is_flag(str) << std::endl;
    // if (app->is_output_valid(str)){
    //   std::cout << "test ourput name checking: True" << std::endl;
    // } else {
    //   std::cout << "test ourput name checking: False" << std::endl;
    // }


    /* return cmd parse return code:
        0 filter successful / compare same
        1 compare different
        2 invalid input filename
        3 invalid output filename
        4 invalid argv
        5 flag not found
    */
    // char buffer[1024];
    // getcwd(buffer, 1024);
    // std::string test(buffer);
    // std::cout << "current working directory: " << test << std::endl;
    // std::string lalala = "abcd";
    // float lalala = atof(argv[1]);
    // std::cout << "convter to float: " << lalala << std::endl;
    int exit_status = app->parse_command_line(argc, argv);
    // if (app->is)
    // std::cout << "exit code: " << exit_status << std::endl;
    delete app;
    exit(exit_status);
  }
  return 0;
} /* main() */
