#ifndef _REGS_
#define _REGS_

#include "systemc.h"

SC_MODULE(reg)
{
	sc_in<bool> clk, enable, w;
	sc_in<sc_bv<5>> addr_read1, addr_read2;
	sc_in<sc_bv<5>> addr_write;
	sc_in<sc_bv<32>> rd;
    sc_out<sc_bv<32>> rs1, rs2;

    sc_bv<32> regdata [32];

    void reg_base();

    SC_CTOR(reg)
    {
    	SC_METHOD(reg_base);
    	sensitive << clk.pos();
    }
};

#endif