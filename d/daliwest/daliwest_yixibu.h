//yixibu.h

//Sample for room: ��Ϫ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_yixibu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ϫ��");

	//add npcs into the room
	add_npc("pub_shaonu");
	
	add_door("����ǰ�ͷ��", "����ǰ�ͷ��", "�������Ϫ��");
	add_door("����Ǳ���ɽ��", "����Ǳ���ɽ��", "�������Ϫ��");
	add_door("������������4", "������������4", "�������Ϫ��");

	set("long", "��Ϫ��Ҳ���������������Ĳ��䡣���ﴦ���µأ������в���ũ���ũҵ�����Ҫ�����ָ���������񾭳�Ǩ�㣬��������˼�������⣬�������ݶ��ܼ�ª��--����ǣ���ȥ�������ɽ�����ڽӽ��������ģ�����·�������൱ƽ��������ɽ����᫣���·�������ѡ�" );
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
