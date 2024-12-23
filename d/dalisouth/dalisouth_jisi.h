//jisi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_jisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_jisi");
	
	add_door("�������������", "�������������", "������ϼ�����");

	set("long", "�˼�����¥���㣬��һ����Ĵ��ݣ�����һ����̨��ʮ����ʯΧ��һȦ����������һ�����ƣ��ϻ汾�������ͼ����Ȧ�����м�����С�����ƣ�������������������ţ���̨ǰ���Ʒ������ã�ʱ������ǰ������Ĥ�ݡ�" );

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
