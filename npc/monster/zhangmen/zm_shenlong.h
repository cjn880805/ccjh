//zm_shenlong.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_shenlong);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("������",2,"����");
};

ZHANGMEN_END;
