//tuzai.h

//Sample for room: ���׳�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_tuzai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���׳�");

	//add npcs into the room
	add_npc("pub_tuchanghuoji");
	add_npc("honghua_lilishi");
	add_npc("pub_linguohong");
	
	add_door("�����ʳ�", "�����ʳ�", "�������׳�");

	set("long", "���������׳��������������������ζ��ż��һ���ȷ紵������ʱһ�ɳ���Ϯ����ֱѬ������Ż��һ������������������ָ���Ż����ɱ��ȥë������Ǿ����������׳�����˵�������е����ⶼ�Ǵ�������ȥ�ġ�" );
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
