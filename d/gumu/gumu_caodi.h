//caodi.h

//Sample for room: ��Ĺ�ݵ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_caodi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ�ݵ�");

	add_npc("animal_dushe");

	add_door("��Ĺ����2", "��Ĺ����2", "��Ĺ�ݵ�");
	add_door("��ĹĹ��", "��ĹĹ��", "��Ĺ�ݵ�");
	add_door("��Ĺ�ݵ�2", "��Ĺ�ݵ�2", "��Ĺ�ݵ�");

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
