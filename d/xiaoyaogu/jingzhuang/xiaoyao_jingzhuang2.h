//jingzhuang2.h
//Sample for room: ����Ǿ���2

ROOM_BEGIN(CRXiaoYao_jingzhuang2);

virtual void create()
{
	set_name( "����Ǿ���2");
	set("no_autosave",1);

	add_door("����Ǿ���1", "��ң�ȴ���Ǿ���1", "��ң�ȴ���Ǿ���2");
	add_door("����Ǿ���3", "��ң�ȴ���Ǿ���3", "��ң�ȴ���Ǿ���2");

	set("long", "Ϊ�������񣬸��б��飬����¡�𣬽�ڱ��֣����Ⱪ�𣬼�������С�" );
	
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
