/*******************************************************************************
 * Name            : brushwork_app.cc
 * Project         : BrushWork
 * Module          : App
 * Description     : Implementation of BrushWrok
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/brushwork_app.h"
#include <cmath>
#include <iostream>
#include "include/color_data.h"
#include "include/pixel_buffer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
BrushWorkApp::BrushWorkApp(int width,
                           int height)
    : BaseGfxApp(width,
                 height),
      display_buffer_(nullptr),
      cur_tool_(0.0),
      cur_color_red_(0.0),
      cur_color_green_(0.0),
      cur_color_blue_(0.0),
      spinner_r_(nullptr),
      spinner_g_(nullptr),
      spinner_b_(nullptr) {}

BrushWorkApp::~BrushWorkApp(void) {
    int tool_size = brush_tools_.size();
    for (int tool_index = 0 ; tool_index < tool_size; tool_index++) {
        delete brush_tools_[tool_index];
    }

    if (display_buffer_) {
        delete display_buffer_;
    }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void BrushWorkApp::Init(
    int argc,
    char* argv[],
    int x,
    int y,
    ColorData background_color) {

    BaseGfxApp::Init(argc, argv,
                     x, y,
                     GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH,
                     true,
                     width()+51,
                     50);

    // Set the name of the window
    set_caption("BrushWork");

    // Initialize Interface
    InitializeBuffers(background_color, width(), height());

    InitGlui();
    InitGraphics();

    // initialize previous coordinates
    pre_coordinate_x = - 10000;
    pre_coordinate_y = - 10000;

    // Initialize tools
    InitializeTools();
}

void BrushWorkApp::InitializeTools() {
    brush_tools_.push_back(new Pen());
    brush_tools_.push_back(new Eraser());
    brush_tools_.push_back(new SprayCan());
    brush_tools_.push_back(new CaligraphyPen());
    brush_tools_.push_back(new Highlighter());
    brush_tools_.push_back(new Special());

    // Apply Singleton pattern: only pen has been modified for singleton
    // Pen * temp = Pen::get_instance();
    // brush_tools_.push_back(temp);
    // printf("test for pen instance radius: %d \n", temp->radius);
    // brush_tools_.push_back((*Eraser::get_instance()));
    // brush_tools_.push_back((*SprayCan::get_instance()));
    // brush_tools_.push_back((*CaligraphyPen::get_instance()));
    // brush_tools_.push_back((*Highlighter:: get_instance()));
    // toDo: add other tools;
}

void BrushWorkApp::Display(void) {
    DrawPixels(0, 0, width(), height(), display_buffer_->data());
}

void BrushWorkApp::MouseDragged(int x, int y) {
    // only apply colore while dragging on canvas
    if (pre_coordinate_x != -10000 && pre_coordinate_y != -10000) {
        (*brush_tools_[cur_tool_]).apply_color_to_mask(
                                    x,
                                    y,
                                    ColorData(cur_color_red_, cur_color_green_, cur_color_blue_),
                                    &display_buffer_);
        connect_two_coordinates(pre_coordinate_x, pre_coordinate_y, x, y);

        // update previous coordinate each time after connecting a line
        pre_coordinate_x = x;
        pre_coordinate_y = y;
    }
}
void BrushWorkApp::MouseMoved(int x, int y) {
}

void BrushWorkApp::LeftMouseDown(int x, int y) {
    std::cout << "mousePressed " << x << " " << y << std::endl;

    // apply a dot color onto the canvas
    (*brush_tools_[cur_tool_]).apply_color_to_mask(
                                            x,
                                            y,
                                            ColorData(cur_color_red_, cur_color_green_, cur_color_blue_),
                                            &display_buffer_);
    pre_coordinate_x = x;
    pre_coordinate_y = y;
}

void BrushWorkApp::LeftMouseUp(int x, int y) {
    std::cout << "mouseReleased " << x << " " << y << std::endl;
    pre_coordinate_x = -10000;
    pre_coordinate_y = -10000;
}
void BrushWorkApp::connect_two_coordinates(
                                int pre_coordinate_x,
                                int pre_coordinate_y,
                                int cur_coordinate_x,
                                int cur_coordinate_y) {
    // connect two dots by rescusively
    // apply color at the cneter of two dots until filling the gap
    if (
        abs(cur_coordinate_x - pre_coordinate_x) <= 1
        && abs(cur_coordinate_y - pre_coordinate_y) <= 1) {
        return;
    }
    // get center coordinates
    int center_x = (pre_coordinate_x + cur_coordinate_x)/2;
    int center_y = (pre_coordinate_y + cur_coordinate_y)/2;
    // when the previous curdinate is out of canvas, stop applying color;
    if (
        pre_coordinate_x < 0
        || pre_coordinate_x > this->width()
        || pre_coordinate_y < 0
        || pre_coordinate_y > this -> height()) {
        return;
    } else {
        (*brush_tools_[cur_tool_]).apply_color_to_mask(
                                center_x,
                                center_y,
                                ColorData(cur_color_red_, cur_color_green_, cur_color_blue_),
                                &display_buffer_);
    }

    connect_two_coordinates(
        pre_coordinate_x,
        pre_coordinate_y,
        center_x,
        center_y);
    
    connect_two_coordinates(
        center_x,
        center_y,
        cur_coordinate_x,
        cur_coordinate_y);
}

void BrushWorkApp::InitializeBuffers(
    ColorData background_color,
    int width,
    int height) {
    display_buffer_ = new PixelBuffer(width, height, background_color);
}

void BrushWorkApp::InitGlui(void) {
    // Select first tool (this activates the first radio button in glui)
    cur_tool_ = 0;

    GLUI_Panel *tool_panel = new GLUI_Panel(glui(), "Tool Type");
    GLUI_RadioGroup *radio = new GLUI_RadioGroup(tool_panel,
                                                 &cur_tool_,
                                                 UI_TOOLTYPE,
                                                 s_gluicallback);

    // Create interface buttons for different tools:
    new GLUI_RadioButton(radio, "Pen");
    new GLUI_RadioButton(radio, "Eraser");
    new GLUI_RadioButton(radio, "Spray Can");
    new GLUI_RadioButton(radio, "Caligraphy Pen");
    new GLUI_RadioButton(radio, "Highlighter");
    new GLUI_RadioButton(radio, "Special");

    GLUI_Panel *color_panel = new GLUI_Panel(glui(), "Tool Color");

    cur_color_red_ = 0;
    spinner_r_  = new GLUI_Spinner(color_panel, "Red:", &cur_color_red_,
                                   UI_COLOR_R, s_gluicallback);
    spinner_r_->set_float_limits(0, 1.0);

    cur_color_green_ = 0;
    spinner_g_ = new GLUI_Spinner(color_panel, "Green:", &cur_color_green_,
                                   UI_COLOR_G, s_gluicallback);
    spinner_g_->set_float_limits(0, 1.0);

    cur_color_blue_ = 0;
    spinner_b_  = new GLUI_Spinner(color_panel, "Blue:", &cur_color_blue_,
                                   UI_COLOR_B, s_gluicallback);
    spinner_b_->set_float_limits(0, 1.0);
    new GLUI_Button(color_panel, "Red", UI_PRESET_RED, s_gluicallback);
    new GLUI_Button(color_panel, "Orange", UI_PRESET_ORANGE, s_gluicallback);
    new GLUI_Button(color_panel, "Yellow", UI_PRESET_YELLOW, s_gluicallback);
    new GLUI_Button(color_panel, "Green", UI_PRESET_GREEN, s_gluicallback);
    new GLUI_Button(color_panel, "Blue", UI_PRESET_BLUE, s_gluicallback);
    new GLUI_Button(color_panel, "Purple", UI_PRESET_PURPLE, s_gluicallback);
    new GLUI_Button(color_panel, "White", UI_PRESET_WHITE, s_gluicallback);
    new GLUI_Button(color_panel, "Black", UI_PRESET_BLACK, s_gluicallback);


    new GLUI_Button(glui(), "Quit", UI_QUIT, static_cast<GLUI_Update_CB>(exit));
}


void BrushWorkApp::InitGraphics(void) {
    // Initialize OpenGL for 2D graphics as used in the BrushWork app
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, width(), 0, height());
    glViewport(0, 0, width(), height());
}

void BrushWorkApp::GluiControl(int control_id) {
    switch (control_id) {
    case UI_PRESET_RED:
        cur_color_red_ = 1;
        cur_color_green_ = 0;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_ORANGE:
        cur_color_red_ = 1;
        cur_color_green_ = 0.5;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_YELLOW:
        cur_color_red_ = 1;
        cur_color_green_ = 1;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_GREEN:
        cur_color_red_ = 0;
        cur_color_green_ = 1;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_BLUE:
        cur_color_red_ = 0;
        cur_color_green_ = 0;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_PURPLE:
        cur_color_red_ = 0.5;
        cur_color_green_ = 0;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_WHITE:
        cur_color_red_ = 1;
        cur_color_green_ = 1;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_BLACK:
        cur_color_red_ = 0;
        cur_color_green_ = 0;
        cur_color_blue_ = 0;
        break;
    default:
        break;
    }

    spinner_b_->set_float_val(cur_color_blue_);
    spinner_g_->set_float_val(cur_color_green_);
    spinner_r_->set_float_val(cur_color_red_);
}
}  // namespace image_tools
