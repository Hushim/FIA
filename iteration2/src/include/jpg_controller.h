/*******************************************************************************
 * Name            : filter_manager.h
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Header for FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ITERATION2_SRC_INCLUDE_JPG_CONTROLLER_H_
#define ITERATION2_SRC_INCLUDE_JPG_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "GL/glui.h"
#include <jpeglib.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "include/io_manager.h"
#include "include/pixel_buffer.h"
#include "include/image_controller.h"



/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Manager for all aspects of filters in FlashPhoto, including
 * initialization of GLUI control elements for filters, filter creation,
 * application, deletion.
 */
class JpgController : ImageController{
 public:
    JpgController();
    virtual ~JpgController();

    struct my_error_mgr {
        jpeg_error_mgr pub;
        jmp_buf setjmp_buffer;
    };

    static PixelBuffer* LoadImage(const std::string &name) {
      PixelBuffer * load_buffer = NULL;

      struct jpeg_decompress_struct cinfo;
      struct my_error_mgr jerr;

      FILE * infile;
      JSAMPARRAY buffer;
      int row_stride;


      if ((infile = fopen(name.c_str(), "rb")) == NULL) {
          fprintf(stderr, "can't open %s\n", name.c_str());
          // std::cout << "ERROR: CANNOT READ JPG" << std::endl;
          return 0;
      }

      /* Step 1: allocate and initialize JPEG decompression object */
      /* We set up the normal JPEG error routines, then override error_exit. */
      cinfo.err = jpeg_std_error(&jerr.pub);
      jerr.pub.error_exit = NULL;

      /* Establish the setjmp return context for my_error_exit to use. */

      if (setjmp(jerr.setjmp_buffer)) {
          /* If we get here, the JPEG code has signaled an error.
           * We need to clean up the JPEG object, close the input file, and return.
           */
          jpeg_destroy_decompress(&cinfo);
          fclose(infile);
          return 0;
      }

      /* Now we can initialize the JPEG decompression object. */
      jpeg_create_decompress(&cinfo);

      /* Step 2: specify data source (eg, a file) */



      jpeg_stdio_src(&cinfo, infile);

      /* Step 3: read file parameters with jpeg_read_header() */

      (void) jpeg_read_header(&cinfo, TRUE);

      /* We can ignore the return value from jpeg_read_header since
       *   (a) suspension is not possible with the stdio data source, and
       *   (b) we passed TRUE to reject a tables-only JPEG file as an error.
       * See libjpeg.doc for more info.
       /
      /* Step 4: set parameters for decompression */

      /* In this example, we don't need to change any of the defaults set by
       * jpeg_read_header(), so we do nothing here.
       */
      /* Step 5: Start decompressor */

      (void) jpeg_start_decompress(&cinfo);

      /* We can ignore the return value since suspension is not possible
       * with the stdio data source.
       */


      load_buffer = new PixelBuffer(cinfo.output_width,
                                    cinfo.output_height,
                                    ColorData(0.0, 0.0, 0.0));

      /* We may need to do some setup of our own at this point before reading
       * the data.  After jpeg_start_decompress() we have the correct scaled
       * output image dimensions available, as well as the output colormap
       * if we asked for color quantization.
       * In this example, we need to make an output work buffer of the right size.
       */
      /* JSAMPLEs per row in output buffer */
      row_stride = cinfo.output_width * cinfo.output_components;
      /* Make a one-row-high sample array
      that will go away when done with image */
      buffer = (*cinfo.mem->alloc_sarray)
      ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

      printf("come here\n");
      int y = 0;
      while (cinfo.output_scanline < cinfo.output_height) {
          (void) jpeg_read_scanlines(&cinfo, buffer, 1);

          for (int index = 0; index < cinfo.output_width; index++) {
              float red, green, blue, alpha = 0.f;
              red = *(buffer[0]+(index*3))/255.0f;
              green = *(buffer[0]+(index*3)+1)/255.0f;
              blue = *(buffer[0]+(index*3)+2)/255.0f;
              alpha = 1.0f;
              load_buffer->set_pixel(index,
                                     cinfo.output_height-(y+1),
                                     ColorData(red, green, blue, alpha));
          }
          y+=1;
      }

      /* Step 7: Finish decompression */

      (void) jpeg_finish_decompress(&cinfo);

      jpeg_destroy_decompress(&cinfo);

      fclose(infile);

      return load_buffer;
  }
    static void  SaveImage(const std::string &name,
                           PixelBuffer ** display_buffer) {
      struct jpeg_compress_struct cinfo;

      struct jpeg_error_mgr jerr;


      FILE * outfile;    /* target file */
      JSAMPROW row_pointer[1];  /* pointer to JSAMPLE row[s] */
      int row_stride;    /* physical row width in image buffer */

      /* Step 1: allocate and initialize JPEG compression object */

      /* We have to set up the error handler first, in case the initialization
       * step fails.  (Unlikely, but it could happen if you are out of memory.)
       * This routine fills in the contents of struct jerr, and returns jerr's
       * address which we place into the link field in cinfo.
       */
      cinfo.err = jpeg_std_error(&jerr);
      /* Now we can initialize the JPEG compression object. */
      jpeg_create_compress(&cinfo);

      /* Step 2: spe cify data destination (eg, a file) */
      /* Note: steps 2 and 3 can be done in either order. */

      /* Here we use the library-supplied code to send compressed data to a
       * stdio stream.  You can also write your own code to do something else.
       * VERY IMPORTANT: use "b" option to fopen() if you are on a machine that
       * requires it in order to write binary files.
       */
      if ((outfile = fopen(name.c_str(), "wb")) == NULL) {
          exit(1);
      }
      jpeg_stdio_dest(&cinfo, outfile);

      /* Step 3: set parameters for compression */

      /* First we supply a description of the input image.
       * Four fields of the cinfo struct must be filled in:
       */
      cinfo.image_width = (*display_buffer)->width();

      /* image width and height, in pixels */
      cinfo.image_height = (*display_buffer)->height();
      cinfo.input_components = 3;    /* # of color components per pixel */
      cinfo.in_color_space = JCS_RGB;   /* colorspace of input image */
      /* Now use the library's routine to set default compression parameters.
       * (You must set at least cinfo.in_color_space before calling this,
       * since the defaults depend on the source color space.)
       */
      jpeg_set_defaults(&cinfo);
      /* Now you can set any non-default parameters you wish to.
       * Here we just illustrate the use of quality (quantization table) scaling:
       */
      jpeg_set_quality(&cinfo,
                       100/*quality*/,
                       TRUE /* limit to baseline-JPEG values */);

      /* Step 4: Start compressor */

      /* TRUE ensures that we will write a complete interchange-JPEG file.
       * Pass TRUE unless you are very sure of what you're doing.
       */
      jpeg_start_compress(&cinfo, TRUE);

      /* Step 5: while (scan lines remain to be written) */
      /*           jpeg_write_scanlines(...); */

      /* Here we use the library's state variable cinfo.next_scanline as the
       * loop counter, so that we don't have to keep track ourselves.
       * To keep things simple, we pass one scanline per call; you can pass
       * more if you wish, though.
       */
      row_stride = cinfo.image_width * 3;
      const int width = (*display_buffer)->width();
      const int height = (*display_buffer)->height();
      JSAMPLE* image_buffer = new JSAMPLE[row_stride*cinfo.image_height];

      for (int y = 0; y < height; y++) {
          for (int x = 0; x < width; x++) {
              ColorData currentPixel = (*display_buffer)->get_pixel(x, y);
              image_buffer[((height-(y+1))*width+x)*3] =
                (JSAMPLE) (currentPixel.red()*255.0);
              image_buffer[((height-(y+1))*width+x)*3+1] =
                (JSAMPLE) (currentPixel.green()*255.0);
              image_buffer[((height-(y+1))*width+x)*3+2] =
                (JSAMPLE) (currentPixel.blue()*255.0);
          }
      }


      while (cinfo.next_scanline < cinfo.image_height) {
          /* jpeg_write_scanlines expects an array of pointers to scanlines.
           * Here the array is only one element long, but you could pass
           * more than one scanline at a time if that's more convenient.
           */
          row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
          (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
      }

      delete[] image_buffer;

      /* Step 6: Finish compression */

      jpeg_finish_compress(&cinfo);
      /* After finish_compress, we can close the output file. */
      fclose(outfile);

      /* Step 7: release JPEG compression object */
      /* This is an important step since 
      it will release a good deal of memory. */
      jpeg_destroy_compress(&cinfo);
    }
};
}  /* namespace image_tools */
#endif  // ITERATION2_SRC_INCLUDE_JPG_CONTROLLER_H_
