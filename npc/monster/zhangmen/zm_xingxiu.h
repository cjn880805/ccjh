//zm_xingxiu.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_xingxiu);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("������", 2, "��ɽ��ʦ");
};

ZHANGMEN_END;
