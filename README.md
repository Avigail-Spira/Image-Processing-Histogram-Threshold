# Image-Processing-Histogram-Threshold

Introduction:
I created a program which creates a histogram from an image and filters the image based on the given threshold value to remove any background noise from the image. The histogram is an array where i is the pixel value and array[i] is the count of how many pixels in the given image have that pixel value.

The program takes in a greyscale image (as grid of pixel values with a header) and a threshold value as input. 

There are 4 output files:
1. A list of each pixel value in the image with the count of how many pixels have that value
2. A better visual representation- A list of each pixel value in the image with a + sign for the count of how many pixels have that value
3. The thresholded image: any pixel which is above the threshold will be replaced by a 1 and any pixel below the threshold is replaced by a 0. 
   The result is an image with background pixels deleted and object pixels merged to be one entity.
4. A better visual representation- the image from output 3 with 0s replaced by "."

