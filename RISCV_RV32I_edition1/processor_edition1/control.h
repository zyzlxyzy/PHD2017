#include "systemc.h"

SC_MODULE(control)
{
	sc_in<sc_bv<7>> opcode;
	sc_in<sc_bv<3>> funct3;                     //bit 14-12
	
	sc_out<bool> reg_w, reg_enable;
	sc_out<bool> dataram_w, dataram_enable;  
	sc_out<sc_bv<3>> aluop;
	sc_out<bool> alumux_select;                  // to select the forth bit of aluop is bit30 or other
	sc_out<bool> if_branch;                      // deal with the branch 
	sc_out<bool> if_imm;


	void prc_control();
	void alu_control();

	SC_CTOR(control)
	{
		SC_METHOD(prc_control);
		sensitive << opcode;
		SC_METHOD(alu_control);
		sensitive << opcode << aluop;
	}
};