//zm_btshan.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_btshan);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("����ɽ��", 2, "����");
};

ZHANGMEN_END;
