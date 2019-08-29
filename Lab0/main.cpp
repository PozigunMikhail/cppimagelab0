#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
    int imgWidth, imgHeight, channelsNum;

    const char* fileIn = "imgIn.bmp";
    const char* fileOut = "imgOut.bmp";

    unsigned char* imgData = stbi_load(fileIn, &imgWidth, &imgHeight, &channelsNum, 0);

    if (!imgData)
        return 0;

    const int halfSize = imgWidth * imgHeight / 2;

    for (int i = 0; i < halfSize; i++)
    {
        imgData[channelsNum * i] = 255;
        imgData[channelsNum * i + 1] = 0;
        imgData[channelsNum * i + 2] = 0;
    }

    stbi_write_bmp(fileOut, imgWidth, imgHeight, channelsNum, imgData);

    stbi_image_free(imgData);

    return 0;
}
