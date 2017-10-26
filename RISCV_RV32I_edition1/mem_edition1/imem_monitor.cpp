#include "imem_monitor.h"

void imem_monitor::prc_imem_monitor()
{
	cout << "at time" << sc_time_stamp() << "::";
	cout << "(clk, write, addr, instruction_o):";
	cout << clk << write << addr << instruction_o;
}