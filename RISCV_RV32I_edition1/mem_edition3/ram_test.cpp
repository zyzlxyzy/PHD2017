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
    
	sc_int<32> datain_int, dataout_int;
	sc_int<8> addr_int;

    wait (81, SC_NS);

    datain_int = t_datain; 
	dataout_int = t_dataout;
	addr_int = t_addr;

	cout << "  _______________special time__________  " << sc_time_stamp() << "::";
	cout << "  clk  " << t_clk << "  enable  " << t_enable;
	cout << "  write  " << t_w << "  addr  " << addr_int;
	cout << "  datain  " << datain_int << "  dataout  " << dataout_int << endl;
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
	sc_int<32> datain_int, dataout_int;
	sc_int<8> addr_int;

	datain_int = t_datain; 
	dataout_int = t_dataout;
	addr_int = t_addr;

	cout << "  at time  " << sc_time_stamp() << "::";
	cout << "  clk  " << t_clk << "  enable  " << t_enable;
	cout << "  write  " << t_w << "  addr  " << addr_int;
	cout << "  datain  " << datain_int << "  dataout  " << dataout_int << endl;

}