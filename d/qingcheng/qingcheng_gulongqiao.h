//gulongqiao.h

//Sample for room: ��ǹ�����
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_gulongqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ǹ�����");
	
	add_npc("pub_bing");      //add by zdn 2001-07-14
	add_npc("qingcheng_yu");  


	add_door("�����ʦ��", "�����ʦ��", "��ǹ�����");
	add_door("�����ʦ��", "�����ʦ��", "��ǹ�����");

	
    

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"northup"   : __DIR__"zushidian",
		"southdown" : __DIR__"tianshidong",
	]));
*****************************************************/
};


ROOM_END;
