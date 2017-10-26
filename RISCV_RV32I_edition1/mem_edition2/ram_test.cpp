#include "ram_test.h"

void ram_test::make_clk()
{
	t_clk = 1;
	while(1)
	{
		wait (5, SC_NS);
		t_clk = !t_clk;
	}
}

void ram_test::show_special()
{
    wait (81, SC_NS);

	cout << "  _______________special time__________  " << sc_time_stamp() << "::";
	cout << "  clk  " << t_clk << "  enable  " << t_enable;
	cout << "  write  " << t_w << "  addr  " << t_addr;
	cout << "  datain  " << t_datain << "  dataout  " << t_dataout << endl;
}


void ram_test::generate_signal()
{
	t_datain.write(0x9f);
	t_addr.write(0x00);
	t_enable = 0;
	t_w = 0;
    wait (20, SC_NS);

    t_datain.write(0x9f);
	t_addr.write(0x00);
	t_enable = 1;
    wait (20, SC_NS);

    t_datain.write(0x9f);
	t_addr.write(0x00);
	t_w = 1;
    wait (20, SC_NS);

    t_datain.write(0x33);
	t_addr.write(0x01);
    wait (20, SC_NS);

    t_datain.write(0x9f);
	t_addr.write(0x00);
	t_w = 0;
    wait (20, SC_NS);

    t_datain.write(0x9f);
	t_addr.write(0x00);
	t_enable = 0;
    wait (20, SC_NS);
}

void ram_test::monitor()
{
	cout << "  at time  " << sc_time_stamp() << "::";
	cout << "  clk  " << t_clk << "  enable  " << t_enable;
	cout << "  write  " << t_w << "  addr  " << t_addr;
	cout << "  datain  " << t_datain << "  dataout  " << t_dataout << endl;

}