//zm_taohua.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_taohua);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	 create_family("�һ���", 2, "����");
};

ZHANGMEN_END;
