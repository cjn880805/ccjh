//road1.h

//Sample for room: �ּ��1
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��1");

	//add npcs into the room
//	add_npc("animal_huananhu");
	add_npc("pub_punk");  //add by zdn 2001-07-13	

	CBox * box = Add_Box();
	box->add_object("shikuai", 1);	
	box->set_name( "����");		
	
	add_door("����ǻ���·", "����ǻ���·", "��ɽ�ּ��1");
	add_door("��ɽ�ּ��2", "��ɽ�ּ��2", "��ɽ�ּ��1");

	set("long", "������һ���ּ�С���������������ѡ��������ǹ������������߾��Ǵ�����ĵؽ��ˡ�" );

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
