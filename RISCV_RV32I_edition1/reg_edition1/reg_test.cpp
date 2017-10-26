#include "reg_test.h"

void reg_test::make_clk()
{
	t_clk = 1;
	while(1)
	{
		wait (5, SC_NS);
		t_clk = !t_clk;
	}
}

void reg_test::generate_signal()
{
    t_enable.write(0);
    t_w.write(0);
    t_addr_read1.write(0);
    t_addr_read2.write(5);
    t_addr_write.write(0);
    t_rd.write(55);
    wait (20, SC_NS);
    t_enable.write(1);
    wait (10, SC_NS);
    t_w.write(1);
    wait (20, SC_NS);
    t_rd.write(1023);
    t_addr_write.write(5);
    wait (10, SC_NS);
    t_w.write(0);

}

void reg_test::monitor()
{
	cout << "  at time  " << sc_time_stamp() << "::";
	cout << "  clk  " << t_clk << "  enable  " << t_enable;
	cout << "  write  " << t_w << "  addrw  " << t_addr_write;
	cout << "  addr1  " << t_addr_read1 << "  addr2  " << t_addr_read2 << endl;

	cout << "  rs1  " << t_rs1 << "  rs2  " << t_rs2 << "  rd  " << t_rd << endl;

}