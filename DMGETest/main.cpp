#include <dmapplication.h>

int main()
{
    DMAPP_INIT();

    DMAPP.GetConfig()->SetFullScreen(false);
    DMAPP.Initialize();
    DMAPP.Start();

    DMAPP.Shutdown();

    return 0;
}
