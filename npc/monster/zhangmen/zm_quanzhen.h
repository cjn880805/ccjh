//zm_quanzhen.h
//code by Lanwood
//2001-2-26

//����NPC
ZHANGMEN_BEGIN(CNzm_quanzhen);

virtual void create()
{
	CNmonster_zhangmen::create();
	
	create_family("ȫ���", 2, "�ƽ�");
};

ZHANGMEN_END;
