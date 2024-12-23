//dangpu.h

//Sample for room: Ӣ�۵䵱
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ӣ�۵䵱");

	//add npcs into the room
	add_npc("pub_chaofeng");
	
	add_door("��ɽ", "��ɽ", "��ɽӢ�۵䵱");

	set("long", "������һ�Ÿ߸ߵĹ�̨����̨�������ŵ��̵ĳ����ҵ����Ƿ���ү������ʮ��������û�����ֹ��£�����Ҳ�ͺܷ��ġ���̨�Ϲ���һ��ľ����(paizi)��" );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
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
