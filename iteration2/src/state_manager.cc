/*******************************************************************************
 * Name            : state_manager.cc
 * Project         : FlashPhoto
 * Module          : state_manager
 * Description     : Implementation of StateManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Sun Oct 2 20:47:05 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/state_manager.h"
#include <iostream>
#include "include/ui_ctrl.h"
// #include "include/flashphoto_app.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
StateManager::StateManager(void) :
    undo_btn_(nullptr),
    redo_btn_(nullptr) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void StateManager::InitGlui(const GLUI *const glui,
                            void (*s_gluicallback)(int)) {
  undo_btn_ = new GLUI_Button(const_cast<GLUI*>(glui), "Undo", UICtrl::UI_UNDO,
                              s_gluicallback);
  undo_toggle(false);

  redo_btn_  = new GLUI_Button(const_cast<GLUI*>(glui), "Redo", UICtrl::UI_REDO,
                               s_gluicallback);
  redo_toggle(false);
}

void StateManager::UndoOperation(
                            PixelBuffer **display_buffer,
                            StateStack *undo_buffers_stack,
                            StateStack *redo_buffers_stack) {
  std::cout << "Undoing..." << std::endl;

  redo_buffers_stack -> PushStateData(*display_buffer);

  *display_buffer = undo_buffers_stack ->
    get_state_at(undo_buffers_stack -> get_state_size() -1);

  // modify window size
  // FlashPhotoApp::SetWindowDimensions(
  //                           (*display_buffer) -> height(),
  //                           (*display_buffer) -> width());

  undo_buffers_stack -> PopStateData();

  if (!redo_buffers_stack -> IsEmpty()) {
    redo_toggle(true);
  } else {
    redo_toggle(false);
  }

  if (!undo_buffers_stack -> IsEmpty()) {
    undo_toggle(true);
  } else {
    undo_toggle(false);
  }
}

void StateManager::RedoOperation(
                            PixelBuffer **display_buffer,
                            StateStack *undo_buffers_stack,
                            StateStack *redo_buffers_stack) {
  std::cout << "Redoing..." << std::endl;
  undo_buffers_stack -> PushStateData(*display_buffer);
  *display_buffer = redo_buffers_stack ->
    get_state_at(redo_buffers_stack -> get_state_size() -1);

  // modify window sizes
  // FlashPhotoApp::SetWindowDimensions(
  //                           (*display_buffer) -> height(),
  //                           (*display_buffer) -> width());

  redo_buffers_stack -> PopStateData();

  if (!redo_buffers_stack -> IsEmpty()) {
    redo_toggle(true);
  } else {
    redo_toggle(false);
  }

  if (!undo_buffers_stack -> IsEmpty()) {
    undo_toggle(true);
  } else {
    undo_toggle(false);
  }
}

void StateManager::SaveState(
                            PixelBuffer **display_buffer,
                            StateStack *undo_buffers_stack,
                            StateStack *redo_buffers_stack) {
  PixelBuffer *copy_of_current_state = new PixelBuffer(
                                    (*display_buffer) -> width(),
                                    (*display_buffer) -> height(),
                                    (*display_buffer) -> background_color());

  PixelBuffer::BackUpPixelBuffer(copy_of_current_state, *display_buffer);

  if (undo_buffers_stack -> get_state_size() >= MAX_UNDO) {
    undo_buffers_stack -> pop_first_state();
  }

  undo_buffers_stack -> PushStateData(copy_of_current_state);

  while (!redo_buffers_stack -> IsEmpty()) {
    redo_buffers_stack -> ClearData();
  }

  if (!redo_buffers_stack -> IsEmpty()) {
    redo_toggle(true);
  } else {
    redo_toggle(false);
  }

  if (!undo_buffers_stack -> IsEmpty()) {
    undo_toggle(true);
  } else {
    undo_toggle(false);
  }
}
}  /* namespace image_tools */

