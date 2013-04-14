//
//  main.cpp
//  diphw1p1c
//
//  Created by chen on 13/3/12.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    fstream file1;
    ofstream ofile("./sampleL.raw");
    char y ;
    file1.open("./sampleD.raw",ios::in);
    double histogram[4][256]={0};
    int raw =0 , column = 0 ;
    // window size 2*2
    for(int i = 0;i<256;i++)
    {
        if(i>127)
        {
            raw = 2;
        }
        for(int j = 0;j<256;j++)
        {
            if(j>127)
            {
                column = raw + 1;
            }
            else{
                column = raw;
            }
            file1.get(y);
            histogram[column][ ((int)y)+128 ]=histogram[column][ ((int)y)+128 ]+ (1.0/16384.0) ;
        }
    }
    file1.close();
    for(int i = 0 ; i< 4 ; i++)
    {
    
        for(int j = 0 ; j < 256 ; j ++)
        {
            
            if(j>0)
            {
                histogram[i][j]=histogram[i][j]+histogram[i][j-1];
            }
//            cout<<i<<"的長條圖  "<<j<<":"<<histogram[i][j]<<endl;
        }
    }
    
    file1.open("./sampleD.raw",ios::in);
    raw = 0 ;
    column = 0 ;
    for(int i = 0;i<256;i++)
    {
        if(i>127)
        {
            raw = 2;
        }
        for(int j = 0;j<256;j++)
        {
            if(j>127)
            {
                column = raw + 1;
            }
            else{
                column = raw;
            }
            file1.get(y);
            ofile << (char)((histogram[column][ ((int)y)+128 ])*256.0-128.0);

        }
    }
    file1.close();
    ofile.close();
    cout<<"圖檔處理成功....."<<endl;

    return 0;
}

