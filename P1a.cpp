//
//  main.cpp
//  diphw1
//
//  Created by chen on 13/3/7.
//  Copyright (c) 2013年 chen. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...

    char y ;
    fstream fin;
    ofstream ofin("./sampleD.raw");
    fin.open("./sample1.raw",ios::in);
    if(!fin){    cout << "讀檔失敗" << endl;   }
    do
    {
        fin.get(y);
        ofin << (unsigned char)((( (int)y+256)%256)/3) ;
        
    }while(!fin.eof());
    cout<<"圖檔處理成功....."<<endl;
    
    fin.close();
    ofin.close();

   // system("PAUSE");
    return 0;
}

