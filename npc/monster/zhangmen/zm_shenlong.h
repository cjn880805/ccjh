//zm_shenlong.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_shenlong);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("神龙教",2,"教主");
};

ZHANGMEN_END;
