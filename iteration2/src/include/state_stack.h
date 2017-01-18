/*******************************************************************************
 * Name            : state_manager.h
 * Project         : FlashPhoto
 * Module          : state_manager
 * Description     : Header for IoHandler class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_STATE_STACK_H_
#define ITERATION2_SRC_INCLUDE_STATE_STACK_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "include/pixel_buffer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The manager for simulation state in FlashPhoto.
 *
 * Simulation state is defined as the sequence of operations that comprises the
 * current canvas. An operation is defined as what happens during 1 click/drag
 * operation, or when 1 button on the control panel that affects the canvas is
 * clicked.
 *
 * A sequence of undos followed by some edits, followed by more undos will
 * FIRST undo the new edits, until you get back to the state before you made the
 * edits. You will not be able to go back any further.
 */
class StateStack {
 public:
  StateStack();
  ~StateStack() {}

  /**
   * @brief Undoes the last operation applied to the canvas (not permanently; it
   * can still be re-done later)
   *
   */
  void PushStateData(PixelBuffer* state_data);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */
  void PopStateData(void);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */
  void ClearData(void);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */

  bool IsEmpty(void);


  int get_state_size(void);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */
  PixelBuffer* get_state_at(int stat_index);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */
  void pop_first_state();

 private:
  /* data members */
  std :: vector<PixelBuffer *> state_stack_;
};

}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_STATE_STACK_H_
