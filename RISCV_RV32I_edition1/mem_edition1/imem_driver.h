#include "systemc.h"

SC_MODULE(imem_driver)
{
	sc_out<sc_uint<10>> addr;
	sc_out<sc_uint<32>> instruction_i;
	sc_out<bool> write, clk;

    void clk_imem_driver();
    void prc_imem_driver();

	SC_CTOR(imem_driver)
	{
		SC_THREAD(prc_imem_driver);
		SC_THREAD(clk_imem_driver);
	}
};