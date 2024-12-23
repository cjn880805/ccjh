//huanyuan.h

//Sample for room: ���ջ�԰
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_huanyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ�԰");

	//add npcs into the room
	add_npc("lingjiu_zhang");
	add_npc("lingjiu_lu");
	add_npc("lingjiu_yu");
	add_npc("wuji");
	add_item("jiashan");

	add_door("���ջ���15", "���ջ���15", "���ջ�԰");
	add_door("���ջ���1", "���ջ���1", "���ջ�԰");
	add_door("���ջ���2", "���ջ���2", "���ջ�԰");
	add_door("����С��1", "����С��1", "���ջ�԰");


/*****************************************************
  set("exits",([
      "west" : __DIR__"changl1",
      "north" : __DIR__"xiaodao1",
      "east" : __DIR__"changl2",
      "south" : __DIR__"changl15",
  ]));
  set("outdoors", "lingjiu");
  set("item_desc", ([
      "jiashan" : "������ɽ����������̫����Ӧ�ÿ��԰ᶯ(move)��.\n",
  ]));
  set("objects",([
      __DIR__"npc/lu" : 1,
      __DIR__"npc/zhang" : 1,
  ]));
********************************************/
};


ROOM_END;
