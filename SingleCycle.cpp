#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int bianryTodecimal(int bianry[],int size)
{
    int decimalNumber = 0;
    for(int i = 0;i < size;i++)
    {
        decimalNumber += bianry[i] * pow(2, size-i-1);
    }
    return decimalNumber;
}

int typeInsruction(int _opcode[6])
{
    int decimalOpcode = bianryTodecimal(_opcode,6);
    if(decimalOpcode == 0)
    {
        return 0; ///for R-type
    }else if(decimalOpcode == 2)
    {
        return 2; ///for J-type
    }
    return 1; ///for I-type
}

string controlPanel(int _opcode[6])
{
    string functionName;
    int function = bianryTodecimal(_opcode,6);

    switch (function) {
        case 32:
            return functionName = "add";
        case 34:
            return functionName = "sub";
        case 37:
            return functionName = "or";
        case 36:
            return functionName = "and";
        case 42:
            return functionName = "slt";
        case 2:
            return functionName = "jump";
        case 43:
            return functionName = "sw";
        case 35:
            return functionName = "lw";
        case 8:
            return functionName = "addi";
        case 10:
            return functionName = "slti";
        case 12:
            return functionName = "andi";
        case 13:
            return functionName = "ori";
        case 4:
            return functionName = "beq";
        case 5:
            return functionName = "bne";

    }
}

void rType(bool _machineCode[32], int *_registterFile)
{
    int _rs,rs[5];
    int _rt,rt[5];
    int _rd,rd[5];
    int _funct,funct[6];

    for(int i = 6,j = 0; 5 < i && i < 11, j < 5;i++, j++)
    {
        rs[j] = _machineCode[i];
    }
    for(int i = 11,j = 0; 10 < i && i < 16, j < 5;i++, j++)
    {
        rt[j] = _machineCode[i];
    }
    for(int i = 16,j = 0; 15 < i && i < 21, j < 5;i++, j++)
    {
        rd[j] = _machineCode[i];
    }
    for(int i = 26,j = 0; 25 < i && i < 32, j < 6;i++, j++)
    {
        funct[j] = _machineCode[i];
    }
    _rs = bianryTodecimal(rs,5);
    _rt = bianryTodecimal(rt,5);
    _rd = bianryTodecimal(rd,5);
    _funct = bianryTodecimal(funct,6);
    switch (_funct) {
        case 32: ///rd = rs + rt
            _registterFile[_rd] = _registterFile[_rs] + _registterFile[_rt];
            cout << endl << _rs << '+' << _rt << '=' << _rd;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            cout << endl << "rd: " << _registterFile[_rd];
            break;
        case 34: ///rd = rs - rt
            _registterFile[_rd] = _registterFile[_rs] - _registterFile[_rt];
            cout << endl << _rs << '-' << _rt << '=' << _rd;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            cout << endl << "rd: " << _registterFile[_rd];
            break;
        case 37: ///rd = rs | rt
            _registterFile[_rd] = _registterFile[_rs] | _registterFile[_rt];
            cout << endl << _rs << '|' << _rt << '=' << _rd;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            cout << endl << "rd: " << _registterFile[_rd];
            break;
        case 36: ///rd = rs & rt
            _registterFile[_rd] = _registterFile[_rs] & _registterFile[_rt];
            cout << endl << _rs << '&' << _rt << '=' << _rd;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            cout << endl << "rd: " << _registterFile[_rd];
            break;
        case 42: ///if rs < rt --> rd = 1
            if(_registterFile[_rs] < _registterFile[_rt])
            {
                _registterFile[_rd] = 1;
            }else{
                _registterFile[_rd] = 0;
            }
            cout << endl << _rs << '<' << _rt << '=' << _rd;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            cout << endl << "rd: " << _registterFile[_rd];
            break;
    }
}
void iType(bool _machineCode[32], int *_registterFile, int *pc)
{
    int _opcode,opcode[6];
    int _rs,rs[5];
    int _rt,rt[5];
    int _immediate,immediate[16];

    for(int i = 0;i < 6;i++)
    {
        opcode[i] = _machineCode[i];
    }
    for(int i = 6,j = 0; 5 < i && i < 11, j < 5;i++, j++)
    {
        rs[j] = _machineCode[i];
    }
    for(int i = 11,j = 0; 10 < i && i < 16, j < 5;i++, j++)
    {
        rt[j] = _machineCode[i];
    }
    for(int i = 16,j = 0; 15 < i && i < 32, j < 16;i++, j++)
    {
        immediate[j] = _machineCode[i];
    }

    _opcode = bianryTodecimal(opcode,6);
    _rs = bianryTodecimal(rs,5);
    _rt = bianryTodecimal(rt,5);
    _immediate = bianryTodecimal(immediate,16);
    switch (_opcode) {
        case 43: ///rs --> rt + immediate
            _registterFile[_rt + _immediate] = _registterFile[_rs];
            cout << endl << _rs << ' ' << _immediate << '(' << _rt << ')';
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt + immediate: " << _registterFile[_rt + _immediate];
            break;
        case 35: ///rs <-- rt + immediate
            _registterFile[_rs] = _registterFile[_rt + _immediate];
            cout << endl << _rs << ' ' << _immediate << '(' << _rt << ')';
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt + immediate: " << _registterFile[_rt + _immediate];
            break;
        case 8: ///rs = rt + immediate
            _registterFile[_rs] = _registterFile[_rt] + _immediate;
            cout << endl << _rt << '+' << _immediate << '=' << _rs;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
        case 10: ///if rt < immediate --> rs = 1
            if(_registterFile[_rt] < _immediate)
            {
                _registterFile[_rs] = 1;
            }else{
                _registterFile[_rs] = 1;
            }
            cout << endl << _rt << '<' << _immediate << '=' << _rs;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
        case 12: ///rs = rt & immediate
            _registterFile[_rs] = _registterFile[_rt] & _immediate;
            cout << endl << _rt << '&' << _immediate << '=' << _rs;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
        case 13: ///rs = rt | immediate
            _registterFile[_rs] = _registterFile[_rt] | _immediate;
            cout << endl << _rt << '|' << _immediate << '=' << _rs;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
        case 4: ///if rs == rt goto immediate
            if(_registterFile[_rt] == _registterFile[_rs])
            {
                *pc = _immediate;
            }
            cout << endl << _rt << " == " << _rs << " go to " << _immediate;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
        case 5: ///if rs != rt goto immediate
            if(_registterFile[_rt] != _registterFile[_rs])
            {
                *pc = _immediate;
            }
            cout << endl << _rt << " != " << _rs << " go to " << _immediate;
            cout << endl << "rs: " << _registterFile[_rs];
            cout << endl << "rt: " << _registterFile[_rt];
            break;
    }
}

