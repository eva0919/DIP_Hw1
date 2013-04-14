//
//  main.cpp
//  diphw1p2b
//
//  Created by chen on 13/3/18.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>

#define IMGL 256

using namespace std;

int mean_filter(int *a , int l);
int median_filter(int *a, int l);



int main(int argc, const char * argv[])
{

    // insert code here...
    char y;
    int global_matrix[IMGL][IMGL];
    int mask[9];  // filter mask 3 * 3
    fstream file1;
    ofstream fout("./sampleD1.raw");
    ofstream fout2("./sampleD2.raw");
    file1.open("./sampleN.raw",ios::in);
    int tempi = 0;
    int tempj = 0;
    
    for(int i = 0 ; i < IMGL ; i++)
    {
        for(int j = 0 ; j < IMGL ; j++){
            file1.get(y);
            global_matrix[i][j]=( ( (int)y ) + 256 )% 256 ;
        }
    }
    for(int i = 0 ; i < IMGL ; i++)
    {
        for(int j = 0 ; j < IMGL ; j++){
            int mask_nu = 0 ;
            for(int i2 = i - 1 ; i2 <= i + 1 ; i2++){
                for(int j2 = j -1 ; j2 <= j+1 ; j2++ ){
                    tempi = i2;
                    tempj = j2;
                  if(tempi<0)
                  {
                    tempi++ ;
                  }
                  else if(tempi >= IMGL)
                  {
                    tempi-- ;
                  }
                  if(tempj<0)
                    {
                        tempj++ ;
                    }
                  else if(tempj >= IMGL)
                    {
                        tempj-- ;
                    }
                    mask[mask_nu] = global_matrix[tempi][tempj];
              
                    mask_nu++;
                }
            
            }
            
            fout << (unsigned char)mean_filter(mask, 9);
            fout2 << (unsigned char)median_filter(mask, 9);
            
            
            
        }
    }
    
    file1.close();
    fout.close();
    
    cout<<"圖檔處理完成......"<<endl;
    
    return 0;
}

int mean_filter(int *a , int l)
{
    int temp = 0 ;
    for(int i = 0 ; i < l ; i ++)
    {
    
        temp = temp + a[i];

    
    }
   
    return (temp / l );

}

int median_filter(int *a, int l)
{
    int temp ;
    for(int i = 0 ; i < l ; i ++)
    {
        for(int j = i+1 ; j < l ; j ++)
        {
          if(a[j] < a[i])
          {
              temp = a[j];
              a[j] = a[i];
              a[i] = temp;
          
          }
        }
    
    }

    return a[5];
}
