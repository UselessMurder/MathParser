#include "l_1_b_face.h"
#include "Variables_change.h"
#include "Weight_window.h"


using namespace l_1_b;



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew l_1_b_face());
	return 0;
}

