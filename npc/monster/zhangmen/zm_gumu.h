//zm_gumu.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_gumu);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("��Ĺ��", 4, "����");
};

ZHANGMEN_END;
