//haigang.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_haigang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("resident", "���");

	//add npcs into the room
	add_npc("pub_boy");/////////////////////////
	add_npc("pub_girl");
	add_npc("pub_jinshisanniang");
	add_npc("mingjiao_changjinpeng");


	add_door("Ȫ��", "Ȫ��", "Ȫ�ݺ���");
	add_door("Ȫ�������", "Ȫ�������", "Ȫ�ݺ���");

	set("outdoors", "quanzhou");
/*****************************************************
	set("exits", ([
                "west" : __DIR__"zhongxin",
	]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
	set("objects", ([
		__DIR__"npc/boy": 2,
		__DIR__"npc/girl": 1,
		"/d/mingjiao/npc/changjinpeng": 1,
	]));
//	

********************************************/
};


RESIDENT_END;
