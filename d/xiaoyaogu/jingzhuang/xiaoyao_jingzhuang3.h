//jingzhuang3.h
//Sample for room: ����Ǿ���3

ROOM_BEGIN(CRXiaoYao_jingzhuang3);

virtual void create()
{
	set_name( "����Ǿ���3");
	set("no_autosave",1);

	add_door("����Ǿ���2", "��ң�ȴ���Ǿ���2", "��ң�ȴ���Ǿ���3");
	add_door("����Ǿ���4", "��ң�ȴ���Ǿ���4", "��ң�ȴ���Ǿ���3");

	set("long", "��������������������֮������������һ�顣ʶ��ν�����۹���������Ϊ�ز��������������Ŀ�Ͱ�����̾�ϸ������������" );
	
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
