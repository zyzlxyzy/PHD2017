#include "pc.h"

void pc::program_counter()
{
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
	else
	{
		count = count + 1;
		pcout.write(count);
	}
}