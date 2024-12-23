//zm_shaolin.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_shaolin);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("少林派", 35, "弟子");
};

ZHANGMEN_END;
