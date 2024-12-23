//zm_quanzhen.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_quanzhen);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("全真教", 2, "掌教");
};

ZHANGMEN_END;
