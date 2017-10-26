#ifndef _PC_
#define _PC_

#include "systemc.h"

SC_MODULE(pc)
{
	sc_in<bool> clk, reset, jump;
    sc_in<sc_uint<8>> pcin;
	sc_out<sc_uint<8>> pcout;

	sc_uint<8> count;

	void program_counter();

	SC_CTOR(pc)
	{
		SC_METHOD(program_counter);
		sensitive << clk.pos();
	}
};



#endif