
#include"goldenApple.h"
//a counter for how long the golden apple should stay on the screen and off the screen
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