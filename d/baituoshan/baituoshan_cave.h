//cave.h

//Sample for room: �Ҷ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_cave);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ҷ�");

	//add npcs into the room
	add_npc("animal_mangshe");
	add_npc("pub_jinhua");
	
	add_door("����ɽ����", "����ɽ����", "����ɽ�Ҷ�");

	set("long", "�����Ǵ��Ҷ��������ڡ�����ɽ������ĵ��������¾�������������γɵġ��ϱ��������֡��������߾ͽ����ˡ�");  

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
