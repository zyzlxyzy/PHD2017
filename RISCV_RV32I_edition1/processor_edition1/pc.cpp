#include "pc.h"

void pc::program_counter()
{
    sc_int<12> offset;
    offset = branch_offset.read();

	if (reset.read() == 1)
	{
		count = 0;
		pcout.write(count);
	}
	else if (jump.read() == 1)
	{
		count = pcin.read();
		pcout.write(count);
	}
	else if (branch.read() == 1)
	{
		count = count + offset;
		pcout.write(count);
	}
	else
	{
		count = count + 1;
		pcout.write(count);
	}
}