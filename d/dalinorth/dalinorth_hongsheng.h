//hongsheng.h

//Sample for room: ��ʥ����
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiNorth_hongsheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʥ����");

	add_npc("pub_jianke");    // add by zdn 2001-07-13
	add_npc("dali_poyi");        //add by zdn 2001-07-20

	add_door("����ǲ�ɽ", "����ǲ�ɽ", "����Ǻ�ʥ����");
	add_door("�����´���", "�����´���", "����Ǻ�ʥ����");

	set("long", "��ʥ����������һ�����������ڲ�ɽ֮´�����������Ϊ������������֮һ����ʥ����Ϊ�ķ��ο���שʯ�����������֮����ש������ɬ����ʹ���ĽǷ��̡��������������������ߣ�����������" );
	
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
