//majiu.h

//Sample for room: ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");
	add_npc("pub_mafu");
				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("���ݳ����", "���ݳ����", "�������");

	set("long", "���ǳ������ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ���������µ���ľ���϶���һ����ľ��(paizi)��");  
	set("no_fight", "1");
	set("no_beg", "1");
	
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
