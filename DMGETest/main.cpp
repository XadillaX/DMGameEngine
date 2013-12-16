#include <dmapplication.h>
#include <dmresourcemanager.h>
#include <module\hge\include\hge.h>
#include <module\hge\include\hgesprite.h>

DMResourceManager rscMgr;

class TestScene : public DMBaseScene
{
private:
    DMResourceBuffer* buff;
    hgeSprite* spr;
    HTEXTURE hTex;
    HGE* hge;

public:
    virtual bool Initialize()
    {
        hge = hgeCreate(HGE_VERSION);
        buff = rscMgr.GetResource("../Assets/test.jpg");

        hTex = hge->Texture_Load((char*)buff->m_pBuff, buff->m_dwBuffSize, true);
        spr = new hgeSprite((HTEXTURE)hTex, 0, 0, 3402, 1400);

        return true;
    }

    virtual void Destroy()
    {
        SAFEDEL(spr);
        hTex = 0;
        hge->Release();
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

    return 0;
}
