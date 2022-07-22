
#include"goldenApple.h"

void goldenApple::countOneDown()
{
	--coun;
	if (coun == 0 && show)
	{
		show = false;
		coun = rand() % 70 + 500;
	}
	if (coun == 0 && !show)
	{
		show = true;
		coun = 80;
	}
	if (show)
		this->draw();

}