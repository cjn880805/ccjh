//zm_wudang.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_riyue);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("日月神教", 3, "掌门大弟子");
};

ZHANGMEN_END;
