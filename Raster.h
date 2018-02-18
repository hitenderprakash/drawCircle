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
    int intm_DimX; //raster length (along x-axies)
    int intm_DimY; //raster width (along y-axis)

    int orig_X; //x coordinate of origin of circle
    int orig_Y; //y coordinate of origin of circle

    int radius; //length of radius of circle

    //pair<int,int> represents a point that lie on circumference
    //with respect to its relative difference of x-cordinate and y coordinate from center respectively
    //we can stroe the absolute coordinate but that would complicate the resize and origin relocation functions
    //In this implimentation we can resize and relocate the center coordinate very easily (provided radius does not change)
    //However the points stored in this vector can fall outside of the raster but display function will handle it.
    vector<pair<int,int>> mRaster;

    //we do  not want user to initialize object without providing dimensions therefor
    //making default constructer private
    Raster();

public:

    /*
        Constructer
        dimx: number of pixels (characters) along x-axis
        dimy: number of pixels (characters) along y-axis
        e.g Raster(50,40) will create a grid of length:50 and width: 40
    */
    Raster(int dimx, int dimy);

    /*
        Sets the parameters of a circle
        origin_x: x coordinate of origin of circle
        origin_y: y coordinate of origin of circle
        radius: radius of circle
        e.g set_circle_param( 40,30,10) will have center at (40,30) and radius =10
    */
    int set_circle_param(int origin_x, int origin_y, int radius);

    /*
        drawCircle will compute all the circle points and fill the mRaster vector
        circle points do not contain absolute x and y coorninate values but it stores the relative difference of x and y coordinate w.r.t center
        e.g (3,4) means the actual circle point is  (center.x + 3, center.y + 4)

        return 0 on success
        -1 in case of error (radius is not valid)
    */
    int drawCircle();


    /*
        dispay_Circle is responsible for rendering the circle on console
        it calculate the absolute coordinates of the circle points
        Not all points can lie within Raster grid, this funstion will ignore such points

        return 0 on success
        -1 , if raster dimensions are invalid (this should never happen, but still handling as every function should not rely on others for error handling)
        -2 , if invalid center coordinates
        -3 , if invalid radius
    */
    int dispay_Circle();

    /*
        Resize the Raster grid
        new_DimX: new length of the raster
        new_DimY: new width of the raster
        ensures that new_DimX and new_DimY are valid
        e.g Raster circle (40,30) //create grid of size 40x30
        circle.resize_RasterDimensions(60,40) //now grid will be 60x40

        return 0 on success
        -1 if input new_DimX is invalid
        -2 if input new_DimY is invalid
    */
    int resize_RasterDimensions(int new_DimX, int new_DimY);

    /*
        shifts the origin of the circle to new position
        relocate_Center(30,20) //will move the circle such that its center is (30,20)

        return 0 on success
        -1 if x-coordinate is invalid
        -2 if y-coordinate is invalid
    */
    int relocate_Center(int x, int y);
};

#endif
