//zushidian.h

//Sample for room: ��ʦ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_zushidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʦ��");
	
	add_npc("pub_youke");  //add by zdn 2007-07-14


	add_door("��ǹ�����", "��ǹ�����", "�����ʦ��");
	add_door("��ǳ�����", "��ǳ�����", "�����ʦ��");

	set("long","��ʦ���������乬����ʦ�����ԯ�壬�������Ϫ��ʮ�����ġ���������̨���ഫΪ�Ƶ��ܵ�����");
    

/*****************************************************
	set("exits", ([
		"eastup"    : __DIR__"chaoyangdong",
		"southdown" : __DIR__"gulongqiao",
	]));
*****************************************************/
};


ROOM_END;
