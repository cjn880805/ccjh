//yaocaidian.h

//Sample for room: �ƺ�Ƥ��ҩ�ĵ�
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_yaocaidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�Ƥ��ҩ�ĵ�");

	//add npcs into the room
	add_npc("pub_huoji");

	add_door("�ƺӹ���", "�ƺӹ���", "�ƺ�Ƥ��ҩ�ĵ�");

	set("long","���ǹ��˳���Ψһ��һ�ҵ��̣�һ̤�����ھͿ��ŵ�һ�ɵ�������ζ���������Կ����ѷ��ں�Ժ��ɹ�ĸ�ʽƤ�������в���ǧ���������ǽ�ߣ�����һ�����ľҩ������ʢ���˲�ҩ��");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
********************************************/
};


CHANGAN_END;
