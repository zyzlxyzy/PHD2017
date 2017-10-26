#ifndef _CONTROL_
#define _CONTROL_

#include "systemc.h"

SC_MODULE(control)
{
	sc_in<bool> clk;
	sc_in<bool> reset;
	sc_in<sc_bv<7>> opcode;
	sc_in<sc_bv<5>> rd;
	sc_in<sc_bv<3>> funct3_control_i;
	sc_in<sc_bv<5>> rs1;
	sc_in<sc_bv<5>> rs2;
	sc_in<sc_bv<7>> imm7;
	sc_in<sc_bv<12>> pc_i;
//	sc_in<bool> reg_w_following_stage_i;       // input of the signal whether to write data to registor 
	                                           // in the folling cycle for ALU and LOAD instructions
//	sc_in<sc_bv<5>> rd_previous;               // the rd from previous instructions like 
	                                           // ALU or LOAD instructions
    sc_out<sc_bv<12>> pc_o;
	sc_out<sc_bv<12>> imm;                     // a 12 bit imm output, could be from different bits of 
	                                           // the instruction code for different instructions
	sc_out<bool> pc_jump;                      // tell pc to select jump input, 1 to select jump input
	sc_out<bool> alu12_select;                 // to select the input of 12 bit alu
	                                           // 1/JAL/BRANCH: imm + pc;   0/JALR/LOAD/STORE: imm + rs1
	sc_out<bool> reg_w_current_stage;          // whether to write data to registor
	sc_out<bool> reg_w_following_stage_o;      // whether to write data to registor in the folling cycle
	                                           // for ALU and LOAD instructions

	sc_out<bool> ins_branch;                   // flag for branch instruction, passed to next stage for 
	                                           // the if-branch judgement
	sc_out<bool> ins_load;
	sc_out<bool> ins_store;

	sc_out<bool> shift_imm;

	sc_out<sc_bv<4>> aluop;
	sc_out<bool> alu_input;                    // to choose the input of 32 bit alu: imm or rs2
	sc_out<sc_bv<3>> funct3_control_o;         // pass funct3 to next stage for 
	                                           // BRANCH and ALU instructions control

	sc_bv<12> imm1, imm2, imm3, imm4, imm5;

	//imm.write(imm7.read(), rs2.read());
	//imm.range(12,5) = imm7.read();

	void control_main();
	void imm_selector();
	void write_reg();

	SC_CTOR(control)
	{
		SC_METHOD(control_main);
		sensitive << clk.pos() << reset.pos();
		SC_METHOD(imm_selector)
		sensitive << clk.pos() << reset.pos();
		SC_METHOD(write_reg);
		sensitive << opcode;
	}
};

#endif