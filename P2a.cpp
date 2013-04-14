//
//  main.cpp
//  diphw1p2a
//
//  Created by chen on 13/3/18.
//  Copyright (c) 2013年 chen. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
#define IMGL 256


int main(int argc, const char * argv[])
{

    // insert code here...
    fstream fin;
    ofstream fout("./sampleN.raw");
    srand(time(NULL));
    char y;
    double temp = 0 ;
    double gussain = 0.0 ;
    int matrix[IMGL][IMGL];
    int row = 0 , column = 0 ;
    fin.open("./sample2.raw",ios::in);
    do {
        fin.get(y);
        temp = (double)(((int)y+256)%256);
        for(int i = 0 ; i<12 ; i++)
        {
            gussain = gussain + ( (double)rand()/(double)RAND_MAX );
        }
        gussain = 5 * ( gussain - 6 );
        if(temp + gussain > 255)
        {
            temp = 255;
        }
        else if(temp+gussain < 0)
        {
            temp = 0;
        }
        else{
            temp = temp + gussain;
        
        }
        matrix[row][column] = (int)((unsigned char)(temp)) ;
        column ++ ;
        if(column >= IMGL)
        {
            row ++;
            column = 0 ;
        }
        if(row > IMGL)
        {
            cout<<"Something Error......"<<endl;
        }
        gussain = 0 ;
        
    } while (!fin.eof());
    for(int i = 0 ; i< 1500 ; i ++)
    {
        row = rand()%256;
        column = rand()%256;
        matrix[row][column] = 255 ;
    
    }
    for(int i = 0 ; i< 1500 ; i ++)
    {
        row = rand()%256;
        column = rand()%256;
        matrix[row][column] = 0 ;
        
    }
    for(int i = 0 ; i < IMGL ; i ++)
    {
        for(int j = 0 ; j < IMGL ; j++)
        {
            fout << (unsigned char)matrix[i][j];
        }
    
    }
    fin.close();
    fout.close();
    
    cout<<"圖像處理成功......"<<endl;

    return 0;
}

