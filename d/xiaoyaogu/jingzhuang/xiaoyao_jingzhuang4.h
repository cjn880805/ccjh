//jingzhuang4.h
//Sample for room: ����Ǿ���4

ROOM_BEGIN(CRXiaoYao_jingzhuang4);

virtual void create()
{
	set_name( "����Ǿ���4");
	set("no_autosave",1);

	add_door("����Ǿ���3", "��ң�ȴ���Ǿ���3", "��ң�ȴ���Ǿ���4");
	add_door("����Ǿ���5", "��ң�ȴ���Ǿ���5", "��ң�ȴ���Ǿ���4");

	set("long", "���а����������Դ����ж�����������Ŀ���䣬�ݲ��ɱ档�����������������ķ𾭡�����β�����С��ȼú���--�����ˡ�������" );
	
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
