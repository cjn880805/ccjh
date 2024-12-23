//xiaochang.h

//Sample for room: У��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "У��");

	add_npc("pub_jianke");
	add_npc("pub_daoke");      //add by zdn 2001-07-13

	add_door("������", "������", "����У��");

	set("long", "����У��Ϊ����ˮʦУ�������е㽫¥�ϸ߹ҡ�ʩ���ֺ�����˧�죬��ǹҫ�����ԡ�ˮʦ�ᶽʩ��ʩ��������ʮ���۱�������������׳�Ĳ��ѡ�" );
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
