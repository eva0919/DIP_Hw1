//
//  main.cpp
//  diphw1p1b
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
    char y;
    int num = 0;
    int total = 0;
    int h = 0,l = 0 ;
    fstream fin;
    fstream file;
    ofstream ofile("sampleH.raw");
    fin.open("sampleD.raw",ios::in);
    file.open("sampleD.raw",ios::in);
    int histogram[257]={0};
    double chistogram[257]={0};
    double chistogram2[257]={0};
    do
    {
        fin.get(y);
        histogram[ ((((int)y)+256)%256) ]++;
        num++;
//        if(  ((int)y) > h  )
//        {
//            h = ((int)y);
//        }
//        if(  ((int)y) < l  )
//        {
//            l = ((int)y);
//        }
//        cout<<num<<":"<<((int)y)<<endl;
    }while(!fin.eof());
    for(int i = 0 ; i<=256;i++){
        chistogram[i] =( (double)histogram[i] )/ ((double) 65536);
        if(i>0){
            chistogram[i]=chistogram[i]+chistogram[i-1];
        }
        
    }
    do
    {
        file.get(y);
        ofile << (char)((chistogram[ ((((int)y)+256)%256) ])*256);
        
    }while(!file.eof());
//    for(int i = 0 ; i<=256;i++){
//        total = total + histogram[i];
//        cout<<i<<":"<<chistogram[i]<<endl;
//    }
//    cout<<"num:"<<num<<"    total:"<<total<<endl;
//    cout<<"h:"<<h<<"    l:"<<l<<endl;
    fin.close();
    ofile.close();
    file.close();
    cout<<"圖檔處理成功....."<<endl;

    return 0;
}

