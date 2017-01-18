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
#include "include/state_stack.h"
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
StateStack::StateStack(void) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void StateStack::PushStateData(PixelBuffer* state_data) {
  this->state_stack_.push_back(state_data);
}

void StateStack::PopStateData(void) {
  this->state_stack_.pop_back();
}

int StateStack::get_state_size(void) {
  this->state_stack_.size();
}

PixelBuffer * StateStack::get_state_at(int stat_index) {
  return this -> state_stack_.at(stat_index);
}

void StateStack::pop_first_state() {
  this -> state_stack_.erase(state_stack_.begin());
}

void StateStack::ClearData(void) {
  for (int index = 0; index < state_stack_.size(); index ++) {
    delete state_stack_.at(index);
}

  this -> state_stack_.clear();
}

bool StateStack::IsEmpty(void) {
  return this -> state_stack_.empty();
}

}  /* namespace image_tools */
