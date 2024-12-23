//nianhuasi.h

//Sample for room: �黨��
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiWest_nianhuasi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�黨��");

	//add npcs into the room
	add_npc("pub_laojisi1");
	
	add_door("�����ɽ·2", "�����ɽ·2", "������黨��");

	set("long", "ɽ·Խ��Խ��Ƨ��ת���ĸ�ɽ�꣬����һ��СС�Ĺ���ǰ��������д�š��黨�¡����֡�����Ǵ�����̡����������⣬������ʮ��С���԰ټƣ��������黨�¡��ش�ƫƧ��������𣬼������Ӵ���֮�ˣ����Ҳ��֪����" );

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
