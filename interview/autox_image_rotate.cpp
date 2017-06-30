/*
Given a grayscale image represented by an NxN matrix, write a method to rotate the image by a given degree theta.
You can use nearest neighbor, linear interpolation etc. For more details about algorithms, please refer to
https://www.mathworks.com/help/images/ref/imrotate.html
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

double getAngle(double x, double y){
    // x close to 0
    if (fabs(x)<1e-5) {
        if (y > 0)
            return 3.1415926/2;
        else
            return -3.1415926/2;
    }
    // y close to 0
    if (fabs(y)<1e-5){
        if (x>=0)
            return 0;
        else
            return 3.1415926;
    }
    double angle = atan(y/x);
    // check quadrant
    if (x<0 && y>0)
        angle += 3.1415926;
    if (x<0 && y<0)
        angle -= 3.1415926;
    return angle;
}

// use nearest neighbor to restore point
int getIndex(double x0,int N){
    int x00;
    if (x0<0) x00 = 0;
    else if (x0>N-1) x00 = N-1;
    else x00 = (int) round(x0);
    return x00;
}

vector<vector<double> > rotate(vector<vector<int> > &img, double degree){
    // positive theta for counterclockwise
    // convert to radian unit
    // degree = fmod (degree, 360);
    double rad = degree/180.0 *3.1415926;

    // check matrix shape
    int N;
    if (img.size()>0 && img[0].size()== img.size())
        N = img.size();
    else{
        cout<<"image size not right!" <<endl;
    }
    cout << "image size is a square: "<<N <<"*"<<N<<endl;

    // iterate to match points before and after rotation
    vector<vector<double> > res(N, vector<double>(N, 0));
    double xcenter = (N-1)/2.0, ycenter = -(N-1)/2.0; //image center (2,-2)
    double r, rad_cur,rad_pre;
    double x, y, i0,j0;
    int ii, jj;
    for (int i= 0; i<N; i++){
        for (int j=0; j<N; j++){
            y = -i- ycenter;  // y value should decrease along i
            x =  j- xcenter; // x value should increae along j
            r = sqrt(x*x +y*y);
            rad_cur = getAngle(x,y);
            rad_pre = rad_cur - rad;
            j0 =  r*cos(rad_pre) + xcenter ;
            i0 = -r*sin(rad_pre) - ycenter ;
            if (fabs(i0)<1e-5)
                i0 = 0;
            if (fabs(j0)<1e-5)
                j0 = 0;
            ii = getIndex (i0,N);
            jj = getIndex (j0,N);
            res[i][j] = img[ii][jj];
            /*
            cout<< i<<",  "<<j <<",    xy:"<<x<<",  "<<y<<",      angle:"
                <<setw(10)<<rad_cur/3.1415926
                <<setw(10)<<rad_pre/3.1415926
                <<",       "<<i0<<",  "<<j0<<",        "<<ii<<",  "<<jj<<endl;
                */
        }
    }

    return res;
}

int main(){
    vector<vector<int> > img = {{1, 1, 5, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1}};
    const double theta = 90.0;
    vector<vector<double> > img_rot = rotate(img, theta);
    for (vector<double> v:img_rot){
        for (double f:v)
            cout<<f<<'\t';
        cout<<endl;
    }
}