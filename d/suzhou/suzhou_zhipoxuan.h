//zhipoxuan.h

//Sample for room: Ҿ��ָ����
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhipoxuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ҿ��ָ����");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-16


	add_door("����ʨ����", "����ʨ����", "����Ҿ��ָ����");

	
	set("long", "��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ˵���дʫ����֮��������ȡ���䡰ǰҾ®ɽ��һ����塱�͸����ġ�Цָͥǰ�ء���ʫ�⡣���ڰ�������ɫ��ƾ����������Ŀʯ����ᾣ��Ű��֦���ƣ�������Դ��ʮ�˾���֮�ơ�" );
	
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
