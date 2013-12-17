#include <dmapplication.h>
#include <dmimageresourcemanager.h>
#include <module\hge\include\hge.h>
#include <module\hge\include\hgesprite.h>

DMResourceManager rscMgr;

class TestScene : public DMBaseScene
{
private:
    hgeSprite* spr;
    DMImageResource* pIR;

public:
    virtual bool Initialize()
    {
        pIR = DMImageResourceManager::Instance().GetImage("../Assets/test.jpg");
        spr = new hgeSprite(pIR->ID(), 0, 0, 3402, 1400);

        return true;
    }

    virtual void Destroy()
    {
        SAFEDEL(spr);
        DMImageResourceManager::Instance().RemoveImage(pIR);
    }

    virtual bool Render(float fDeltaTime)
    {
        spr->RenderStretch(0, 0, 800, 600);

        return false;
    }
};

#ifdef _DEBUG
int main()
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
    DMAPP_INIT();
    DMAPP.GetConfig()->SetFullScreen(false);
    DMAPP.Initialize();

    TestScene* s = new TestScene();
    s->Initialize();

    DMSCENE.AddScene("test", s);
    DMSCENE.SetCurrentScene("test");

    DMAPP.Start();

    DMAPP.Shutdown();
    DMSCENE.ClearScenes();

    return 0;
}
