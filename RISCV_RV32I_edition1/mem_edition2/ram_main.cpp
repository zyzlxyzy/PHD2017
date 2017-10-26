#include "systemc.h"
#include "ram.h"
#include "ram_test.h"

int sc_main(int argc, char * argv[])
{
    sc_signal<bool> clk, enable, w;
	sc_signal<sc_int<32>> datain, dataout;
	sc_signal<sc_uint<8>> addr;

    ram r1("ram1");
    r1.clk(clk);
    r1.enable(enable);
    r1.w(w);
    r1.addr(addr);
    r1.datain(datain);
    r1.dataout(dataout);

    ram_test t1("ram_test1");
    t1.t_clk(clk);
    t1.t_enable(enable);
    t1.t_w(w);
    t1.t_datain(datain);
    t1.t_dataout(dataout);
    t1.t_addr(addr);

    sc_start(150, SC_NS);

    return 0;
}