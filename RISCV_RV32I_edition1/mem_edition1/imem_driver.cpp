#include "imem_driver.h"

void imem_driver::prc_imem_driver()
{
	sc_uint<10> i, temp;
    sc_uint<32> write_instruction;

	wait (30, SC_NS);
	addr = 0;
	temp = 0;
	write = 1;
	for (i = 0; i < 50; i++)
	{
		temp++;
		addr = temp;
		write_instruction++;
		instruction_i = write_instruction;
        wait (10, SC_NS);
	}
	write = 0;
	temp = 0;

	wait (30, SC_NS);
	for (i = 0; i < 50; i++)
	{
		temp++;
		addr = temp;
		wait (10, SC_NS);
	}
}


void imem_driver::clk_imem_driver()
{
	clk = 0;

	while(1)
	{
		clk = !clk;
		wait (5, SC_NS);
	}
}