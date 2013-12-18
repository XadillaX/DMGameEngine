#include <dmapplication.h>
#include <dmimageresourcemanager.h>
#include <module\hge\include\hge.h>
#include <module\hge\include\hgesprite.h>

DMResourceManager rscMgr;

class TestScene : public DMBaseScene
{
private:
    hgeSprite* spr;
    hgeSprite* sprZazaka;
    hgeSprite* sprZazakaClone;

    DMImageResource* pIR;
    DMImageResource* pZazaka;
    DMImageResource* pZazakaClone;

public:
    virtual bool Initialize()
    {
        pIR = DMIMGMANAGER.GetImage("../Assets/test.jpg");
        spr = new hgeSprite(pIR->ID(), 0, 0, pIR->Width(), pIR->Height());

        pZazaka = DMIMGMANAGER.GetImage("../Assets/zazaka.png");
        sprZazaka = new hgeSprite(pZazaka->ID(), 0, 0, pZazaka->Width(), pZazaka->Height());

        pZazakaClone = DMIMGMANAGER.CloneImage(pZazaka);

        DMPixArray pix = pZazakaClone->GetPixel();
        for(int i = 0; i < 500; i++)
        {
            int temp = rand() % (pZazakaClone->Width() * pZazakaClone->Height());
            pix[temp] = 0xff000000;
        }
        pZazakaClone->UnlockPixel();

        sprZazakaClone = new hgeSprite(pZazakaClone->ID(), 0, 0, pZazakaClone->Width(), pZazakaClone->Height());

        return true;
    }

    virtual void Destroy()
    {
        SAFEDEL(spr);
        SAFEDEL(sprZazaka);
        SAFEDEL(sprZazakaClone);

        DMIMGMANAGER.RemoveImage(pIR);
        DMIMGMANAGER.RemoveImage(pZazaka);
        DMIMGMANAGER.RemoveImage(pZazakaClone);
    }

    virtual bool Render(float fDeltaTime)
    {
        spr->RenderStretch(0, 0, 600.0 / 1080.0 * 1920.0, 600);
        sprZazaka->Render(0, 0);
        sprZazakaClone->Render(100, 100);

        return false;
    }
};

#ifdef _DEBUG
int main()
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
    // Initialize the environment.
    DMAPP_INIT();

    // Configuration
    DMAPP.GetConfig()->SetFullScreen(false);
    DMAPP.GetConfig()->SetShowMouse();

    // Initialize the app
    DMAPP.Initialize();

    // Create a scene and show it.
    TestScene* s = new TestScene();
    s->Initialize();
    DMSCENE.AddScene("test", s);
    DMSCENE.SetCurrentScene("test");

    // Start game.
    DMAPP.Start();

    // Shutdown after gaming.
    DMAPP.Shutdown();

    // You should clear scene before all cleaned.
    DMSCENE.ClearScenes();

    return 0;
}
