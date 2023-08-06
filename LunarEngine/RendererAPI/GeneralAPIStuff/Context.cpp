#include "Context.h"

void GeneralAPIs::Context::createContext(const WindowProperties& properties)
{
	initContext(properties);
	initRendererToContext();
}
