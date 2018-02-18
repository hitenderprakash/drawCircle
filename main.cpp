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
#include "console.h"
using namespace std;

int main(){

    //test code to get console properties
    console c;
    cout<<"\n"<<c.getConsoleRows();
    cout<<"\n"<<c.getConsoleCols();
    //
    Raster circle(105, 30);
    circle.set_circle_param(18,8,6);
    circle.drawCircle();
    circle.dispay_Circle();

    //test resize dimensions
    //circle.resize_RasterDimensions(20,16);
    //circle.dispay_Circle();

    //test center relocation
    circle.relocate_Center(10,8);
    circle.dispay_Circle();

    return 0;
}
