//hsroad3.h

//Sample for room: ��ɽ����·
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_hsroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����·");
	
	add_npc("pub_jianke");        //add by zdn 2001-07-20
	add_npc("pub_lushen");

	add_door("������", "������", "��ɽ����·");
	add_door("��ɽ������", "��ɽ������", "��ɽ����·");
	add_door("��ɽ����ɽ��", "��ɽ����ɽ��", "��ɽ����·");
	add_door("�������д��", "�������д��", "��ɽ����·");

    set("long","������һ����������Ļ���·�ϣ���������ɭɭ�����֡����治Զ���Ǻ����س��ˡ�" );
    

/*****************************************************
    set("outdoors", "henshan");
	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));
********************************************/
};


ROOM_END;
