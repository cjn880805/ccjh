//qingcheng.h

//Sample for room: �ƺ����
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_qingcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����");
	
	add_npc("pub_jianke");
	add_npc("pub_poorman");         //add by zdn 2001-07-14


	add_door("�ƺӺ���", "�ƺӺ���", "�ƺ����");

	set("long","���λ�ھ�Զ�������ٶ�ʮ����ϰ�ʮ��������ݣ���Ϊ��ǣ���ʵֻ�Ǹ�С����Ϊ�ش���ȥ���ĵ�Ҫ�壬����������ĺʹ��ε����ö����뾭����������������������֡�(skulls)��");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"shamo",
		"east"  : __DIR__"hetao",
	]));
********************************************/
};


CHANGAN_END;
