#include "systemc.h"

SC_MODULE(control)
{
	sc_in<sc_bv<7>> opcode;
	sc_out<bool> reg_w;

	void prc_control();

	SC_CTOR(control)
	{
		SC_METHOD(prc_control);
		sensitive << opcode;
	}
};