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
    vector<pair<int,int>> mRaster;
    Raster(); //block creating objects without input dimentions
public:
    Raster(int dimx,int dimy);

    //return 0 on success
    //x coordinate not valid -1
    //y coordinate not valid -2
    //radius is not valid  -3
    int set_circle_param(int x, int y,int r);

    //return 0 on success
    int drawCircle();

    int dispay_Circle();

    int resize_RasterDimensions(int new_DimX, int new_DimY);

    int relocate_Center(int x, int y);
};

#endif
