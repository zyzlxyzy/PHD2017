#include "instruction_memory.h"
#include "imem_driver.h"
#include "imem_monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> mclk, mwrite;
	sc_signal<sc_uint<10>> maddr;
	sc_signal<sc_uint<32>> minstruction_i;
	sc_signal<sc_uint<32>> minstruction_o;

	instruction_memory i1 ("instruction1");
	i1.addr(maddr);
	i1.instruction_i(minstruction_i);
	
	i1.clk(mclk);
	i1.write(mwrite);
	i1.instruction_o(minstruction_o);

	imem_driver d1 ("driver1");
	d1.addr(maddr);
	d1.instruction_i(minstruction_i);
	d1.write(mwrite);
	d1.clk(mclk);

	imem_monitor m1 ("monitor1");
	m1.clk(mclk);
	m1.write(mwrite);
	m1.addr(maddr);
//	i1.instruction_i(instruction_i);
	i1.instruction_o(minstruction_o);

	sc_start(1500, SC_NS);

	return 0;
}
