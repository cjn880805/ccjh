//xiayiting.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_xiayiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("huanghe_zu");        //add by zdn 2001-07-20
	add_npc("pub_jiaoqi"); 

	add_door("�ƺӹ㳡", "�ƺӹ㳡", "�ƺ�������");

	set("long","���ǻƺӰ����µĴ��������Ϲ��š��������������Ҷ���￿�����Ϸ���һ�Ż�Ƥ���Σ����߰����ż�����ľ���Σ��ǳ������ɡ�ǽ�ϸ�ӹ���ŵع��˼��������鷨��(paizi)��");

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/sha" : 1,
		__DIR__"npc/peng" : 1,
		__DIR__"npc/liang" : 1,
	]));
//	
********************************************/
};


CHANGAN_END;
