//THIS PROGRAM RELEASED INTO THE PUBLIC DOMAIN UNDER CREATIVE COMMONS ZERO 1.0 UNIVERSAL PUBLIC DOMAIN DEDICATION
//Version 1.1.1
#include <iostream>
using namespace std;
int main(){
    
    //bf is the code of the Brainfuck program.
    char bf[]=
    "++++++++[>++++++++<-]>++++++++.---.+++++++..+++.+[----->++>+++++<<]>.>+++++++.--------.+++.------.--------.";
    char instruction;   // The current instruction
    int instrptr=0;     //The instruction pointer
    int mem[30000]={0}; //Memory space to run it in
    int memptr=0;       //Pointer in memory
    int looplayers=0;   //How many layers of loops are in the loop being checked
    
    while(1){
        instruction=bf[instrptr]; //Read the current instruction
        looplayers=0;
        // DEBUG CODE: INSTRUCTION AND MEMORY
        /*cout << "Instruction: " << instruction << endl;
        cout << "Instruction pointer: " << instrptr << endl;
        cout << "Memory pointer: " << memptr << endl;
        cout << "Memory current value: " << mem[memptr] << endl;//*/
        
        //Error if accessing memory out of bounds (segmentation fault)
        if(memptr < 0 || memptr >= 30000){
            cout << "Invalid memory was accessed.\n";
            cout << "Instruction: "         << instruction << endl;
            cout << "Instruction pointer: " << instrptr    << endl;
            cout << "Memory pointer: "      << memptr      << endl;
            return 0xC0000005;
        }
        switch(instruction){
            case '+': //Increase value in memory
                mem[memptr]++;
                instrptr++;
                break;
            case '-': //Decrease value in memory
                mem[memptr]--;
                instrptr++;
                break;
            case '>': //Move to next spot in memory
                memptr++;
                instrptr++;
                break;
            case '<': //Move to previous spot in memory
                memptr--;
                instrptr++;
                break;
            case '.': //Output a value
                cout << static_cast<char>(mem[memptr]);
                instrptr++;
                break;
            case ',': //Input a value
                cin >> mem[memptr];
                instrptr++;
                break;
            case '[': //Start loop
                looplayers=1;
                if(mem[memptr]==0){ //Skip over loop if current memory value is 0
                    while(1){
                        instrptr++;
                        if(bf[instrptr] == '[') looplayers++; //Nested loop check
                        if(bf[instrptr] == ']') looplayers--; //
                        if(bf[instrptr] == ']' && looplayers == 0) break;
                    }
                }
                instrptr++;
                break;
            case ']': //End loop
                looplayers=1;
                while(1){ //Go back to start of matching loop
                    instrptr--;
                    if(bf[instrptr] == ']') looplayers++; //Nested loop check
                    if(bf[instrptr] == '[') looplayers--; //
                    if(bf[instrptr] == '[' && looplayers == 0) break;
                }
                break;
            case '\0': //End of file
                return 0;
                break;
            default: //If the instruction isn't a Brainfuck instruction it's a comment and gets skipped over
            instrptr++;
        }
    }
    return 0;
}
