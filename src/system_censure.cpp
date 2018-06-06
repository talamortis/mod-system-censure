#include "ScriptMgr.h"
#include "Chat.h"

class SystemCensure : public PlayerScript
{
public:
    SystemCensure() : PlayerScript("SystemCensure") {}

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg)
    {
        CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
    {
        CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group)
    {
        CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild)
    {
        CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel)
    {
        CheckMessage(player, msg, lang, NULL, NULL, NULL, channel);
    }

    void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
    {
        //if (player->isGameMaster() || lang == LANG_ADDON)
        //return;

        // transform to lowercase (for simpler checking)
        std::string lower = msg;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        const uint8 cheksSize = 67;
        std::string checks[cheksSize];
        checks[1] ="http://";
        checks[0] ="sytes";
        checks[1] ="http://";
        checks[2] ="https://";
        checks[3] ="h t t p : / /";
        checks[4] ="h t t p s : / /";
        checks[5] =".com";
        checks[6] =".net";
        checks[7] =".org";
        checks[8] ="www.";
        checks[9] ="wow-";
        checks[10] ="-wow";
        checks[11] ="no-ip";
        checks[12] =".zapto";
        checks[13] =".biz";
        checks[14] =".servegame";
        checks[15] =".br";
        checks[16] ="com.br";
        checks[17] =". c o m";
        checks[18] =". n e t";
        checks[19] =". o r g";
        checks[20] ="w w w .";
        checks[21] =" w o w -";
        checks[22] ="- w o w";
        checks[23] ="n o - i p";
        checks[24] =". z a p t o";
        checks[25] =". b i z";
        checks[26] =". s e r v e g a m e";
        checks[27] =". b r";
        checks[28] ="c o m . b r";
        checks[29] ="h  t  t  p  :  /  /";
        checks[30] =".  c  o  m";
        checks[31] =".  n  e  t";
        checks[32] =".  o  r  g";
        checks[33] ="w  w  w  .";
        checks[34] =" w  o  w  -";
        checks[35] ="-  w  o  w";
        checks[36] ="n  o  -  i  p";
        checks[37] =".  z  a  p  t  o";
        checks[38] =".  b  i  z";
        checks[39] =".  s  e  r  v  e  g  a  m  e";
        checks[40] =".  b  r";
        checks[41] ="c  o  m  .  b  r";
        checks[42] ="h   t   t   p   :   /   /";
        checks[43] =".   c   o   m";
        checks[44] =".   n   e   t";
        checks[45] =".   o   r   g";
        checks[46] ="w   w   w   .";
        checks[47] =" w   o   w   -";
        checks[48] ="-   w   o   w";
        checks[49] ="n   o   -   i   p";
        checks[50] =".   z   a   p   t   o";
        checks[51] =".   b   i   z";
        checks[52] =".   s   e   r   v   e   g   a   m   e";
        checks[53] =".   b   r";
        checks[54] ="   c   o   m   .   b   r";
        checks[55] ="h    t    t    p   :   /   /";
        checks[56] =".    c    o    m";
        checks[57] =".    n    e   t";
        checks[58] =".    o    r    g";
        checks[59] ="w    w    w    .";
        checks[60] ="w    o    w    -";
        checks[61] ="-    w    o    w";
        checks[62] ="n    o    -    i    p";
        checks[63] =".    z    a    p    t    o";
        checks[64] =".    b    i     z";
        checks[65] =".    s    e    r    v    e    g    a    m    e";
        checks[66] =".    b    r";
        checks[67] ="c    o    m    .    b    r";

        for (int i = 0; i < cheksSize; ++i)
        if (lower.find(checks[i]) != std::string::npos)
        {
            msg = "";
            ChatHandler(player->GetSession()).PSendSysMessage("|cffe84118Links/Advertisements are not allowed!"); 
            return;
        }
    }
};

void AddSC_SystemCensure()
{
    new SystemCensure();
}
