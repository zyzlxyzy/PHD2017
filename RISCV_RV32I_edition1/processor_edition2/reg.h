#ifndef _REG_
#define _REG_

#include "systemc.h"

SC_MODULE(reg)
{
	sc_in<bool> clk, w, reset, ins_load;
    sc_in<sc_bv<3>> funct3;
	sc_in<sc_bv<5>> addr_read1, addr_read2;
	sc_in<sc_bv<5>> addr_write_current, addr_write_previous;
	sc_in<sc_bv<32>> rd;
    sc_in<sc_bv<32>> load_rd_i;
    sc_out<sc_bv<32>> rs1, rs2;
    sc_out<sc_bv<32>> reg0, reg1;

    sc_bv<32> regdata [32];
    sc_bv<32> load_rd_o;


    void reg_base();
    void load_extended();
    void view_specific();

    SC_CTOR(reg)
    {
    	SC_METHOD(reg_base);
    	sensitive << clk.pos();
        SC_THREAD(load_extended);
        SC_THREAD(view_specific);
    }
};


#endif