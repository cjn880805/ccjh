//road11.h

//Sample for room: �ּ��11
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��11");

	CBox * box = Add_Box();
	box->add_object("shikuai", 1);	
	box->set_name( "����");	

	add_door("��ɽ�ּ��10", "��ɽ�ּ��10", "��ɽ�ּ��11");
	add_door("��ɽ�ּ��13", "��ɽ�ּ��13", "��ɽ�ּ��11");

	set("long", "������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�" );
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
