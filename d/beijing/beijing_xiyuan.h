//xiyuan.h

//Sample for room: ����ϷԺ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_xiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ϷԺ");

	//add npcs into the room
	add_npc("pub_guanzho");
	add_npc("pub_guanzho1");
	add_npc("pub_guanzho2");
	add_npc("pub_guanzho3");
	add_npc("pub_guanzho4");
	add_npc("pub_guanzho5");
	add_npc("pub_xizi");
	
	add_door("��������", "��������", "��������ϷԺ");

	set("long", "������������ĳ���ϷԺ������Ϸ����̨��(stage)��Ϸ��̨�º�ѹѹ��һƬ�����ˡ�������������ǽ���ס�����Ȳɡ������Ǻ�̨��" );
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
