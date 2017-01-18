/*******************************************************************************
 * Name            : mia_filter_manager.cc
 * Project         : MIA
 * Module          : filter_manager
 * Description     : Implementation of MIAFilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:47:02 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
//#include "src/app/MIA/src/mia_filter_manager.h"
#include "mia_app_cmd.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <limits>
/* FIXME: ADDITIONAL INCLUDES AS NECESSARY HERE :-) */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {
/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MIACmdApp::MIACmdApp(void) {}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MIACmdApp::cmd_init(char * img_name) {}

int MIACmdApp::is_flag(std::string opt) {
	for (int i = 0; i < 9; i += 1) {
		if (opt.compare(*(flags+i)) == 0)
			return i;
	}
	return 999;
}

std::string MIACmdApp::find_dir(std::string str) {
 // std::cout << "Splitting: " << str << '\n';
 std::size_t found = str.find_last_of("/\\");
 // std::cout << " path: " << str.substr(0,found) << '\n';
 // std::cout << " file: " << str.substr(found+1) << '\n';
 return str.substr(0,found);
}


bool MIACmdApp::float_compare(float a, float b) {
    return fabs(a - b) < std::numeric_limits<float>::epsilon();
}
bool MIACmdApp::pixel_compare(ColorData p1, ColorData p2) {
	return p1.red() == p2.red() &&
				 p1.green() == p2.green() &&
				 p1.blue() == p2.blue() &&
				 p1.alpha() == p2.alpha();
}

int MIACmdApp::check_floor_ceiling(float parameter_,
																	 float floor_,
																	 float ceiling_) {
  if (parameter_ > ceiling_) {
		return ceiling_;
	} else if (parameter_ < floor_) {
		return floor_;
	} else {
		return parameter_;
	}
}

void MIACmdApp::canvas_compare() {
	int len = buffer_vec.size();
	for (int i = 0; i < len; i += 1) {
		PixelBuffer * canvas1 = buffer_vec.back();
		PixelBuffer * canvas2 = compare_vec.back();
		buffer_vec.pop_back();
		compare_vec.pop_back();
		if (canvas1->height() != canvas2->height() ||
				canvas1->width() != canvas2->width()) {
			std::cout << "1 ";
		} else {
			std::string diff = "0 ";
			for (int row = 0; row < canvas1->height() && diff.compare("0 ") == 0; row += 1) {
				for (int col = 0; col < canvas1->width() && diff.compare("0 ") == 0; col += 1) {
					if (!pixel_compare(canvas1->get_pixel(col, row), canvas2->get_pixel(col, row))) {
						diff = "1 ";
					}
				}
			}
			std::cout << diff;
		}
	}
	std::cout << "end of image compare" << std::endl;
	return;
}

bool MIACmdApp::is_number(char * str) {
	int decimal = 0;
	for (int i = 0; i < strlen(str); i += 1) {
		if (i == 0 && str[i] == '-') {
			continue;
		} else if (str[i] == '.') {
			decimal += 1;
		} else if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return decimal <= 1;
}

bool MIACmdApp::if_img_exist(std::string filename) {
	std::ifstream f(filename.c_str());
	return f.good();
}

int MIACmdApp::is_img_valid(std::string filename) {
	if (std::size_t found_png = filename.find(".png") != std::string::npos) {
		return 0;
	} else if (std::size_t found_png = filename.find(".jpg") != std::string::npos) {
		return 1;
	} else {
		return -1;
	}
}

bool MIACmdApp::load_input(std::string filename) {
	if (filename.find("###") == std::string::npos &&
		mia_io_manager_.is_valid_image_file(filename)) {
			PixelBuffer * load_buffer;
			mia_io_manager_.LoadImageToBuffer(filename, &load_buffer);
			buffer_vec.push_back(load_buffer);
			return true;
	} else if (filename.find("###") != std::string::npos &&
			is_img_valid(filename) != -1 &&
			!if_img_exist(filename)) {
			next_file_name_ = filename;
			int pos = next_file_name_.find("###");
			std::string image_type = next_file_name_.substr(pos + 4);
			next_file_name_ = next_file_name_.substr(0, pos);
			next_file_name_.append("000");
			next_file_name_.append(".");
			next_file_name_.append(image_type);

			for(int i =0; i < 1000; i++){
				if(mia_io_manager_.is_valid_image_file(next_file_name_)) {
					PixelBuffer * load_buffer;
					mia_io_manager_.LoadImageToBuffer(next_file_name_, &load_buffer);
					buffer_vec.push_back(load_buffer);
					img_name_vec.push_back(next_file_name_.substr(pos,3));
				}
				next_file_name_ = mia_io_manager_.image_name_plus_seq_offset_for_cmd_mia(next_file_name_, 1);
			}

		// std::cout << "in loading " << buffer_vec.size() << std::endl;
		return buffer_vec.size() > 0;

	} else {
		//load a input file with ### in name
		// std::cout << "load a input file with ### in name\n" << std::endl;
		//PixelBuffer * load_buffer;
		//mia_io_manager_.LoadImageToBuffer(filename, &load_buffer);
		//buffer_vec.push_back(load_buffer);
		return false;
	}
}

bool MIACmdApp::save_output(std::string filename) {
	struct stat sb;
	std::string path = find_dir(filename);
  if (filename.find("###") == std::string::npos &&
			is_img_valid(filename) != -1) {
	 		save_img(filename, is_img_valid(filename));
	} else if (filename.find("###") != std::string::npos &&
			is_img_valid(filename) != -1 &&
			!if_img_exist(filename)){
		next_file_name_ = filename;
		int pos = next_file_name_.find("###");
		std::string image_type = next_file_name_.substr(pos + 4);
		while(img_name_vec.size() > 0) {
			std::string image_num =  img_name_vec.back();
			img_name_vec.pop_back();
			next_file_name_ = next_file_name_.substr(0, pos);
			next_file_name_ = next_file_name_.append(image_num);
			next_file_name_ = next_file_name_.append(".");
			next_file_name_ = next_file_name_.append(image_type);
			save_img(next_file_name_, is_img_valid(next_file_name_));
		}
	} else {
		//The file name has "###"
		// std::cout << "save one image with ###\n" << std::endl;
	 	save_img(filename, is_img_valid(filename));
	}
	return true;
}

bool MIACmdApp::load_compare(std::string filename) {
	if (filename.find("###") == std::string::npos &&
			if_img_exist(filename) &&
		  	is_img_valid(filename) != -1) {
			load_img(filename, is_img_valid(filename), false);
	} else if (filename.find("###") != std::string::npos &&
			!if_img_exist(filename) &&
			is_img_valid(filename) != -1){

		//load a sequence of images
		// std::cout << "load a sequence of images" << std::endl;
		next_file_name_ = filename;
		int pos = next_file_name_.find("###");
		std::string image_type = next_file_name_.substr(pos + 4);

		while( img_name_vec.size() > 0) {
			//load buffer which is used to save compare buffer
			PixelBuffer * load_buffer;
			//extract the ID of the image in a sequnce;
			std::string image_num =  img_name_vec.back();
			//pop out the ID in vector
			img_name_vec.pop_back();
			//concat ID and img exetension with the picture name
			next_file_name_ = next_file_name_.substr(0, pos);
			next_file_name_ = next_file_name_.append(image_num);
			next_file_name_ = next_file_name_.append(".");
			next_file_name_ = next_file_name_.append(image_type);

			mia_io_manager_.LoadImageToBuffer(next_file_name_, &load_buffer);
			compare_vec.insert(compare_vec.begin(), load_buffer);
		}
	} else {
		//The file name has "###"
		PixelBuffer * load_buffer;
	 	mia_io_manager_.LoadImageToBuffer(next_file_name_, &load_buffer);
	 	compare_vec.push_back(load_buffer);
	}
	return buffer_vec.size() == compare_vec.size();  // to compare there should be the same number of image on both sides
}

 void MIACmdApp::apply_filter(int flag, float * param) {
	 Filter * f;
	 switch (flag) {
		 case 0:{
		 	std::cout << "Sharpen "<< param[0] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_SHARPEN,
																								1, param[0]);
			 	break;
		 }
		 case 1: {
		 	std::cout << "Edge "<< std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_EDGE_DETECT,
																								0);
			 break;
		 }
		 case 2:{
		 	std::cout << "Threshold "<< param[0] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_THRESHOLD,
																								1, param[0]);
			 break;
		 }
		 case 3: {
		 	std::cout << "Blur "<< param[0] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_BLUR,
																								1, param[0]);
			 break;
		 }
		 case 4: {
		 	std::cout << "Saturate "<< param[0] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_SATURATION,
																								1, param[0]);
			 break;
		 }
		 case 5: {
		 	std::cout << "Channel "<< param[0] << param[1] << param[2] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_CHANNELS,
																								3, param[0], param[1], param[2]);
			 break;
		 }
		 case 6: {
		 	std::cout << "Quantize "<< param[0] << std::endl;
			 f = FilterFactory::CreateFilter(FilterFactory::FILTER_QUANTIZE,
																								1, static_cast<int>(param[0]));
			 break;
		 }
		 default: {
			 break;
		 }
	 }

	 std::vector<PixelBuffer *>::iterator it = buffer_vec.begin();
	 for (int i = 0; i < buffer_vec.size(); i += 1) {
	   PixelBuffer * buffer = buffer_vec.back();
		 buffer_vec.pop_back();
	   FilterFactory::ApplyFilter(*f, &buffer);
		 buffer_vec.insert(it, buffer);
	 }
	 return;
 }

