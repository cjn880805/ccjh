//path2.h

//Sample for room: ���ɽ·2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_path2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ɽ·2");
	
	add_npc("pub_punk");          //add by zdn 2001-07-14


	add_door("�����ʦ��", "�����ʦ��", "���ɽ·2");
	add_door("�����Ȼͼ��", "�����Ȼͼ��", "���ɽ·2");

	set("long","���������ɽ·�ϡ�ɽľ���գ��ľ����ˡ����Ͼ�����ʦ������������Ȼͼ����");
    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"tianshidong",
		"eastdown" : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
