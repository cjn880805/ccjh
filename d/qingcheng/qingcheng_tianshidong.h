//tianshidong.h

//Sample for room: ��ʦ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_tianshidong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʦ��");
	
	add_npc("pub_menmian");          //add by zdn 2001-07-14
	add_npc("pub_xiaomimi"); 

	add_door("���ɽ·2", "���ɽ·2", "�����ʦ��");
	add_door("�������ʯ", "�������ʯ", "�����ʦ��");
	add_door("��ǹ�����", "��ǹ�����", "�����ʦ��");
	add_door("��ǹ�������", "��ǹ�������", "�����ʦ��");


    

/*****************************************************
	set("exits", ([
		"northup"  : __DIR__"gulongqiao",
		"north"    : __DIR__"sanqingdian",
		"eastdown" : __DIR__"path2",
		"west"     : __DIR__"yinxing",
		"east"     : __DIR__"sandaoshi",
	]));
*****************************************************/
};


ROOM_END;
