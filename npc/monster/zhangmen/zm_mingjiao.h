//zm_mingjiao.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_mingjiao);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("����",35, "����");
};

ZHANGMEN_END;
