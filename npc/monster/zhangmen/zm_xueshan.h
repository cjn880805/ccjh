//zm_xueshan.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_xueshan);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("ѩɽ��", 3, "���̷���");
};

ZHANGMEN_END;
