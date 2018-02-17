/*
file: RasterImp.cpp
Implementation of methods of class Raster
Program to draw a circle on text console without floating point operation
Hitender Prakash
Date: Feb 17, 2018
*/
#include <iostream>
#include <vector>
#include "Raster.h"

//constructer
//number of pixels along x-axis are double
//actually it gives better results if we scale it by 1.5 but floats are not allowed
Raster::Raster(int dimx,int dimy):intm_DimX(2*dimx),intm_DimY(dimy){
    //do nothing, implicit initialization
}

//set circle parameters
// i.e center coordinates and radius
//return 0 on success
//return negetive values on error
//x coordinate not valid -1
//y coordinate not valid -2
//radius is not valid  -3
int Raster::set_circle_param(int x, int y, int r){

    if(x<0 || x> intm_DimX){
        return -1;
    }
    if(y<0 || y> intm_DimY){
        return -2;
    }
    if(r<=0){
        return -3;
    }
    orig_X=x;
    orig_Y=y;
    radius=r;

    return 0;
}

int Raster::drawCircle(){
    int x_cord;
    int y_cord;
    for(int i=0;i<=radius;i++){
        x_cord=2*i; // two pixels along x-axis equal 1 -pixel along y-axis
        int j=radius;
        while((j*j+i*i)>=(radius*radius)){
            if((j*j+i*i)==(radius*radius)){
                y_cord=j;
                break;
            }
            else if((j*j+i*i)>(radius*radius)){
                j--;
                continue;
            }
            //apply mid point approximation
            else if((j*j+i*i)<(radius*radius)){
                int deltaUp=(radius*radius)-((i*i)+(j+1)*(j+1));
                int deltaLow=(radius*radius)-((i*i)+(j*j));

                j=(deltaUp<=deltaLow)?j+1:j;
                y_cord=j;
                break;
            }
        }
        //In terms of x_cord and y_cord we have difference of actual coordinates along x-axis and y-axis from the center point
        //we are drawing in first quadrant i.e +ve diff along y-axis in matrix representation means deduct if from center as indeces increases downward
        //write point in first quadrant
        mRaster.push_back(std::make_pair(x_cord,-y_cord));
        //write point in 4th quadrant
        mRaster.push_back(std::make_pair(x_cord,y_cord));
        //write point in 2nd quadrant
        mRaster.push_back(std::make_pair(-x_cord,-y_cord));
        //write point in 3rd quadrant
        mRaster.push_back(std::make_pair(-x_cord,y_cord));

        if(j<=0){break;} //done with all possible x_cord and y_cord
    }
    return 0; //success
}

int Raster::dispay_Circle(){
    if(intm_DimX<=0 || intm_DimY <=0){
        cout<<"\nInvalid Ratser dimensions\n";
        return -1;
    }
    if(orig_X<0||orig_X>=intm_DimX || orig_Y<0 || orig_Y>=intm_DimY){
        cout<<"\nInvalid Center point\n";
        return -2;
    }
    if(radius<=0){
        cout<<"\nInvalid radius\n";
        return -3;
    }
    vector<vector<char>> displayVector(intm_DimY,vector<char>(intm_DimX,' '));
    //mark border
    for(int i=0;i<intm_DimY;i++){
        displayVector[i][0]='.';
        displayVector[i][intm_DimX-1]='.';
    }
    for(int i=0;i<intm_DimX;i++){
        displayVector[0][i]='.';
        displayVector[intm_DimY-1][i]='.';
    }

    for(int i=0;i<mRaster.size();i++){
        int x=orig_X + mRaster[i].first;
        int y=orig_Y + mRaster[i].second;

        if(x<0 || x>=intm_DimX ||y<0||y>=intm_DimY){
            continue;
        }
        displayVector[y][x]='*';
    }
    for(int i=0;i<intm_DimY;i++){
        cout<<"\n";
        for(int j=0;j<intm_DimX;j++){
            cout<<displayVector[i][j];
        }
    }
    cout<<"\n";
    return 0;
}
