//zm_wudang.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_wudang);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("武当派", 2, "开山祖师");
};

ZHANGMEN_END;
