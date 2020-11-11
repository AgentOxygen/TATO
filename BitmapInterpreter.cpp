#include "BitmapInterpreter.h"

//https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393

BitmapInterpreter::BitmapInterpreter(std::string bitmap_path) {

	// Read bitmap, if possible, and log colored pixels (anything other than RGB: 255, 255, 255)
	if (fopen_s(&file_pntr, bitmap_path.c_str(), "r") != 0) {
		std::cout << "ERROR -> file at '" << bitmap_path << "' not found." << std::endl;
	}
	else {
		fread(&type, sizeof(type), 1, file_pntr);
		fread(&file_size, sizeof(file_size), 1, file_pntr);
		fread(&reserved1, sizeof(reserved1), 1, file_pntr);
		fread(&reserved2, sizeof(reserved2), 1, file_pntr);
		fread(&offset, sizeof(offset), 1, file_pntr);

		fread(&header_size, sizeof(header_size), 1, file_pntr);
		fread(&img_width, sizeof(img_width), 1, file_pntr);
		fread(&img_height, sizeof(img_height), 1, file_pntr);
		fread(&num_planes, sizeof(num_planes), 1, file_pntr);
		fread(&bits_per_pixel, sizeof(bits_per_pixel), 1, file_pntr);
		fread(&compression_type, sizeof(compression_type), 1, file_pntr);
		fread(&image_size, sizeof(image_size), 1, file_pntr);
		fread(&x_resolution, sizeof(x_resolution), 1, file_pntr);
		fread(&y_resolution, sizeof(y_resolution), 1, file_pntr);
		fread(&num_of_colors, sizeof(num_of_colors), 1, file_pntr);
		fread(&important_colors, sizeof(important_colors), 1, file_pntr);

		// Iterate through each pixel
		for (int pixel_y = 1; pixel_y <= img_height; pixel_y++) {
			for (int pixel_x = 1; pixel_x <= img_width; pixel_x++) {
				// Stores data of the pixel
				pixel info;

				// Iterate through each byte in the pixel
				for (unsigned int i = 0; i < 3; i++) {
					//pixel data;
					unsigned char data;
					fread(&data, sizeof(data), 1, file_pntr);
					std::bitset<CHAR_BIT> bs(data);

					// Records pixel position
					info.x = pixel_x;
					info.y = pixel_y;

					switch (i) {
						// Red component
					case 0:
						info.b = bs.to_ulong();
						break;
						// Green component
					case 1:
						info.g = bs.to_ulong();
						break;
						// Blue component
					case 2:
						info.r = bs.to_ulong();
						break;
					}
				}
				pixel_pool.push_back(info);
			}
		}
		fclose(file_pntr);
	}
}

int BitmapInterpreter::getBMPHeight() {
	return img_height;
}
int BitmapInterpreter::getBMPWidth() {
	return img_width;
}