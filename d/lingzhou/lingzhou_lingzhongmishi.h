//gongling.h

//Sample for room: ���ݹ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRlingzhou_lingzhongmishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");
	
	//add_npc("pub_youke");       //add by zdn 2001-07-14

//	add_door("��������", "��������", "������������");

	CBox * box = Add_Box();
	if(! random(3))
		box->add_object("icesword", 1);	//put 100 coind into box
	else
		box->add_object("coin",1);	// Put 1 coin into box :ppp
	box->set_name( "ʯ��", "coffin");
	box->Locked("���", 6000);

	set("long", "�������������ذ�˼������Ĺ���ذ�˼�������ʵ���Ǽ���˳��̫���������������Ϊ�����˼�����Ƴ�Ҳ�Ǽ������Ĵ󽫡������Ϊ�����Զ������ĹҲ�����������ΰ������ȥ�е��ưܡ�");  
	

/*****************************************************
	set("exits", ([
		"south"   : __DIR__"deling",
	]));
********************************************/
};

virtual int do_look(CChar * me)
{
	//ֻ�д�������ȷ�Ĵ𰸲��ܷ�������
	say("����ĵ���ȫ�ú�ʯ�̳ɣ�����������һС���ʯ���ر����ۣ�Ҳ����Բ�(steps)��ȥ������", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "steps") == 0)
	{
		message_vision("$N��ס���������ϰ�ʯ����", me);
		if(random(20) == 0)
			me->move(load_room("��������"));
		else
			message_vision("���ʲôҲû��������:>>", me);

		me->receive_damage("hp",30);
		return 1;
	}
	return 0;
}

ROOM_END;
