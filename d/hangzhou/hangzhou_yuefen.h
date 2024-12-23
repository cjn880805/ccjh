//yuefen.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuefen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("wei_yilian");

	add_door("��������", "��������", "��������");

	set("long","Ĺ��������ʯ����ʯ��ʯ����������١����йŰؽ��£��������ɵķ�Ĺ��Ĺ�����š���������Ĺ���� ����Ĺ�����棬��������֮�����Ƶ�Ĺ��Ĺ���Ͽ��š��μ��Һ�����֮Ĺ��.  ������ǰ�������ĸ�����(statue)������ǽ�����ĸ�����(word)��");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query_temp("wei/renwu7_7")&& !me->query_temp(" wei/renwu6_4")
		&& me->query_temp("wei/renwu8_12"))
	{
		tell_object(me,"\n$HIC��������������ǰ��˫ü�������ƺ��������޵����¡�������û��ע�⵽��ĵ�����");
	}
}

ROOM_END;
