//xiaoyao_xuanwu.h ������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_xuanwu);

virtual void create()
{
	set_name( "������");

	add_door("��ң�ȿյ�", "��ң�ȿյ�", "��ң��������");	

	set("long","�������ȥ�ưܲ��������������볾���ƺ��Ѿ��ܾ�û���������ˡ�");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("xy/renwu4_3") )
	{
		say("�������ƿ��ƾɵ����ţ�һ�������ͨ�������ֳ�����",me);
		say("ͨ������һƬ�����滹��ʱ����һЩ�����������",me);
		if(me->query_temp("xy/renwu4_1") && !me->query("xy/renwu4_53"))
		{
			if(me->query_temp("xy/renwu4_1")==2)
				say("���������зǳ����£�����������ʦ����һ�ԣ������̤ʵ����࣬����������������߽������ڡ�",me);
			else
				say("���������зǳ����£�����������ʦ����һ�ԣ������̤ʵ����࣬����������������߽������ڡ�",me);
			AddMenuItem("����������", "$0jinru $1", me);
		}
		else
		{
			say("ֻ�ŵ����ľ������������ٽ�ǰһ�����������ǵ���ʦ������ʦ�������Ϊ��׳׳����",me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("xy/renwu4_1") ||!me->query("xy/renwu4_3")  )
		return 0;
	if(!strcmp(comm, "jinru"))
		return do_jinru(me, arg);
	return 0;
}


int do_jinru(CChar *me, char * arg)
{
	me->move(load_room("��ң������������11"));
	//����Ҫ������NPCҲץ����
	if(me->query_temp("xy/renwu4_1"))
	{
		CContainer * XyNpc;
		CChar * Xy_Npc ;
		if(me->query_temp("xy/renwu4_1")==1)
		{
			XyNpc=present("tong lao");
			Xy_Npc= load_npc("xy_tielao");
		}
		else
		{
			XyNpc=present("li qiou heng");
			Xy_Npc= load_npc("xy_liqiouheng");
		}
		if(XyNpc)
		{
			destruct(XyNpc);
		}
		Xy_Npc->move(load_room("��ң������������11"));
		Xy_Npc->set_leader(me);
		Xy_Npc->set("owner",atoi(me->id(1)));
	}
	return 1;
}

XiaoYao_END;
