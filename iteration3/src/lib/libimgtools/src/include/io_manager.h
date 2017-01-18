/*******************************************************************************
 * Name            : io_manager.h
 * Project         : FlashPhoto
 * Module          : io_manager
 * Description     : Header for IoManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_IO_MANAGER_H_
#define COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_IO_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "GL/glui.h"
#include "include/pixel_buffer.h"
#include "ui_ctrl.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The manager for I/O operations in FlashPhoto. This includes
 * initializing GLUI control elements related to image loading/saving, as well
 * as handling the load/save operations themselves. The load operation includes
 * validating the image type and filesystem permissions before the load will
 * proceed. It also handles loading an image from a file to the stamp.
 */
class IOManager {
 public:

  /** 
   * A constructor 
   *
   * A constructor to construct IOMabager
   */
  IOManager();

   /** 
   * A pure virtual deconstructor 
   *
   * A pure virtual deconstructor to deconstruct IOManager
   */
  virtual ~IOManager() {}

  /**
   * @brief Initialize GLUI control elements for IO management
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   * @return The initialized IO panel handle
   */
  // virtual GLUI_Panel* InitGlui(const GLUI *const glui,
  //                              void (*s_gluicallback)(int));
                               // { return NULL; }
  virtual GLUI_Panel* InitGlui(const GLUI *const glui,
                         void (*s_gluicallback)(int)) {
  new GLUI_Column(const_cast<GLUI*>(glui), true);
  GLUI_Panel *image_panel = new GLUI_Panel(const_cast<GLUI*>(glui),
                                           "Image I/O");
  AddFileBrowserToGLUI(image_panel, s_gluicallback);
  AddSaveCanvasToGLUI(image_panel, s_gluicallback);
  AddLoadStampToGLUI(image_panel, s_gluicallback);
  
  return image_panel;
}

  /**
   * @brief Set the image file. If the file is valid, enable loading/saving
   *
   * @param filepath Pathname of the file
   */
  virtual void set_image_file(const std::string& filepath);

  /**
   * @brief Get the current image file name
   *
   * @return The current image file name
   */
  const std::string& file_name(void) { return file_name_;}

  /**
   * @brief Get a handle on the GLUI file browser
   *
   * @return The handle
   */
  GLUI_FileBrowser* file_browser(void) { return file_browser_; }

  /**
   * @brief Load the selected image file to the canvas
   *
   */
  virtual void LoadImageToCanvas(PixelBuffer **buffer);

  /**
   * @brief Load the selected image file to the stamp
   *
   */
  void LoadImageToStamp(PixelBuffer **buffer);

  /**
   * @brief Save the current state of the canvas to a file
   *
   */
  virtual void SaveCanvasToFile(const PixelBuffer& buffer);


  /**
   * @brief Determine if a file has a valid name for an image file
   *
   * @return TRUE if yes, FALSE otherwise
   */
  bool is_valid_image_file_name(const std::string & name) {
    if (has_suffix(name, ".png") || has_suffix(name, ".jpg")
        || has_suffix(name, ".jpeg")) {
      return true;
    }
    return false;
  }

   /**
   * @brief Determine if the image corresponding to a given file
   *
   * The file must exist, have a proper suffix, and be openable
   * (i.e. the user has permission to open it).
   *
   * @return TRUE if yes, FALSE otherwise
   */
  bool is_valid_image_file(const std::string &name);

 protected:

  /**
   * @brief Initialize SaceCanvas Button
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   */
  void AddSaveCanvasToGLUI(GLUI_Panel* image_panel,
                           void (*s_gluicallback)(int));

  /**
   * @brief Initialize LoadStamp Button
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   */
  void AddLoadStampToGLUI(GLUI_Panel* image_panel,
                          void (*s_gluicallback)(int));

  /**
   * @brief Initialize FileBrowser Button
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   */
  void AddFileBrowserToGLUI(GLUI_Panel* image_panel,
                            void (*s_gluicallback)(int));

  /**
   * @brief enable the save canvas button
   *
   * @param bool
   */
  void save_canvas_toggle(bool enabled) {
    UICtrl::button_toggle(save_canvas_btn_, enabled);
  }

  /**
   * @brief enable the save canvas button
   *
   * @param bool
   */
  void load_stamp_toggle(bool enabled) {
    UICtrl::button_toggle(load_stamp_btn_, enabled);
  }

  /**
   * @brief enable the save canvas button
   *
   * @param bool
   */
  void load_canvas_toggle(bool enabled) {
    UICtrl::button_toggle(load_canvas_btn_, enabled);
  }

  /**
   * @brief enable the load canvas button
   *
   * @param bool
   *
   * @return TRUE if it has suffix
   */
  bool has_suffix(const std::string & str, const std::string & suffix) {
    return str.find(suffix, str.length()-suffix.length()) != std::string::npos;
  }

  GLUI_StaticText* save_file_label(void) { return save_file_label_; }
  GLUI_StaticText* current_file_label(void) { return current_file_label_; }
  GLUI_EditText* file_name_box(void) { return file_name_box_; }

 private:
  /* Copy/move assignment/construction disallowed */
  IOManager(const IOManager &rhs) = delete;
  IOManager& operator=(const IOManager &rhs) = delete;

  /* data members */
  GLUI_FileBrowser *file_browser_;
  GLUI_Button *load_canvas_btn_;
  GLUI_Button *load_stamp_btn_;
  GLUI_Button *save_canvas_btn_;
  GLUI_StaticText *current_file_label_;
  GLUI_EditText *file_name_box_;
  GLUI_StaticText *save_file_label_;
  std::string file_name_;
};

}  /* namespace image_tools */

#endif  /* COMMON_FILES_PUT_THESE_SOMEWHERE_INCLUDE_IO_MANAGER_H_ */
