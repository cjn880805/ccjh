//guchangcheng.h

//Sample for room: �ƺӹų���
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_guchangcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӹų���");

	//add npcs into the room
	add_npc("pub_menmian");

	add_door("�ƺ�Ӫ��ˮ", "�ƺ�Ӫ��ˮ", "�ƺӹų���");
	add_door("�ƺ�ʯ��", "�ƺ�ʯ��", "�ƺӹų���");
	add_door("�ƺ�", "�ƺ�", "�ƺӹų���");

	set("long","������һ�ιų��ǡ��ഫ�ǵ�����ʼ���������ĸ�������������ʮ�������ޡ����±�Ǩ���׺�ɣ������������һƬ���棬Ψһ��ϡ�ɼ����Ǻ����Ƴɵķ��̨���С����һ������������ƺӴ�������ȥ��������һҶС�۰ڶɳ˿ͣ�����Խ�(yell)һ�´��ҡ�---��---������");

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"yinpanshui",
		"southeast" : __DIR__"shimen",
	]));
	set("objects", ([
		__DIR__"npc/menmian" :1,
	]));
********************************************/
};


CHANGAN_END;
