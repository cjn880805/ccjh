//tiyun.h

//Sample for room: ���Ʒ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ʒ�");
	
	add_npc("pub_jianke");   // add by zdn 2001-07-13

	set("monster_chance", 50);

	CBox * box = Add_Box();
	if(! random(10))
		box->add_object("qinghong", 1);	//put 100 coind into box
	else
		box->add_object("coin",1);	// Put 1 coin into box :ppp
	box->set_name( "ʯ��", "hole");
	box->Locked("���", 60000);

	add_door("����������", "����������", "�������Ʒ�");

    set("long","�����山����һɽ�壬�弹���ݺ��ٲ���Զ�����ڰ����ƣ��������ݣ��������Ʒ塣" );
    

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
