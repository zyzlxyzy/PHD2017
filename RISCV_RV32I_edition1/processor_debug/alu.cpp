#ifndef _ALU_
#define _ALU_


#include "systemc.h"

SC_MODULE(alu)
{
	sc_in<bool> clk, reset;
	sc_in<sc_bv<12>> pc;
	sc_in<sc_bv<12>> imm;
	sc_in<bool> pc_jump;                       // directly to pc stage
	sc_in<bool> alu12_select;
	sc_in<bool> reg_w_following_stage;
	sc_in<bool> ins_branch;
	sc_in<bool> ins_load;                      // directly to next reg stage
	sc_in<bool> ins_store;                     // directly to dram stage
	sc_in<bool> shift_imm;
	sc_in<sc_bv<4>> aluop;
	sc_in<bool> alu_input;
	sc_in<sc_bv<3>> funct3; 
	sc_in<sc_bv<32>> rs1, rs2;

	sc_out<sc_bv<12>> alu12_backward;           // go back to pc stage
	sc_out<sc_bv<12>> alu12_forward;            // go forward to next stage

    void alu12_b();
    void alu12_f();
    void alu32();

    SC_CTOR(alu)
    {
    	SC_METHOD(alu12_b);
    	sensitive << imm << alu12_select << pc << rs1;
    	SC_METHOD(alu12_f);
    	sensitive << clk.pos();
    	SC_METHOD(alu32);
    	sensitive << aluop << rs1 << rs2 << funct3 << ins_branch;
    }

};


#endif

void alu::alu12_b()
{
	sc_uint<12> rs1_12, imm_uint, pc_uint;
	sc_uint<12> alu12_backward_uint;

	rs1_12 = rs1.read();
	imm_uint = imm.read();
	pc_uint = pc.read();

	if (alu12_select.read() == 1)
	{
		alu12_backward_uint = imm_uint + pc_uint;
		alu12_backward = alu12_backward_uint;
	}
	else 
	{
		alu12_backward_uint = imm_uint + rs1_12;
		alu12_backward = alu12_backward_uint;
	}
}



void alu::alu12_f()
{
	sc_uint<12> rs1_12, imm_uint, pc_uint;
	sc_uint<12> alu12_forward_uint;

	rs1_12 = rs1.read();
	imm_uint = imm.read();
	pc_uint = pc.read();

	if (alu12_select.read() == 1)
	{
		alu12_forward_uint = imm_uint + pc_uint;
		alu12_forward = alu12_forward_uint;
	}
	else 
	{
		alu12_forward_uint = imm_uint + rs1_12;
		alu12_forward = alu12_forward_uint;
	}
}