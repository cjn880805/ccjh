//bingqiku.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_bingqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_shiwei");   //add by zdn 2001-07-12 

	CBox * box = Add_Box();
	box->add_object("gangjian", 1);	
	box->set_name( "ľ��");
		
	CBox * box1 = Add_Box();
	box1->add_object("changbian", 1);	
	box1->set_name( "ľ��");		

	add_door("�������������", "�������������", "���������������");

	set("long", "���������������ı����������ܷ��⼸�������ܣ��������������˵���ƽʱ�����õ��񽣡�" );
	set("no_fight", 1);

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
