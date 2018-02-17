/*
file: main.cpp
Driver code for Raster class functionality
Program to draw a circle on text console without floating point operation
Hitender Prakash
Date: Feb 17, 2018
*/
#include <iostream>
#include <vector>
#include "Raster.h"
using namespace std;

int main(){
    Raster circle(50, 40);
    circle.set_circle_param(45,20,10);
    circle.drawCircle();
    circle.dispay_Circle();

    //test resize dimensions
    //circle.resize_RasterDimensions(60,40);
    //circle.dispay_Circle();

    //test center relocation
    circle.relocate_Center(20,20);
    circle.dispay_Circle();

    return 0;
}
