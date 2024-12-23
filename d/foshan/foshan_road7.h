//road7.h

//Sample for room: �ּ��7
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��7");
	
	add_npc("pub_liumangtou");    // add by zdn 2001-07-13
	add_npc("pub_tuguaiguai");

	CBox * box = Add_Box();
	box->add_object("shikuai", 1);	
	box->set_name( "����");	

	add_door("��ɽ����", "��ɽ����", "��ɽ�ּ��7");
	add_door("��ɽ�ּ��6", "��ɽ�ּ��6", "��ɽ�ּ��7");

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
