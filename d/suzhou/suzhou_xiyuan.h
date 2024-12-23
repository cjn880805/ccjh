//xiyuan.h

//Sample for room: Ϸ԰��
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_xiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ϸ԰��");

	//add npcs into the room
	add_npc("pub_piaoyou");/////////////////////////
	add_npc("pub_liurusong");
	add_npc("xy_limuou");

	add_door("���ݱ�", "���ݱ�", "����Ϸ԰��");
//	add_door("�������", "�������", "����Ϸ԰��");

	set("long", "����һ�����ݳ��ﶦ��������Ϸ԰��Ϸ԰��������������ī����һӦ��ȫ������һ����Ϸ̨��̨�����ڳ��š�����������̨�²�ʱ�ش���Ʊ���ǵĽ�Ծ���Ȳ�������Ҳ�̲�ס������������Ϸ������һ�½�ǡ� " );

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
