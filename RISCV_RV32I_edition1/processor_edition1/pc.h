#ifndef _PC_
#define _PC_

#include "systemc.h"

SC_MODULE(pc)
{
	sc_in<bool> clk, reset, jump, branch;
    sc_in<sc_bv<12>> pcin;
    sc_in<sc_bv<12>> branch_offset;
	sc_out<sc_bv<12>> pcout;

	sc_int<12> count;

	void program_counter();

	SC_CTOR(pc)
	{
		SC_METHOD(program_counter);
		sensitive << clk.pos();
	}
};



#endif