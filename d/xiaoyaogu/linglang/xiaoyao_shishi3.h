//xiaoyao_shishi3.h ��ߧ����ʯ��3(������)
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_shishi3);

virtual void create()
{
	set_name( "ʯ��3");
	set("no_autosave",1);
	set("long","������Բ��ʯ�ң��ı���ʯ��ĥ�����ǹ⻬��ʯ���Ͽ������������������ԲȦ��ÿ��Ȧ�ж����˸��ָ�����ͼ�Ρ���");

	add_door("��ߧ����", "��ң����ߧ����", "��ң����ߧ����ʯ��3");
	set("index",3);
	add_item("shiguei");
	add_npc("xy_xiaoyaozi1");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		say("����ϸ�о���ǽ�ϵ�ͼ��������ԼԼ�У����������ƺ�������һ�ֺܸ���ĵ�����", me);
	}
	SendMenu(me);
	return 1;
}
XiaoYao_END;
