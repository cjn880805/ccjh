//xy_jingzhuang7.h
//Sample for room: ����Ǿ���7

ROOM_BEGIN(CRXiaoYao_jingzhuang7);

virtual void create()
{
	set_name( "����Ǿ���7");
	set("no_autosave",1);

	add_door("�չ���", "��ң�ȱչ���", "��ң�ȴ���Ǿ���1");
	add_door("����Ǿ���6", "��ң�ȴ���Ǿ���6", "��ң�ȴ���Ǿ���7");

	set("long", "�����Ǿ����Ķ�����Բ���ζ���������񷡣�������������𣬷�����ʿ�ȡ�" );
	
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
