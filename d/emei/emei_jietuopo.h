//jietuopo.h

//Sample for room:  ���ҽ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jietuopo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҽ�����");
	
	add_npc("emei_girldizi");     //add by zdn 200107-20


	CBox * box = Add_Box();
	box->add_object("coin", 80);	//put 100 coind into box
	box->set_name( "���");		//set box's name

				
	add_door("��������2", "��������2", "���ҽ�����");
	add_door("���ҹ�����", "���ҹ�����", "���ҽ�����");

	set("long","�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���������Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����ã�����һƬ���֡�����ɽϪ�����ʵ������µ����档");

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
