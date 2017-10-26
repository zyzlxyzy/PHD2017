#ifndef _RAM_
#define _RAM_

#include "systemc.h"

SC_MODULE(ram)
{
	sc_in<bool> clk, enable, w;
	sc_in<sc_bv<8>> addr;
	sc_in<sc_bv<32>> datain;
	sc_out<sc_bv<32>> dataout;

		sc_bv<32> ramdata [256];

	void prc_ram();
//	void ram_monitor();

	SC_CTOR(ram)
	{
		SC_METHOD(prc_ram);
		sensitive << clk.pos();
//		SC_METHOD(ram_monitor);
//		sensitive << clk;
	}
    
};

#endif