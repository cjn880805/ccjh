//zm_mingjiao.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_mingjiao);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("明教",35, "教主");
};

ZHANGMEN_END;
