//xiaoyao_kongdi.h �յ�
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_kongdi);

virtual void create()
{
	set_name( "�յ�");

	add_item("mupai");

	add_door("��ң��������ɽ·5", "��ң��������ɽ·5", "��ң�ȿյ�");	
	add_door("��ң��������", "��ң��������", "��ң�ȿյ�");	
	add_door("��ң��������", "��ң��������", "��ң�ȿյ�");	
	add_door("��ң����ȸ��", "��ң����ȸ��", "��ң�ȿյ�");	
	add_door("��ң�Ȱ׻���", "��ң�Ȱ׻���", "��ң�ȿյ�");	

};

virtual int do_look(CChar * me)
{
	if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_5")  )
	{
		say("�յ�����һ��Ұ�ջ���һ���õ�塣",me);
		if(me->query_temp("xy/renwu4_1") && !me->query("xy/renwu4_41"))
		{
			CContainer * env = load_room("��ң�ȿյ�");
			if(me->query_temp("xy/renwu4_1")==2)//������������
			{
				//���������Ƿ�����ң�ȿյ�
				CContainer * liqiouhen=env->present("li qiou heng");
				if(liqiouhen)
				{
					say("�����ժ��һ��Ұ�ջ�������ز����ޱߣ�תͷ������ȻһЦ�����㿴ʦ�������𣿡�",me);
					AddMenuItem("���������", "$0zhanmei $1",me);	
					AddMenuItem("���ÿɷ�", "$0bushuo $1",me);
				}
			}
			else//���������ɽ����
			{
				CContainer * tielao=env->present("tong lao");
				if(tielao)
				{
					say("��ɽ����ժ��һ��Ұ�ջ������ޱߣ��̲�ס����̾��һ��������������",me);
					AddMenuItem("������ɽ����", "$0zhanmei1 $1",me);	
					AddMenuItem("���ÿɷ�", "$0bushuo1 $1",me);
				}
			}
			me->set("xy/renwu4_41",1);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("xy/renwu4_1") ||!me->query("xy/renwu4_3")  )
		return 0;
	CContainer * env = load_room("��ң�ȿյ�");
	if(me->query_temp("xy/renwu4_1")==2)
	{
		CContainer * liqiouhen=env->present("li qiou heng");
		if(liqiouhen)
		{
			if(!strcmp(comm, "zhanmei") && !me->query("xy/renwu4_41_1"))
				return do_zhanmei(me, arg);
			if(!strcmp(comm, "bushuo") && !me->query("xy/renwu4_41_2"))
				return do_bushuo(me, arg );
			if(!strcmp(comm, "rose") && !me->query("xy/renwu4_41_3"))
				return do_rose(me, arg);
			if(!strcmp(comm, "dai") && !me->query("xy/renwu4_41_4"))
				return do_dai(me, arg);
		}
	}
	else
	{	
		CContainer * tielao=env->present("tong lao");
		if(tielao)
		{
			if(!strcmp(comm, "zhanmei1") && !me->query("xy/renwu4_41_5"))
				return do_zhanmei1(me, arg);
			if(!strcmp(comm, "bushuo1") && !me->query("xy/renwu4_41_6"))
				return do_bushuo1(me, arg);
			if(!strcmp(comm, "dai1") && !me->query("xy/renwu4_41_7"))
				return do_dai1(me, arg);
			if(!strcmp(comm, "budai") )
				return do_budai(me, arg);
		}
	}
	return 0;
}

int do_zhanmei(CChar *me, char * arg)
{
	say("���޵�����ʦ������գ���ν������£�������ˮ������������������ˣ���",me);
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		say("�������������������š��һ�ѣ���������СѾͷ����Ȼ��ȡЦ��ʦ�壡��",me);	
	}
	else
	{
		say("�������������һ�ڵ���������������",me);
	}
	if(!me->query("xy/renwu4_41_1"))
	{
		me->add("xy/��ɶ�",1);
		me->set("xy/renwu4_41_1",1);
	}

	AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
		AddMenuItem("ʰ���õ����Լ�ͷ��", "$0dai $1",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "����"))
		AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
	SendMenu(me);
	
	return 1;
}

