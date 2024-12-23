//wuqiku.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_wuqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_shiwei");

	CBox * box = Add_Box();
	box->add_object("shezhang", 1);	
	box->set_name( "ľ��");
		
	CBox * box1 = Add_Box();
	box1->add_object("gangzhang", 3);	
	box1->set_name( "ľ��");	
	
	add_door("����ɽԺ��", "����ɽԺ��", "����ɽ������");

	set("long", "�����ǡ�����ɽ�����ӵ������⣬������ɽ�����ӿ��Ե�����ȡ�����õĸ����������������ɵ����ǲ����������ġ�");  

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