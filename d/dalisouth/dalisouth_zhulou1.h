//zhulou1.h

//Sample for room: ��¥��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��¥��");

	//add npcs into the room
//	add_npc("animal_cow");
	add_npc("animal_dog");           //add by zdn 2001-07-13
	
	add_door("������䶨��", "������䶨��", "�������¥��");

	set("long", "̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ������Ϊǽ����¥�����൱���¡��²������ֻ���ĸ����Ӽܿյģ��ȿ�������Ȧ��ҲΪ�˷��ߡ�һ������ͨ���ϲ�ķ��ᡣ" );
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
