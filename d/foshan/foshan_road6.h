//road6.h

//Sample for room: �ּ��6
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��6");
	
	add_npc("pub_playboy");  // add by zdn 2001-07-13

	CBox * box = Add_Box();
	box->add_object("shikuai", 2);	
	box->set_name( "����");	

	add_door("��ɽ�ּ��7", "��ɽ�ּ��7", "��ɽ�ּ��6");
	add_door("��ɽ�ּ��5", "��ɽ�ּ��5", "��ɽ�ּ��6");

	set("long", "������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�" );

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
