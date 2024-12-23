//zm_dali.h
//code by Lanwood
//2001-2-26

//掌门NPC
ZHANGMEN_BEGIN(CNzm_dali);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("大理段家",19,"镇南王");
};

ZHANGMEN_END;
