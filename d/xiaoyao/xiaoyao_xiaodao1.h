//xiaodao1.h

//Sample for room: С��1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaodao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң��С��1");

	add_npc("xiaoyao_mengmianr");
	add_npc("zm_xiaoyao");

	add_door("��ң������", "��ң������", "��ң��С��1");

	add_door("��ң��ʯ��", "��ң��ʯ��", "��ң��С��1");
	add_door("��ң�ֹ�����", "��ң�ֹ�����", "��ң��С��1");
	add_door("��ң��С��2", "��ң��С��2", "��ң��С��1");

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