void jType(bool _machineCode[32], int *pc)
{
    int _immediate,immediate[26];
    for(int i=0,j=6;j<32;i++,j++)
    {
        immediate[i] = _machineCode[j];
    }
    _immediate = bianryTodecimal(immediate,26);

    *pc = _immediate;
    cout << endl << "programm counter changed to " << *pc << endl;
}
int main()
{
    string type[3][2] = {"R","0",
                         "I","0",
                         "J","0"};
    int typeNumber = 0;
    int registerFile[32];
    int opcode[6];
    int programCounter = 0;
    bool machineCode[32]; ///instruction line 32-Bits

    for(int i=0;i<32;i++)
    {
        registerFile[i] = (i+1); ///enter value in register file for calculate
    }
    cout << endl << "enter machine code:" << endl;
    for(int i = 0; i < 32; i++)
    {
        cout << "[" << i <<"]: " ;
        cin >> machineCode[i];
    }
    cout << "your machine code is ";
    for(int i = 0; i < 32; i++)
    {
        cout << machineCode[i];
    }
    cout << endl;
    for(int i = 0;i < 6;i++)
    {
        opcode[i] = machineCode[i]; ///save opcode
    }
    typeNumber = typeInsruction(opcode);
    switch (typeNumber) {
        case 0: ///R-type
            rType(machineCode, registerFile);
            break;
        case 1: ///I-type
            iType(machineCode, registerFile, &programCounter);
            break;
        case 2: ///J-type
            jType(machineCode, &programCounter);
            break;
    }
    return 0;
}
