//huangyangtan.h

//Sample for room: ���ݻ���̲
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_huangyangtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݻ���̲");

	//add npcs into the room
//	add_npc("animal_lamb");/////////////////////////
        add_npc("lingzhou_yun");   //add by zdn 2001-07-20

	add_door("������", "������", "���ݻ���̲");
	add_door("����С��", "����С��", "���ݻ���̲");

	set("long", "��������������������Ļ���̲�������ǻƺӱߵ�һ��Ƭˮ���μ�أ��ƺ�ˮ���ĺ���ȥ�γ���һ��Ƭ����ˮ̲������ˮ�ݷ�ʢ���������������˴���������Ұ��������������ˮ��Ϸ��������Ϣ����Ϊ����һ�󾰹ۡ�");  
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
