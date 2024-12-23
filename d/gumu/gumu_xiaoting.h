//xiaoting.h

//Sample for room: ��ĹС��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĹС��");


	add_door("��Ĺǰ��", "��Ĺǰ��", "��ĹС��");
	add_door("��Ĺ����", "��Ĺ����", "��ĹС��");
	add_door("��ĹС��", "��ĹС��", "��ĹС��");
	add_door("��Ĺ����", "��Ĺ����", "��ĹС��");

    set("long","������һ��СС�����ã�Ҳ����Ϊ������ǰ���������õġ����ߵ������Χ�Ĺ�������һЩ���㷢������ȼ����һЩ�͵ơ�����Ĳ������������ª��һ��һ�ζ���ʰ�ľ���������" );

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
