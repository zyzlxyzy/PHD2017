#include "pc.h"
#include "pc_test.h"

int sc_main(int argv, char * argc[])
{
	sc_signal<bool> m_clk, m_reset, m_jump;
    sc_signal<sc_uint<8>> m_pcin;
	sc_signal<sc_uint<8>> m_pcout;

	pc p1("pc1");
	p1.clk(m_clk);
	p1.reset(m_reset);
	p1.jump(m_jump);
	p1.pcin(m_pcin);
	p1.pcout(m_pcout);

    pc_test t1("test1");
	t1.t_clk(m_clk);
	t1.t_reset(m_reset);
	t1.t_jump(m_jump);
	t1.t_pcin(m_pcin);
	t1.t_pcout(m_pcout);

    sc_start(150, SC_NS);

    return 0;

}