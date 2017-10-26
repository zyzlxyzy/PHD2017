#ifndef _ALU_
#define _ALU_

#include "systemc.h"

SC_MODULE(alu)
{
	sc_in<sc_bv<3>> aluop;    // bit 12-14
	sc_in<bool> ins_bit30;    // bit 30 of the instruction

	sc_in<sc_bv<5>> shift_imm;
	sc_in<sc_bv<32>> operand1, operand2; //operand1 is rs1/rs
	                                     //operand2 is rs2/rt
	sc_out<sc_bv<32>> result;

	void alu_main();
	void show_temp();

	SC_CTOR(alu)
	{
		SC_METHOD(alu_main);
		sensitive << aluop << ins_bit30 << operand1 << operand2 << shift_imm;
		/*SC_METHOD(show_temp);
		sensitive << aluop << ins_bit30;*/
	}
};


#endif