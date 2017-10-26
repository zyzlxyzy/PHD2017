#include "systemc.h"

SC_MODULE(ram_test)
{
	sc_out<bool> t_clk, t_enable, t_w;
	sc_out<sc_int<32>> t_datain;
	sc_out<sc_uint<8>> t_addr;
	sc_in<sc_int<32>> t_dataout;

	void make_clk();
	void generate_signal();
	void monitor();
	void show_special();

	SC_CTOR(ram_test)
	{
		SC_METHOD(monitor);
		sensitive << t_clk;

		SC_THREAD(make_clk);
		SC_THREAD(generate_signal);
		SC_THREAD(show_special);
	}
};