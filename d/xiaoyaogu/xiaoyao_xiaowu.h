//xiaoyao_xiaowu.h С��
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_xiaowu1);

virtual void create()
{
	set_name( "С��");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);
	add_npc("xy_liqiouheng");

	add_door("��ң��СԺ", "��ң��СԺ", "��ң��С��");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") )
		{
			CContainer * env=me->environment();
			CContainer * XyNpc=env->present("li qiou heng");
			if(XyNpc && !XyNpc->querystr("owner")[0])
				destruct(XyNpc);
		}
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("xy/renwu3") && !me->query_temp("xy/tanhuan5")
		&& me->query_temp("xy/renwu3_5") && !me->query("xy/renwu4"))
	{
		me->disable_player("������");
		me->call_out(do_tanhua1, 1);
	}
	else if(!me->query("xy/renwu3") && !me->query_temp("xy/tanhuan")
		&& me->query_temp("xy/renwu2_2"))
	{
		me->disable_player("������");
		me->call_out(do_tanhua, 1);
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4") )
		{
			if(!me->query("xy/renwu3") )
				return 0;
			else if(me->query_temp("xy/renwu3_5") )
				return 0;
		}
	}

	return CRoom::valid_leave(me, dir);
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	char msg[255];
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me, "\nֻ����ɽ�������Թ��еĿ����Լ�����æ�����µأ������л��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "Ȼ����һ���������Լ�����Ȭ���ɻ���磬ֻ�����������Ӳ�����ѡ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, snprintf(msg, 255,"��ɽ���ѻ�æ���𣬵�����%s������ʦ�ܵ�ҩ�󣬸о��ö��˰ɣ���",query_respect(me)));
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "��˫�������������ţ�С�������֮������������ġ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "�����꣡����ɽ�������������С����̲�ס����һЦ��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "������С���ﳤС����̵Ľ����ˣ��ҵ���Ϳɲ�С���Ժ����Ի����ס���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, snprintf(msg, 255,"��ɽ���ѽ���˵������Ҳ��%s�����þ����ܰ�Ȼ��������ң�ȣ������Ե��ǳ������ʹ���ȥ����ʦ�ܣ���������Ϊ����ϡ���\n",query_respect(me)));
		me->delete_temp("xy");
		me->del("xy/renwu2");
		me->set("xy/renwu3",1);//����������֣�Ѱ������ѩ���ⶾ
		me->enable_player();
		CChar * XyNpc ;
		CContainer * Xy_Npc;
		CContainer * tielao=env->present("tong lao");
		tell_object(me, "��ɽ���ѽ�����СԺ��");
		if(tielao)
			destruct(tielao);
		env = load_room("��ң��СԺ");
		Xy_Npc=env->present("tong lao");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_tielao");
			XyNpc->move(load_room("��ң��СԺ"));
		}
		//���������Ƿ�СԺ�У���û�����NPC���һ��
		Xy_Npc=env->present("li qiou heng");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_liqiouheng");
			XyNpc->move(load_room("��ң��СԺ"));
		}
		//�����׺��Ƿ�СԺ�У���û�����NPC���һ��
		Xy_Npc=env->present("li cang hai");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_licanghai1");
			XyNpc->move(load_room("��ң��СԺ"));
		}
		//�����ң���Ƿ�СԺ�У���û�����NPC���һ��
		Xy_Npc=env->present("xiaoyao zi");
		if(!Xy_Npc)
		{
			XyNpc = load_npc("xy_xiaoyaozi");
			XyNpc->move(load_room("��ң��СԺ"));
		}
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan5"))
	{
	case 0:
		tell_object(me, "\n�����������˹�����");
		me->add_temp("xy/tanhuan5",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "�㷢����֫������˵�������泩������Ͷ���������Ȼ����������");
		me->add_temp("xy/tanhuan5",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "ԭ������ң������Ϊ���ƶ�������ڹ�����һ���ˣ�");
		me->set("xy/renwu4_1",1);//�����������10��
		me->add("max_mp",10);
		me->UpdateMe();
		tell_object(me,"\n$HIR���������������ˡ���\n");
		me->enable_player();
		me->set("xy/renwu4",1);//������Ĳ��֣���ȡ�������еı���
		me->del("xy/renwu3");
		me->del("xy/renwu3_2");
		me->delete_temp("xy");
		break;
	}
}
XiaoYao_END;
