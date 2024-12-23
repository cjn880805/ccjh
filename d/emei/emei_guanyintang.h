//guanyintang.h
//Sample for room:  ���ҹ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_guanyintang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҹ�����");
	add_npc("pub_girldizi");   // add yb zdn 2001-07-14

	CBox * box = Add_Box();
	box->add_object("coin", 60000);	//put 100 coind into box
	box->set_name( "����֮ӡ", "enchantment");
	box->Locked("���", 18000);

	add_door("���ҽ�����", "���ҽ�����", "���ҹ�����");
	add_door("���ҹ��Ƹ�", "���ҹ��Ƹ�", "���ҹ�����");

	set("long","�����ø߾��¸ڣ�����Σ�£������ľ���������ľ��������Ŀ���ġ���˵��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬�ֹ��������֡���ɽ�����ڴ˷���ϴ�ģ���ɽ���ɻ���Ϊ�ģ�����ƽ�������ﶫ�¿ɴ�����£�������Լ����ɵ����Ƹ�");

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
