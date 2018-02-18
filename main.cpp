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

    //Driver code

    //welcome message ! comment this section and uncomment any of the test case and run command: "make run"


    cout<<"\nWelcome!";
    cout<<"\nPlease edit 'main.cpp' file, uncomment the code for the desired test case";
    cout<<"\nRun 'make' to build the project";
    cout<<"\nExecute the program as './drawCircle'";
    cout<<"\n\n";



    //TEST CASE: 1
    //test that we can dynamically get the console window size  and on the basis of that we can create raster that covers the entire screen
    //and draw the circle with its center at the middle of the raster and radius=min(length_of_console,width_of_console)
    //before running the program you can set your console at any size. Program will always make the circle to fit the screen
    //If code fail for some reason,  it will give a raster of default size (50,50)
    //uncomment below to run this test case

    /*
    console c;
    int cols=c.getConsoleCols()/2; //2 pixels along x-axis
    int rows=c.getConsoleRows();

    Raster circle(cols, rows);
    circle.set_circle_param(cols/2,rows/2,min(cols,rows)/2-1);
    circle.drawCircle();
    circle.dispay_Circle();
    */


    //TEST CASE: 2
    //Creating a raster with user provided dimensions
    //uncomment below to run this test case

    /*
    Raster circle(30,20);
    circle.set_circle_param(22,10,6); //center(22,10) and radius=5 you should see a circle towards the right side
    circle.drawCircle();
    circle.dispay_Circle();
    */

    //TEST CASE: 3
    //Draw a circle when only partial part of circle falls inside raster
    //uncomment below to run this test case

    /*
    Raster circle(30,20);
    circle.set_circle_param(28,10,6); //center(28,10) and radius=6 you should see a partial circle towards the right side
    circle.drawCircle();
    circle.dispay_Circle();
    */

    //TEST CASE: 4
    //Demo of Raster resize, we first draw a circle which falls partially inside Raster
    //then resize the Raster to increse its size and display the circle again such that it now falls within raster
    //uncomment below to run this test case

    /*
    Raster circle(30,20);
    circle.set_circle_param(28,10,6); //center(28,10) and radius=6 you should see a partial circle towards the right side
    circle.drawCircle();
    circle.dispay_Circle();
    circle.resize_RasterDimensions(40,20); //increase the raster dimensions
    circle.dispay_Circle();
    */

    //TEST CASE: 5
    //Demo of relocating origin of circle, we first draw a circle which falls partially inside Raster
    //then relocate the origin and then display the circle again such that it now falls within raster
    //uncomment below to run this test case


    /*
    Raster circle(30,20);
    circle.set_circle_param(28,10,6); //center(28,10) and radius=6 you should see a partial circle towards the right side
    circle.drawCircle();
    circle.dispay_Circle();
    circle.relocate_Center(22,10); //move the origin of the circle towards left so circle shifts inside the raster
    circle.dispay_Circle();
    */

    //TEST CASE: 6
    //Demo of error handling, if invalid circle params are given
    //should print relevant error message
    //uncomment below to run this test case

    /*
    Raster circle(50,40);
    int ret = circle.set_circle_param(-45,20,10); //center(-45,20) and radius=10 , notice wrong dimensions for DimX, try giving invalid values for other inputs
    if(ret!=0){
        if(ret==-1){
            cout<<"\nInvalid input for x dimension";
        }
        else if(ret==-2){
            cout<<"\nInvalid input for y dimension";
        }
        else{
            cout<<"\nInvalid input for radius";
        }
        cout<<"\n";
        return 0;
    }
    circle.drawCircle();
    circle.dispay_Circle();
    */

    //TEST CASE: 7
    //Try displaying circle without creating it i.e call  dispay_Circle() without calling drawCircle(). It should print only broder

    /*
    Raster circle(30,20);
    circle.set_circle_param(28,10,6); //center(28,10) and radius=6
    //circle.drawCircle();
    circle.dispay_Circle(); //should see only border, no circle
    */

    //TEST CASE: 8
    //Try displaying circle without setting origin and radius i.e call  drawCircle() and dispay_Circle() without calling set_circle_param().

    /*
    Raster circle(30,20);
    //circle.set_circle_param(28,10,6); //center(28,10) and radius=6
    circle.drawCircle();
    circle.dispay_Circle(); //should see an error message
    */


    return 0;
}