// IO manager interface: save one img
void MIACmdApp::save_img(std::string filename, int type) {
// load one img
	if (type == 0) {
		IPNGHandler::SaveImage(filename, buffer_vec.back());
	} else {
		IJPEGHandler::SaveImage(filename, buffer_vec.back());
	}
	buffer_vec.pop_back();
	return;
}

// IO manager interface: load one img
void MIACmdApp::load_img(std::string filename, int type, bool input) {
// save one img
	PixelBuffer * temp;
	if (type == 0) {
		temp = IPNGHandler::LoadImage(filename);
	} else {
		temp = IJPEGHandler::LoadImage(filename);
	}
	if (input){
	  buffer_vec.push_back(temp);
	} else {
		compare_vec.push_back(temp);
	}
	return;
}

int MIACmdApp::parse_command_line(int argc, char* argv[]) {
	int cnt = 2;
	std::string input(argv[1]);

  if (input.compare("-h") == 0 && argc == 2) {
		display_command_lines();
		return 0;
	} else if (input.compare("-h") == 0 && argc != 2) {
		std::cout << "command error";
		return 4;
	} if (!load_input(input)) {
		std::cout << "command error" << input << std::endl;
		return 2;
	}
	while (cnt < argc) {
		float * param;
		std::string opt(argv[cnt]);
		int flag = is_flag(opt);
		switch (flag) {
			case 0: case 2: case 3: case 4: case 6:
			//required at least two more paramter;
				if (cnt + 2 < argc && is_number(argv[cnt+1])) {
					param = new float[1];
					param[0] = atof(argv[++cnt]);
					apply_filter(flag, param);
					// std::cout << "case 0 2 3 6 "<< opt <<" found\n";
					break;
				} else {
					std::cout << "command error\n";
					return 4;
				} break;
			case 1:
			//edge detection and gray scale: required at least one more paramter;
				if (cnt + 1 < argc) {
					apply_filter(flag, param);
					// std::cout << "case 1 4 "<< opt <<" found\n";
					break;
				} else {
					std::cout << "command error\n";
					return 4;
				} break;
			case 5:
			//required at least four more paramter;
				if (cnt + 4 < argc &&
				    is_number(argv[cnt+1]) &&
					  is_number(argv[cnt+2]) &&
					  is_number(argv[cnt+3])) {
					param = new float[3];
					param[0] = atof(argv[++cnt]);
				  param[1] = atof(argv[++cnt]);
				  param[2] = atof(argv[++cnt]);
					apply_filter(flag, param);
					// std::cout << "case 5 "<< opt <<" found\n";
				} else {
					std::cout << "command error\n";
					return 4;
				} break;
			case 7:
			// this is compare: next parameter should be the last one.
			  if (cnt + 2 == argc) {
					// std::cout << "case 7 "<< opt <<" found\n";
					std::string output(argv[++cnt]);
					// TODO: compare image
					// 			 check output file. need return ?
					//			 compare. return 0 or 1;
					if (!load_compare(output)) {
						return 3;
					}
					canvas_compare();
					return 0;
				} else {
					std::cout << "command error\n";
					return 4;
				} break;
			case 8:
			// this is help: this should be the las parameter
				if (cnt + 1 <= argc) {
					display_command_lines();
					return 0;
				} else {
					std::cout << "command error\n";
					return 4;
				} break;
			default:
				// std::cout << "reach defalut cases\n";
				if (is_img_valid(opt) != -1) {
					// std::cout << "default saving\n";
					if (save_output(opt)) {
						return 0;
					} else {
						return 3;
					}
				} else {
					std::cout << "command not found: " << std::endl;
					return 1;
				}
			  break;
		}

		if (cnt+1 < argc && is_flag(argv[cnt+1]) != 999) {  											// next argv is a flag
			cnt++;
			continue;
		} else if (cnt+1 < argc && is_img_valid(argv[cnt+1]) != -1) {   				// next argv is output file
			std::string output(argv[++cnt]);
			// TODO: save img. upton successful return 0
			// 								 return code otherwise
			if (save_output(output)) {
				return 0;
			} else {
				return 3;
			}
		} else {   																															// unknown next argv
			std::cout << "command error\n";
			// delete param;
			return 3;
		}
		delete param;
	}
	return 0;
}

void MIACmdApp::display_command_lines() {
	printf("-h\n");
	printf("-sharpen <float>\n");
	printf("-edge\n");
	printf("-threshold <float>\n");
	printf("-quantize <int>\n");
	printf("-blur <float>\n");
	printf("-saturate <float>\n");
	printf("-channel <float> <float> <float>\n");
	printf("-compare\n");
	return;
}

}  /* namespace image_tools */
