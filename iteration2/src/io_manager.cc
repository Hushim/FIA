/*******************************************************************************
 * Name            : io_manager.cc
 * Project         : FlashPhoto
 * Module          : io_manager
 * Description     : Implementation of IOManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:47:05 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/io_manager.h"
#include <iostream>
#include "include/pixel_buffer.h"
#include "include/png_controller.h"
#include "include/jpg_controller.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
IOManager::IOManager(void) :
    file_browser_(nullptr),
    load_canvas_btn_(nullptr),
    load_stamp_btn_(nullptr),
    save_canvas_btn_(nullptr),
    current_file_label_(nullptr),
    file_name_box_(nullptr),
    save_file_label_(nullptr),
    file_name_() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void IOManager::InitGlui(const GLUI *const glui,
                         void (*s_gluicallback)(int)) {
  new GLUI_Column(const_cast<GLUI*>(glui), true);
  GLUI_Panel *image_panel = new GLUI_Panel(const_cast<GLUI*>(glui),
                                           "Image I/O");
  file_browser_ = new GLUI_FileBrowser(image_panel,
                                      "Choose Image",
                                      false,
                                      UICtrl::UI_FILE_BROWSER,
                                      s_gluicallback);

  file_browser_->set_h(400);

  file_name_box_ = new GLUI_EditText(image_panel ,
                                    "Image:",
                                    file_name_,
                                    UICtrl::UI_FILE_NAME,
                                    s_gluicallback);
  file_name_box_->set_w(200);

  new GLUI_Separator(image_panel);

  current_file_label_ = new GLUI_StaticText(image_panel,
                                           "Will load image: none");
  load_canvas_btn_ = new GLUI_Button(image_panel,
                                    "Load Canvas",
                                    UICtrl::UI_LOAD_CANVAS_BUTTON,
                                    s_gluicallback);
  load_stamp_btn_ = new GLUI_Button(image_panel,
                                   "Load Stamp",
                                   UICtrl::UI_LOAD_STAMP_BUTTON,
                                   s_gluicallback);

  new GLUI_Separator(image_panel);

  save_file_label_ = new GLUI_StaticText(image_panel,
                                        "Will save image: none");

  save_canvas_btn_ = new GLUI_Button(image_panel,
                                    "Save Canvas",
                                    UICtrl::UI_SAVE_CANVAS_BUTTON,
                                    s_gluicallback);

  load_canvas_toggle(false);
  load_stamp_toggle(false);
  save_canvas_toggle(false);
}


bool IOManager::is_valid_image_file(const std::string & name) {
  FILE *f;
  bool is_valid = false;
  if (is_valid_image_file_name(name)) {
    if ((f = fopen(name.c_str(), "r"))) {
      is_valid = true;
      fclose(f);
    }
  }
  return is_valid;
}

void IOManager::set_image_file(const std::string & file_name) {
  // If a directory was selected
  // instead of a file, use the
  // latest file typed or selected.
  std::string image_file = file_name;
  if (!is_valid_image_file_name(image_file)) {
    image_file = file_name_;
  }

  // TOGGLE SAVE FEATURE
  // If no file is selected or typed,
  // don't allow file to be saved. If
  // there is a file name, then allow
  // file to be saved to that name.

  if (!is_valid_image_file_name(image_file)) {
    save_file_label_->set_text("Will save image: none");
    save_canvas_toggle(false);
  } else {
    save_file_label_->set_text((std::string("Will save image: ") +
                                image_file).c_str());
    save_canvas_toggle(true);
  }

  // TOGGLE LOAD FEATURE

  // If the file specified cannot be opened,
  // then disable stamp and canvas loading.
  if (is_valid_image_file(image_file)) {
    load_stamp_toggle(true);
    load_canvas_toggle(true);

    current_file_label_->set_text((std::string("Will load: ") +
                                   image_file).c_str());
    file_name_box_->set_text(image_file);
  } else {
    load_stamp_toggle(false);
    load_canvas_toggle(false);
    current_file_label_->set_text("Will load: none");
  }
}

// IOManager::IMAGE_TYPE IOManager::check_image_type(const std::string &name) {
//     if (name.substr(name.length()-4, 4).compare(".png") == 0) {
//         return PNG;
//     }
//     else if (name.substr(name.length()-5, 5).compare(".jpeg") == 0 ) {
//         return JPG;
//     }
//     else {
//         return -1;
//     }
// }

PixelBuffer * IOManager::LoadImageToCanvas(
                              const std::string &name,
                              PixelBuffer ** display_buffer) {
  std::cout << "Load Canvas has been clicked for file " << std::endl;
  int image_type = IOManager::check_image_type(name);
    PixelBuffer * image_buffer;
    if (image_type == 0) {
        image_buffer = PngController::LoadImage(name);
    } else if (image_type == 1) {
        image_buffer = JpgController::LoadImage(name);
    }  else {
      printf("Not jpeg or png\n");
    }

    *display_buffer = image_buffer;
}

void IOManager::SaveCanvasToFile(
                              const std::string &name,
                              PixelBuffer ** display_buffer) {
  std::cout << "Save Canvas has been clicked for file " << file_name_
  << std::endl;
  int image_type = IOManager::check_image_type(name);
    if (image_type == 0) {
        PngController::SaveImage(name, display_buffer);
    } else if (image_type == 1) {
        JpgController::SaveImage(name, display_buffer);
    }  else {
      printf("Not jpeg or png\n");
    }
}

PixelBuffer * IOManager::LoadImageToStamp(const std::string &name) {
  std::cout << "Load Stamp been clicked for file " <<
      file_name_ << std::endl;
  int stamp_type = IOManager::check_image_type(name);
  PixelBuffer * stamp_buffer;
  if (stamp_type == 0) {
    stamp_buffer = PngController::LoadImage(name);
  } else if (stamp_type == 1) {
    stamp_buffer = JpgController::LoadImage(name);
  } else {
    printf("Not jpeg or png\n");
  }
  return stamp_buffer;
}

}  /* namespace image_tools */
