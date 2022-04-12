#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <bitset>

using namespace std;

int main(){

char c;
float clk, Time;
clk = 0;
Time = 0.001;
bitset<16> Data16;
bitset<8> Data8, Binary;
bitset<7> A;
bitset<7> B;
bitset<1> Carry(string("0"));

ifstream Data;
ofstream NewData;
ofstream IntData;
Data.open("C://Users//silma//Desktop//RawData.txt");
NewData.open("C://Users//silma//Desktop//ClockedData.txt");
IntData.open("C://Users//silma//Desktop//IntData3.txt");
while (!Data.eof()) {
clk = clk + 0.1;

while (!Data.eof()){
if (Time >= clk){
    break;
}
    Data >> Time;

    for (int i =0; i<7; i++){
        A[i] = Data16[(2*i)+1];
        B[i] = Data16[(2*i)+2];
    }
    for (int i =0; i<7; i++){
        if (Carry[0] == 1){
            Data8[i] = 1;
            Carry[0] = A[i] + B[i];
            continue;
        }

        if (A[i] == 1 & B[i] == 1) {
            Data8[i] = 0;
            Carry[0] = 1;
            continue;
        }
        Data8[i] = A[i] + B[i];
        Carry[0] = 0;
    }
    Data8[7] = Data16[15] + Carry[0];
    Binary = Data8;
    Data >> Data16;
}
    NewData << clk*1000 << "\t" << Binary << endl;
    IntData << Binary.to_ulong() << endl;
}

IntData.close();
Data.close();
NewData.close();



cout << "DONE!" << endl;
return 0;
}
