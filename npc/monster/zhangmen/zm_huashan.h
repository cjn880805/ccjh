//zm_huashan.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_huashan);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("��ɽ��", 14, "����");
};

ZHANGMEN_END;
