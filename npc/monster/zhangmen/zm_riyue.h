//zm_wudang.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_riyue);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("�������", 3, "���Ŵ����");
};

ZHANGMEN_END;
