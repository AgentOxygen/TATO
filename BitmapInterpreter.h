#ifndef BITMAP_INTERPRETER
#define BITMAP_INTERPRETER

#include <vector>
#include <bitset>
#include <iostream>

class BitmapInterpreter{
private:
	// Header
	unsigned short int type = -1;							/* Identifier */
	unsigned int file_size = -1;							/* File size in bytes */
	unsigned short int reserved1 = -1, reserved2 = -1;
	unsigned int offset = -1;								/* Offset to image data, bytes */
	// Info Header
	unsigned int header_size = -1;							/* Header size in bytes */
	int img_width = -1, img_height = -1;					/* Width and height of image */
	unsigned short int num_planes = -1;						/* Number of color planes */
	unsigned short int bits_per_pixel = -1;					/* Bits per pixel */
	unsigned int compression_type = -1;						/* Compression type */
	unsigned int image_size = -1;							/* Image size in bytes */
	int x_resolution = -1, y_resolution = -1;				/* Pixels per meter */
	unsigned int num_of_colors = -1;						/* Number of colors */
	unsigned int important_colors = -1;						/* Important colors */
	
	// Points to bitmap file
	FILE* file_pntr;

public:
	struct pixel {
		// Color component saturation (0 - 255)
		int r = 255, b = 255, g = 255;
		// Position relative to bottom left corner ? <- check
		int x = -1, y = -1;
	};
	// Vector pool that contains all pixels logged by the interpreter
	std::vector<pixel> pixel_pool;

	/// <summary>
	/// Interprets bitmap. Use dimensions that are multiples of 4, no padding accomidation is implemented at the moment
	/// </summary>
	/// <param name="bitmap_path"> - path to bitmap file</param>
	BitmapInterpreter(std::string bitmap_path);
	/// <returns>Height of image in pixels</returns>
	int getBMPHeight();
	/// <returns>Width of image in pixels</returns>
	int getBMPWidth();
};

#endif

