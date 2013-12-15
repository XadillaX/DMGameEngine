#include <dmapplication.h>

#ifdef _DEBUG
int main()
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
    DMAPP_INIT();

    DMAPP.GetConfig()->SetFullScreen(false);
    DMAPP.Initialize();
    DMAPP.Start();

    DMAPP.Shutdown();

    return 0;
}
