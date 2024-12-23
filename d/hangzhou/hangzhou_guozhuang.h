//guozhuang.h

//Sample for room: ���ݹ�ׯ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_guozhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݹ�ׯ");

	//add npcs into the room
	add_item("daotian");
	
	add_door("�����غ����1", "�����غ����1", "���ݹ�ׯ");

	set("long","ׯ԰�Ĵ������ǡ���ׯ���������֡�����(gate)���գ����澲���ĵ�һ��������û�С�");
    

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
