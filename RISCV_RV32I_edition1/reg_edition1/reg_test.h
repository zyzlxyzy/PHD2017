#include "systemc.h"

SC_MODULE(reg_test)
{
	sc_out<bool> t_clk, t_enable, t_w;
	sc_out<sc_bv<5>> t_addr_read1, t_addr_read2;
	sc_out<sc_bv<5>> t_addr_write;
	sc_out<sc_bv<32>> t_rd;
    sc_in<sc_bv<32>> t_rs1, t_rs2;

    void make_clk();
    void generate_signal();
    void monitor();

    SC_CTOR(reg_test)
    {
    	SC_METHOD(monitor);
    	sensitive << t_clk;
    	SC_THREAD(make_clk);
    	SC_THREAD(generate_signal);
    }
};
