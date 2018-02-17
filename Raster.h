/*
Class: Raster
Program to draw a circle on text console without floating point operation
Hitender Prakash
Date: Feb 16, 2018
*/

#ifndef _RASTER_H
#define _RASTER_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Raster{
private:
    int intm_DimX;
    int intm_DimY;

    int orig_X;
    int orig_Y;

    int radius;

    //this vector contains the relative difference of circle coordinates x,y from center coordinate
    //we can stroe the absolute coordinate but that would complicate the resize and origin relocation functions
    //In this implimentation we can resize and relocate the center coordinate very easily (provided radius does not change)
    //However the points stored in this vector can fall outside of the raster but display function will handle that

    //pair<int,int> correspondsd difference of x-cordinate from center, difference of y coordinate from center respectively
    vector<pair<int,int>> mRaster;

    //we do  not want user to initialize object without providing dimensions therefor
    //making default constructer private
    Raster();

public:
    Raster(int dimx,int dimy);

    //return 0 on success
    //x coordinate not valid -1
    //y coordinate not valid -2
    //radius is not valid  -3
    int set_circle_param(int x, int y,int r);

    //This function does not actually render the circle on screen but just calculate all the circle points
    //and store that in the mRaster vector
    int drawCircle();

    //This function renders the circle on the console provided mRaster vector has already been filled with circle points
    //By getting the difference of x,y coordinates with respect to the origin, it will find the pixel position on the screen
    //Points falling outside of the raster are ignored
    int dispay_Circle();

    //Will resize the raster dimensions if input parameters are valid
    int resize_RasterDimensions(int new_DimX, int new_DimY);

    //will change the center coordinates of the circle
    int relocate_Center(int x, int y);
};

#endif
