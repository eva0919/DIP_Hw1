//
//  main.cpp
//  diphw1p1d
//
//  Created by chen on 13/3/17.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[])
{

    // insert code here...
    ofstream i("./I.txt");
    ofstream d("./D.txt");
    ofstream h("./H.txt");
    ofstream l("./L.txt");
    fstream file_i,file_d,file_h,file_l;
    char y ;
    int histogram[256] ={0};
    file_i.open("./sample1.raw",ios::in);
    file_d.open("./sampleD.raw",ios::in);
    file_h.open("./sampleH.raw",ios::in);
    file_l.open("./sampleL.raw",ios::in);
    do
    {
        file_i.get(y);
        histogram[((((int)y)+256)%256)]++;
                
    }while(!file_i.eof());
    for(int j = 0 ; j<256 ; j++)
    {
        i << histogram[j]<<endl;
        histogram[j]=0;
    }
    do
    {
        file_d.get(y);
        histogram[((((int)y)+256)%256)]++;
               
    }while(!file_d.eof());
    for(int j = 0 ; j<256 ; j++)
    {
        d<< histogram[j]<<endl;
        histogram[j]=0;
    } do
    {
        file_h.get(y);
        histogram[((((int)y)+256)%256)]++;
                
    }while(!file_h.eof());
    for(int j = 0 ; j<256 ; j++)
    {
        h << histogram[j]<<endl;
        histogram[j]=0;
    } do
    {
        file_l.get(y);
        histogram[((((int)y)+256)%256)]++;
    }while(!file_l.eof());
    for(int j = 0 ; j<256 ; j++)
    {
        l << histogram[j]<<endl;
        histogram[j]=0;
    }
    file_d.close();
    file_l.close();
    file_i.close();
    file_h.close();
    cout<<"統計完成......"<<endl;
    return 0;
}

