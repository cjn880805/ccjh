//zm_lingjiu.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_lingjiu);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("���չ�",3,"����");
};

ZHANGMEN_END;
