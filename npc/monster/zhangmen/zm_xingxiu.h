//zm_xingxiu.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_xingxiu);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("星宿派", 2, "开山祖师");
};

ZHANGMEN_END;
