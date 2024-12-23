//xiaoyao_baihu17.h �׻�������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_baihu17);

virtual void create()
{
	set_name( "�׻�������");
	
	add_door("�׻�������6", "��ң�Ȱ׻�������16", "��ң�Ȱ׻�������17");
	add_door("�׻�������", "��ң�Ȱ׻�������21", "��ң�Ȱ׻�������17");
	
	add_npc("xy_baihu1");
	add_npc("xy_baihu1");
	
};


virtual int do_look(CChar * me)
{
	if(me->query_temp("xy/ta/�׻�/2")!=query("count") )
	{
		say("һ�Ⱥ���ʯ�ŵ�ס��ȥ·������������ʲô���ؿ����俪�ϡ������������ʧ�ޣ�ʯ���Ѳ�����ʵ��������ֻҪ����Щ����������ƿ��ˡ�", me);
		say("������ֱ���ƿ�ʯ��ǰ����Ҳ��֪�Ƿ������һЩ���µ��ݾ���������û��ǻ�ȥ������û�н⿪���صİ취��", me);
		AddMenuItem("�ƿ�ʯ��", "$0tuei $1", me);
		AddMenuItem("������취", "", me);
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (me->query_temp("xy/renwu4_1")  && me->query("xy/renwu4_3"))
	{
		if(!strcmp(comm, "tuei") )
			return do_tuei(me, arg);
	}
	return 0;
}

int do_tuei(CChar *me, char * arg)
{
	if(me->query("mp")<1500)
		tell_object(me, "\n$YEL������ȫ����������ʯ��������ȥ��ʯ����Ȼ��˿�������ƺ����������������\n");
	else
	{
		tell_object(me, "\n$YEL������ȫ����������ʯ��������ȥ��ֻ���¸µ�һ���죬ʯ�Ż���������ǽ�С�\n");
		char msg[255];
		int damage=me->query("hp")-random(500)-100;
		if(damage<0)
			damage=me->query("hp")-1;
		me->receive_damage("hp",damage);
		me->receive_wound("hp",damage);
		me->add("mp",-me->query("mp")*2/3);
		me->UpdateMe();
		switch(random(5))
		{
		case 0:
			tell_object(me, snprintf(msg, 255,"$HIRһ�ż�ʸ�������������������ܣ�����ܵ���%d����˺���\n",damage));
			break;
		case 1:
			tell_object(me, snprintf(msg, 255,"$HIR��Ȼ�䣬ǽ���������İ���������޿ɶ㣬����ܵ���%d���˺���\n",damage));
			break;
		case 2:
			tell_object(me, snprintf(msg, 255,"$HIR�ص׺���ð��һ�����棬�㱻���ȵĻ����Χ������ܵ���%d���˺���\n",damage));
			break;
		case 3:
			tell_object(me, snprintf(msg, 255,"$HIRһ���ʯ��Х��ѹ�£��㼱æ����һ�ߣ����Ա����˶ദ������ܵ���%d���˺�����\n",damage));
			break;
		case 4:
			tell_object(me, snprintf(msg, 255,"$HIRһư��ˮ��ͷ���£���ֻ���ñ���ˮ����֮����ʹ���̣��ͺ����ѿ����㣬����ܵ���%d���˺���\n",damage));
			break;
		}
		me->move(load_room("��ң�Ȱ׻�������21"));
		if(me->query_temp("xy/renwu4_1"))
		{
			CContainer * XyNpc;
			if(me->query_temp("xy/renwu4_1")==1)
			{
				XyNpc=present("tong lao");
			}
			else
			{
				XyNpc=present("li qiou heng");
			}
			if(XyNpc)
			{
				if(XyNpc->query("owner")==atoi(me->id(1)))
					XyNpc->move(load_room("��ң�Ȱ׻�������21"));
			}
		}
	}
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("��ɽ������"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIRͨ������һƬ�����滹��ʱ����һЩ�����������ֻ�ŵ����ľ������������ٽ�ǰһ�����������ǵ���ʦ������ʦ�������Ϊ��׳׳����\n");
			me->move(load_room("��ң�ȿյ�"));
			return 0;
		}
		CContainer * ShouWei=present("jiouwei hu");
		if(ShouWei)
		{
			tell_object(me, "$HIR�׻�������ȵ������󵨿�ͽ�������Ҵ��׻���������������������£���");
			return 0;
		}
		if(me->query_temp("xy/ta/�׻�/2")!=query("count") && EQUALSTR(dir,"�׻�������"))
		{
			tell_object(me, "$HIRһ�Ⱥ���ʯ�ŵ�ס��ȥ·������������ʲô���ؿ����俪�ϡ�");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
