#include "systemc.h"

SC_MODULE(imem_monitor)
{
	sc_in<bool> clk, write;
	sc_in<sc_uint<10>> addr;
//	sc_in<sc_uint<32>> instruction_i;
	sc_in<sc_uint<32>> instruction_o;

	void prc_imem_monitor();

	SC_CTOR(imem_monitor)
	{
		SC_METHOD(prc_imem_monitor);
		sensitive << clk << addr << write 
		//<< instruction_i
		<< instruction_o;
	} 
};