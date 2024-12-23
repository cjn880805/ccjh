//caodi2.h

//Sample for room: ��Ĺ�ݵ�2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_caodi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ�ݵ�2");

	add_npc("animal_dushe");       //add by zdn 2001-07-13

	add_door("��Ĺ��ˮ̶", "��Ĺ��ˮ̶", "��Ĺ�ݵ�2");
	add_door("��Ĺ�ݵ�", "��Ĺ�ݵ�", "��Ĺ�ݵ�2");

	set("long","������һƬ�ݵأ��ݺ��������û��С�ȡ��ݼ�ɢ����һЩ�滨��΢�紵�����ҷ��˱ǡ�������ʱ���С������ˡ���������������һЩ��ͷ���İ�ɫ���۷��ڲݵ��Ϸ���������" );


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
