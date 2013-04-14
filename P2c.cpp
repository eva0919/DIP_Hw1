//
//  main.cpp
//  diphw1p2c
//
//  Created by chen on 13/3/19.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>



using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    fstream finI,finN,finD1,finD2;
    char i,n,d1,d2;
    double psnr_n = 0 , psnr_d1 = 0 , psnr_d2 = 0 ;
    finI.open("./sample2.raw",ios::in);
    finN.open("./sampleN.raw",ios::in);
    finD1.open("./sampleD1.raw",ios::in);
    finD2.open("./sampleD2.raw",ios::in);
    
    do {
        finI.get(i);
        finN.get(n);
        finD1.get(d1);
        finD2.get(d2);
        
        psnr_n =(double) ( psnr_n + (pow((double)((int)i - (int)n) ,2)/(double)(256*256)) );
        
        psnr_d1 =(double) ( psnr_d1 + (pow((double)((int)i - (int)d1) ,2)/(double)(256*256)) );
        psnr_d2 =(double) ( psnr_d2 + (pow((double)((int)i - (int)d2) ,2)/(double)(256*256)) );
        
        
    } while (!finI.eof());
    
    finD1.close();
    finD2.close();
    finI.close();
    finN.close();

    cout<<"圖檔處理完成......\n";
    
    cout<<"PSNR of image N : " <<10*log10( pow(255.0,2) / psnr_n  )<<endl;
    cout<<"PSNR of image D1 : " <<10*log10( pow(255.0,2) / ( psnr_d1 ) )<<endl;
    cout<<"PSNR of image D2 : " <<10*log10( pow(255.0,2) / (psnr_d2 ) )<<endl;
    
    return 0;
}

