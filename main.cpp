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
    Raster circle(100, 40);
    circle.set_circle_param(50,20,15);
    circle.drawCircle();
    circle.dispay_Circle();
    return 0;
}
