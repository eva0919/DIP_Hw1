//
//  main.cpp
//  diphw1p1e
//
//  Created by chen on 13/3/17.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int turnTobi(int data,int s,int b);
int turnTo4(int data,int s,int b);
int turnTo8(int data,int s,int b);
int turnTo16(int data,int s,int b);



int main(int argc, const char * argv[])
{

    // insert code here...
    fstream file1;
    ofstream o_bi("./sampleE_bi_a.raw");
    ofstream o_4("./sampleE_4_a.raw");
    ofstream o_8("./sampleE_8_a.raw");
    ofstream o_16("./sampleE_16_a.raw");
    int smallest = 0 , bigest = 0;
    char y ;
    int temp = 0;
    file1.open("./sampleD.raw",ios::in);
    
    do{
       file1.get(y);
       temp = (((int)y+256)%256);
        if(temp<smallest){smallest=temp;}
        if(temp>bigest){bigest=temp;}
    }while(!file1.eof());
    
    
    file1.close();
    file1.open("./sampleD.raw",ios::in);
    
    do {
        file1.get(y);
        temp = (((int)y+256)%256);
        o_bi << (unsigned char) ( turnTobi( temp , smallest , bigest ) ) ;
        o_4 << (unsigned char) ( turnTo4( temp , smallest , bigest ) ) ;
        o_8 << (unsigned char) ( turnTo8( temp , smallest , bigest ) ) ;
        o_16 << (unsigned char) ( turnTo16( temp , smallest , bigest ) ) ;
    } while (!file1.eof());
    
    file1.close();
    o_bi.close();
    o_4.close();
    o_8.close();
    o_16.close();
    cout<<"圖檔處理完成......"<<endl;
    
    return 0;
}

//********************    bi-level 的轉換 function
int turnTobi(int data,int s,int b)
{
    int result;
    int gap = b - s;
    if(data < (s +(gap/2)) )
    {
        result=0;
    }
    else
    {
        result=255;
    }
    
    
    return result;
} 
//                           bi function end

//********************    4-level 的轉換 function
int turnTo4(int data,int s,int b)
{
    int result;
    int gap = b - s;
    if(data < (s+(gap/4)) )
    {
        result=0;
    }
    else if(data >= (s+(gap/4)) && data < (s+(gap/4)*2))
    {
        result=64;
    }
    else if(data >= (s+(gap/4)*2) && data < (s+(gap/4)*3))
    {
        result=128;
    }
    else
    {
        result=255;
    }
    
    
    return result;
}
//                           4 function end

//********************    8-level 的轉換 function
int turnTo8(int data,int s,int b)
{
    int result;
    int gap = b - s;
    if( data <(s+(gap/8)) )
    {
        result=0;
    }
    else if(data >= (s+(gap/8)) && data < (s+(gap/8)*2))
    {
        result=32;
    }
    else if(data >= (s+(gap/8)*2) && data < (s+(gap/8)*3))
    {
        result=64;
    }
    else if(data >= (s+(gap/8)*3) && data < (s+(gap/8)*4))
    {
        result=96;
    }
    else if(data >= (s+(gap/8)*4) && data < (s+(gap/8)*5))
    {
        result=128;
    }
    else if(data >= (s+(gap/8)*5) && data < (s+(gap/8)*6))
    {
        result=160;
    }
    else if(data >= (s+(gap/8)*6) && data < (s+(gap/8)*7))
    {
        result=192;
    }
    else
    {
        result=255;
    }
    
    return result;
}
//                           8 function end

//********************    16-level 的轉換 function
int turnTo16(int data,int s,int b)
{
    int result;
    int gap = b - s;
    if(data < (s+(gap/16)) )
    {
        result=0;
    }
    else if(data >= (s+(gap/16)) && data < (s+(gap/16)*2))
    {
        result=16;
    }
    else if(data >= (s+(gap/16)*2) && data < (s+(gap/16)*3))
    {
        result=32;
    }
    else if(data >= (s+(gap/16)*3) && data < (s+(gap/16)*4))
    {
        result=48;
    }
    else if(data >= (s+(gap/16)*4) && data < (s+(gap/16)*5))
    {
        result=64;
    }
    else if(data >= (s+(gap/16)*5) && data < (s+(gap/16)*6))
    {
        result=80;
    }
    else if(data >= (s+(gap/16)*6) && data < (s+(gap/16)*7))
    {
        result=96;
    }
    else if(data >= (s+(gap/16)*7) && data < (s+(gap/16)*8))
    {
        result=112;
    }
    else if(data >= (s+(gap/16)*8) && data < (s+(gap/16)*9))
    {
        result=128;
    }
    else if(data >= (s+(gap/16)*9) && data < (s+(gap/16)*10))
    {
        result=144;
    }
    else if(data >= (s+(gap/16)*10) && data < (s+(gap/16)*11))
    {
        result=160;
    }
    else if(data >= (s+(gap/16)*11) && data < (s+(gap/16)*12))
    {
        result=176;
    }
    else if(data >= (s+(gap/16)*12) && data < (s+(gap/16)*13))
    {
        result=192;
    }
    else if(data >= (s+(gap/16)*13) && data < (s+(gap/16)*14) )
    {
        result=208;
    }
    else if(data >= (s+(gap/16)*14) && data < (s+(gap/16)*15))
    {
        result=224;
    }
    else
    {
        result=255;
    }
    
    
    return result;
}
//                           16 function end
