//huyingting.h

//Sample for room: ��Ǻ�Ӧͤ
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_huyingting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ǻ�Ӧͤ");
	
	add_npc("pub_youke");         // add by zdn 2001-07-14
	add_npc("qingcheng_ji");     //add by zdn 2001-07-20


	add_door("������幬", "������幬", "��Ǻ�Ӧͤ");

	set("long","��Ӧͤ�߾�����嶥���������ߴ������ٳ�Х�������ص�����ɽ��Ӧ����ѩ����ڣ����̲׺����������ǣ��̵���ޡ�����ҹ�֣���ʥ�Ƹ��ƣ���˵�����ɳ�������ʦ�����ɵƣ��������˸�̾���ѡ� '���µ�����ɽ' ���ƻ�񣬺���׳�ۡ�");
    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"eastdown" : __DIR__"shangqing",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
*****************************************************/
};


ROOM_END;
