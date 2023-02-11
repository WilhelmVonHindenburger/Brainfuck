//THIS PROGRAM RELEASED INTO THE PUBLIC DOMAIN UNDER CREATIVE COMMONS ZERO 1.0 UNIVERSAL PUBLIC DOMAIN DEDICATION
//Version 1.0
#include <iostream>
using namespace std;
int main(){
    char bf[]=
    "++++++++[>++++++++<-]>++++++++.---.+++++++..+++.+[----->++>+++++<<]>.>+++++++.--------.+++.------.--------.";
    char instruction;
    int instrptr=0;
    int mem[10000]={0};
    int ptr=0;
    int looplayers=0;
    while(1){
        instruction=bf[instrptr];
        looplayers=0;
        /*cout << "Instruction: " << instruction << endl;
        cout << "Instruction pointer: " << instrptr << endl;
        cout << "Memory pointer: " << ptr << endl;
        cout << "Memory current value: " << mem[ptr] << endl;//*/
        switch(instruction){
            case '+':
                mem[ptr]++;
                instrptr++;
                break;
            case '-':
                mem[ptr]--;
                instrptr++;
                break;
            case '>':
                ptr++;
                instrptr++;
                break;
            case '<':
                ptr--;
                instrptr++;
                break;
            case '.':
                cout << static_cast<char>(mem[ptr]);
                instrptr++;
                break;
            case ',':
                cin >> mem[ptr];
                instrptr++;
                break;
            case '[':
                looplayers=1;
                if(mem[ptr]==0){
                    while(1){
                        instrptr++;
                        if(bf[instrptr] == '[') looplayers++;
                        if(bf[instrptr] == ']') looplayers--;
                        if(bf[instrptr] == ']' && looplayers == 0) break;
                    }
                }
                instrptr++;
                break;
            case ']':
                looplayers=1;
                while(1){
                    instrptr--;
                    if(bf[instrptr] == ']') looplayers++;
                    if(bf[instrptr] == '[') looplayers--;
                    if(bf[instrptr] == '[' && looplayers == 0) break;
                }
                break;
            case '\0':
                return 0;
                break;
            default:
            instrptr++;
        }
        if(!instruction) return 0;
    }
    return 0;
}
