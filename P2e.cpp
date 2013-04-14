//
//  main.cpp
//  diphw1p2e
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
    fstream finI,finDX;
    char i,n,d1,d2;
    double psnr_dx = 0 ;
    finI.open("./sample2.raw",ios::in);
    finDX.open("./sampleDX.raw",ios::in);

    
    do {
        finI.get(i);
        finDX.get(n);

        
        psnr_dx =(double) ( psnr_dx + (pow((double)((int)i - (int)n) ,2)/(double)(256*256)) );
        
     
        
    } while (!finI.eof());
    

    finDX.close();
    finI.close();

    
    
    cout<<psnr_dx<<endl;
    
    cout<<"圖檔處理完成......\n";
    
    cout<<"PSNR of image DX : " <<10*log10( pow(255.0,2) / psnr_dx  )<<endl;
 
    
    return 0;
}

