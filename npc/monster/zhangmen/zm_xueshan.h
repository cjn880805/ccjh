//zm_xueshan.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_xueshan);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("雪山寺", 3, "护教法王");
};

ZHANGMEN_END;