int do_bushuo(CChar *me, char * arg)
{
	say("��˵������������ͷ�ϲ��˶�Ұ���û��ʲô����ѽ����",me);
	say("����ۡ��ߡ���һ����",me);
	
	if(!me->query("xy/renwu4_41_2"))
	{
		me->add("xy/��ɶ�",-1);
		me->set("xy/renwu4_41_2",1);
	}

	AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
		AddMenuItem("ʰ���õ����Լ�ͷ��", "$0dai $1",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "����"))
		AddMenuItem("ʰ���õ���͸������", "$0rose $1",me);
	SendMenu(me);
	
	return 1;
}

int do_rose(CChar *me, char * arg)
{
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		say("�㽫��õ�������������ϣ�˵��������ʦ��������ޣ����Ժ�õ����ƺ����Ӻ��ʣ���",me);	
		say("�����Ц����������СѾͷ���������˻�ϲ�ģ��������ǲ�֪Ȥ��ʦ�㣬һ�쵽��ֻ֪���������ԣ���",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "����"))
	{
		say("�㽫���Ὣ��õ���������۵ķ���֮�ϣ���Ұ��������ֻ��װ����ɫ����ʦ�����ľ�ɫ���գ����Ժ�õ��������֮��������ģ���",me);	
		say("���������������������һ�ڣ���٬��Ц������ʦֶСС��ͣ���������Ů�˻��ģ��������Ǹ�����ʥ�֣���",me);
	}
	if(!me->query("xy/renwu4_41_3"))
	{
		me->add("xy/��ɶ�",1);
		me->set("xy/renwu4_41_3",1);
	}
	SendMenu(me);
	return 1;
}

int do_dai(CChar *me, char * arg)
{
	if(me->query("per")<36)
	{
		say("���õ�����ͷ�ϣ�����Ц������ʦ���������Ҳ��������",me);
		say("����۳���Ǻ�һЦ����СѾͷ�����Ƥ����",me);
	}
	else
	{
		say("������ذѺ�õ�����ͷ�ϣ�һʱ�䣬�ʻ��Ľ���ӳ�ĵ���Խ���������ˣ�����֮�£���������۲��÷ֺ���",me);
		say("����������һ������СС��ͣ��ͻ�ѧ����ҡ�ˣ���",me);
		if(!me->query("xy/renwu4_41_4"))
		{
			me->add("xy/��ɶ�",-1);
			me->set("xy/renwu4_41_4",1);
		}
	}
	SendMenu(me);
	return 1;
}

int do_zhanmei1(CChar *me, char * arg)
{
	say("�㿴����ɽ���ѣ��������ݵ������벻��ʦ��Ҳ�������ò��ƽ��������ô��δ�������أ���",me);
	say("��ɽ������¶��ɫ������������Ϊƽ������ֻ���ſ��������ʦ��ȥ�ˣ��͸�ʦ��һ��ģ������",me);	
	if(!me->query("xy/renwu4_41_5"))
	{
		me->add("xy/��ɶ�",1);
		me->set("xy/renwu4_41_5",1);
	}

	AddMenuItem("ʰ���õ����Լ�ͷ��", "$0dai1 $1",me);
	AddMenuItem("���ǲ�Ҫʰ���õ��Ϊ��", "$0budai $1",me);
	SendMenu(me);
	
	return 1;
}

int do_bushuo1(CChar *me, char * arg)
{
	say("��˵�������ö˶˵ģ�ʦ����̾ɶ��ѽ����",me);
	say("��ɽ���Ѷ�ݺݵص�����һ�ۡ�",me);

	if(!me->query("xy/renwu4_41_6"))
	{
		me->add("xy/��ɶ�",-1);
		me->set("xy/renwu4_41_6",1);
	}

	AddMenuItem("ʰ���õ����Լ�ͷ��", "$0dai1 $1",me);
	AddMenuItem("���ǲ�Ҫʰ���õ��Ϊ��", "$0budai $1",me);

	SendMenu(me);

	return 1;
}

int do_dai1(CChar *me, char * arg)
{
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		say("��ɽ��������ؿ�����һ�ۡ�",me);
		if(me->query("per")>30 && !me->query("xy/renwu4_41_6"))
			{
				me->add("xy/��ɶ�",-1);
				me->set("xy/renwu4_41_6",1);
			}
	}
	else
	{
		say("��ժ��һ���õ������Լ�ͷ�ϡ�",me);
		say("��ɽ������Բ�۾�������ŭ����������Ϊ�Ҵ����������˴���һ����Ц�𣡡�",me);
		me->add("xy/��ɶ�",-1);
	}
	SendMenu(me);
	return 1;
}

int do_budai(CChar *me, char * arg)
{
	return 1;
}
XiaoYao_END;
