#include "reg.h"
#include "reg_test.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> m_clk, m_enable, m_w;
	sc_signal<sc_bv<5>> m_addr_read1, m_addr_read2;
	sc_signal<sc_bv<5>> m_addr_write;
	sc_signal<sc_bv<32>> m_rd;
    sc_signal<sc_bv<32>> m_rs1, m_rs2;
 
    reg r1("reg1");
    r1.clk(m_clk);
    r1.enable(m_enable);
    r1.w(m_w);
    r1.addr_write(m_addr_write);
    r1.addr_read1(m_addr_read1);
    r1.addr_read2(m_addr_read2);
    r1.rd(m_rd);
    r1.rs1(m_rs1);
    r1.rs2(m_rs2);

	reg_test t1("reg_test1");
    t1.t_clk(m_clk);
    t1.t_enable(m_enable);
    t1.t_w(m_w);
    t1.t_addr_write(m_addr_write);
    t1.t_addr_read1(m_addr_read1);
    t1.t_addr_read2(m_addr_read2);
    t1.t_rd(m_rd);
    t1.t_rs1(m_rs1);
    t1.t_rs2(m_rs2);

	sc_start(80, SC_NS);

	return 0;

}