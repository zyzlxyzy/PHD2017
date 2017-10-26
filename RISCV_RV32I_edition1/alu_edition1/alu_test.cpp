#include "alu_test.h"
#include <iostream>
#include <string>
using namespace std;

void alu_test::driver()
{
	sc_uint<3> temp_aluop;
	sc_uint<5> temp_shift_imm;
	sc_uint<32> temp_operand1u, temp_operand2u; 
	//sc_uint<32> t_result;
	sc_int<32> temp_operand1, temp_operand2;
	
	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1u = 4;
	t_operand1 = temp_operand1u;
	temp_operand2u = 8;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);                    
	//unsigned add 4 + 8 = 12

	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 4;
	t_operand1 = temp_operand1;
	temp_operand2 = 8;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//signed add 4 + 8 = 12

	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = -4;
	t_operand1 = temp_operand1;
	temp_operand2 = 8;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//signed add -4 + 8 = 4

	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 4;
	t_operand1 = temp_operand1;
	temp_operand2 = -8;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//signed add 4 + (-8) = -4

	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(1);
	temp_operand1u = 4;
	t_operand1 = temp_operand1u;
	temp_operand2u = 8;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//unsigned sub 8 - 4 = 4

	temp_aluop = 0;
	t_aluop = temp_aluop;
	t_ins_bit30.write(1);
	temp_operand1u = 8;
	t_operand1 = temp_operand1u;
	temp_operand2u = 4;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//unsigned sub 4 - 8 = -4

	temp_aluop = 6;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 3;
	t_operand1 = temp_operand1;
	temp_operand2 = 6;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//or 0011 | 0110 = 0111

	temp_aluop = 7;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 3;
	t_operand1 = temp_operand1;
	temp_operand2 = 6;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//and 0011 & 0110 = 0010

	temp_aluop = 4;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 3;
	t_operand1 = temp_operand1;
	temp_operand2 = 6;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//xor 0011 ^ 0110 = 0101

	temp_aluop = 2;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1 = 3;
	t_operand1 = temp_operand1;
	temp_operand2 = 3;
	t_operand2 = temp_operand2;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//slt set less than

	temp_aluop = 3;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1u = 3;
	t_operand1 = temp_operand1u;
	temp_operand2u = 3;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 0;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//sltu set less than unsigned

	temp_aluop = 1;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1u = 3333;
	t_operand1 = temp_operand1u;
	temp_operand2u = 3;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 63;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//sll

	temp_aluop = 5;
	t_aluop = temp_aluop;
	t_ins_bit30.write(0);
	temp_operand1u = 1024;
	t_operand1 = temp_operand1u;
	temp_operand2u = 3;
	t_operand2 = temp_operand2u;
	temp_shift_imm = 6;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//srl

	temp_aluop = 5;
	t_aluop = temp_aluop;
	t_ins_bit30.write(1);
	temp_operand1 = -1024;
	t_operand1 = temp_operand1;
	temp_operand2 = 3;
	t_operand2 = temp_operand2;
	temp_shift_imm = 6;
	t_shift_imm = temp_shift_imm;
	wait (10, SC_NS);
	//slt set less than

}


void alu_test::monitor()
{
	while (1)
	{
		sc_uint<3> temp_aluop;
	    sc_uint<5> temp_shift_imm;
	    sc_uint<32> temp_operand1u, temp_operand2u; 
	    sc_int<32> temp_operand1, temp_operand2;
	    sc_uint<32> temp_resultu;
	    sc_int<32> temp_result;
	    sc_bv<4> op_4bit;
	    sc_uint<4> opcode = op_4bit;

	    //char opname[4];
	    //opname = "add";

	    op_4bit = (t_aluop, t_ins_bit30);

	    temp_aluop = t_aluop;
	    temp_resultu = t_result;
	    temp_operand1 = t_operand1;
	    temp_operand2 = t_operand2;
	    temp_operand1u = t_operand1;
	    temp_operand2u = t_operand2;
	    temp_shift_imm = t_shift_imm;
	    temp_result = t_result;

	    /*switch(opcode)
	    {
	    	case 0 : opname = "add";   break;
	    	case 1 : opname = "__sub";   break;
	    	case 2 : opname = "__sll";   break;
	    	case 4 : opname = "__slt";   break;
	    	case 6 : opname = "_sltu";   break;
	    	case 8 : opname = "__xor";   break;
	    	case 10: opname = "__srl";   break;
	    	case 11: opname = "__sra";   break;
	    	case 12: opname = "___or";   break;
	    	case 14: opname = "__and";   break;
	    	default: opname = "wrong";   break;
	    }*/

		cout << sc_time_stamp() << "::  " << "rs1  " << temp_operand1 << "  " << temp_operand1u;
		cout << "  rs2  " << temp_operand2 << "  " << temp_operand2u << "  opcode  " ; 
		cout << "  " << t_aluop << t_ins_bit30 << "  shift  " << temp_shift_imm << endl;
		cout << "  result  " << temp_resultu << endl; 
		cout << t_result << "  " << temp_result << endl;
		wait(10, SC_NS);
	}
}










//	sc_out<bool> t_ins_bit30;
//	sc_out<sc_bv<3>> t_aluop;
//	sc_out<sc_bv<5>> t_shift_imm;
//	sc_out<sc_bv<32>> t_operand1, t_operand2; 
//	sc_in<sc_bv<32>> t_result;