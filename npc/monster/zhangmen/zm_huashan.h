//zm_huashan.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_huashan);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("华山派", 14, "掌门");
};

ZHANGMEN_END;
