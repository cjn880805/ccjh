//zm_emei.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_emei);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("������", 4, "������");
};

ZHANGMEN_END;
