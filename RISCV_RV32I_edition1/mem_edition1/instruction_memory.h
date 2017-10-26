#include "systemc.h"

SC_MODULE(instruction_memory)
{
	sc_in<sc_uint<10>> addr;
	sc_in<sc_uint<32>> instruction_i;
	
    sc_in<bool> clk, write;
    sc_out<sc_uint<32>> instruction_o;

	void prc_instruction_memory();
	sc_uint<32> ram [1024];

	SC_CTOR(instruction_memory)
	{
		SC_METHOD(prc_instruction_memory);
		//sensitive_pos << clk;
		sensitive_pos(clk);
	}
};