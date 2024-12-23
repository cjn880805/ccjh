//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_feifei");

	CBox * box = Add_Box();
	box->add_object("doujiang", 1);	
	box->set_name( "����");
		
	CBox * box1 = Add_Box();
	box1->add_object("cake", 1);	
	box1->set_name( "����");	
	
//	add_door("����ɽ��", "����ɽ��", "����ɽ����");
	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ����");

	set("long", "���Ǽ���ĳ�������ʦ����չʾ���Ե���⿾�������������������˴������εĲ��㡣ǽ������һ����Ŀ������(note)��");
    set("no_fight", "1");
    set("no_beg", "1");
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
