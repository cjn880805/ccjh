//xiaoyao_shishi2.h ��ߧ����ʯ��2�������ң�
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_shishi2);

virtual void create()
{
	set_name( "ʯ��2");
	set("no_autosave",1);
	set("long","������Բ��ʯ�ң��ı���ʯ��ĥ�����ǹ⻬��ʯ���Ͽ������������������ԲȦ��ÿ��Ȧ�ж����˸��ָ�����ͼ�Ρ���");

	add_door("��ߧ����", "��ң����ߧ����", "��ң����ߧ����ʯ��2");
	set("index",2);
	add_item("shiguei");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		say("����ϸ�о���ǽ�ϵ�ͼ��������ǧ������֮�У���Щ�ʻ���Ȼ����һ�ѳ��������ж���ʮ�ѣ����������ƺ�������һ�ֺܸ���Ľ�����", me);
	}
	SendMenu(me);
	return 1;
}

XiaoYao_END;
