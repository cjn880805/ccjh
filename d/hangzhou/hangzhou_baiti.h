//baiti.h

//Sample for room: ���ݰ׵�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baiti);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݰ׵�");
	
	add_npc("pub_boy");          // add by zdn 2001-07-14

	add_door("���ݶ���", "���ݶ���", "���ݰ׵�");
	add_door("����ƽ������", "����ƽ������", "���ݰ׵�");

	set("long"," �׵̺ᵩ���ϣ��������ֳ������������������������������ҡ�ÿ�괺������������˿���̣��������մ�Ц�����׾������С��һ����������ۣ�ǳ�ݲ���û���㡣������в��㣬���������ɳ�̡�������������ľ�ɫ���������߹��˽����ű��ǡ�ƽ�����¡����������Ƕ��š�");

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
