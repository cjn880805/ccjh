//xy_shiganlu.h	����ذ��ѡ�ʯ��¶
//�ز� 2002��12��2

NPC_BEGIN(CNxy_shiganlu);

void create()
{
	set_name("ʯ��¶","shi ganlu");
	set("gender", "Ů��");
	set("age", 28);
	set("long","����һ������������һ�����´��øɾ����ţ���Ҳ˹˹���ģ������ϻ�����һ��ǳ��ɫ��С����");

	set("attitude", "peaceful");
	set("icon",young_woman10);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 20+random(6));
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	set_skill("zhemei_shou", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","����");
	set("no_huan",1);

};

void init(CChar * me)
{
	CNpc::init(me);
	if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_62") && me->query_temp("xy/renwu1_63")
		&& me->query_temp("xy/renwu1_64") && me->query_temp("xy/renwu1_65") && me->query_temp("xy/renwu1_66")
		&&!me->query_temp("xy/renwu1_7"))
	{
		//����Ѿ�������������������ҵ�ʯ��¶�����ͻ�����ɵġ���װ�ع����������
		CContainer * bot = load_item("redrose");
		bot->set_name("��װ�ع�", "hong zhuang");
		bot->set("long","һ��Ҷ��֦��Ĳ��꣬������ż����ɫ�Ĳ軨��ÿ��軨�Ļ����ϻ�׺���ŵ���ߡ�");
		bot->set("value", 1);      
		bot->set("unit", "��");
		bot->move(me);
		tell_object(me,"\n$HICʯ��¶С�ĵ�����һ���Ѿ�ʢ���ġ���װ�ع����������㡣\nʯ��¶΢΢Ц���������軨����������Ҳ�����˼������Ҫ�͸��㣬�Ҷ���Щ�᲻���ˣ���");
		me->set_temp("xy/renwu1_670",1);
		me->set_temp("xy/renwu1_7",1);//����װ�ع����Ѿ����ɣ����Ը��������ˡ�
	}
	else if (me->query_temp("xy/renwu1_3")  && !me->query_temp("xy/renwu1_42")&& !me->query_temp("xy/renwu1_4")) 
	{
		//set("����",1);
		//disable_player("������");
		//set("apply/name","ʯ��¶<������>");
		//UpdateMe();
		//set_weight(50000000);
		tell_object(me,"\n$HIC�㿴������Ȫ�ߵ���һ�����긾�ˣ��������ƺ�������Ҫ�ҵ��ˣ�ֻ����˫Ŀ���գ������Ѿ����Թ�ȥ�ˡ�\n");
		me->set_temp("xy/renwu1_31",1);//ʯ��¶�ж�����
	}
}

virtual int do_look(CChar * me)
{
	if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		say("��������һ���˿ڣ�����ɫ����һ�飬���Ǳ��ζ������ˡ�", me);
		SendMenu(me);
		me->set_temp("xy/renwu1_4",1);//�۲쵽ʯ��¶�ж�����
		return 1;
	}
	
	return CChar::do_look(me);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("xy/renwu1_82") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("����ʯ��¶����Ѱ�Ҹ���֮��","fudi",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "fudi") )
		{
			say("ʯ��¶˵����������ǽ���Բ��ֹǧ���ȥ��Ȼ������֣���",me);
			say("ʯ��¶����˵��������������ɽ��Ѱ�ñ���С�����֮�ס�����˵���ܴ�ͨ���¹�֮·��ʱ��֮�ף���Ȼ�������ţ���Ҳ���ҵ�һ�����⣬��ú��ղء���",me);
			tell_object(me,"ʯ��¶����������1������֮�ס�");
			me->delete_temp("xy");
			me->del("xy/renwu1");
			me->set("xy/renwu2",1);//��ң����ڶ����֣�ȡ������֮��
			CContainer * bot = load_item("yingyue_si");
			bot->set("owner",me->id(1));
			bot->move(me);
			SendMenu(me);
		}
		return 1;
	}
	else if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_670"))
	{
		if(!me->query_temp("xy/renwu1_67"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ת��ʯ��¶������Ϧ���֮��","qixi",me);
			}
			else if(!strcmp(ask, "qixi") )
			{
				char msg[255];
				if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_670") )
				{
					if(!me->query_temp("xy/renwu1_67") )
						me->set_temp("xy/renwu1_67",1);//֪ͨʯ��¶�μ���Ϧ���
					if(EQUALSTR(me->querystr("family/family_name"), "��ң��")&& EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))//��ң����
					{
						say("ʯ��¶���������ǰ�ʦ���ô˷���ۣ�ȫ����ʦ��֮����ֻ����Ϧ֮ʱ��ʦ��Ҳ���͹�μӣ�",me);
					}
					else
						say(snprintf(msg, 255, "ʯ��¶���������ǰ�ʦ���ô˷���ۣ�ȫ����%s֮����ֻ����Ϧ֮ʱ��%sҲ���͹�μӣ�",query_respect(me),query_respect(me)),me);
				}
				else
					say("ʯ��¶���ɻ�Ŀ��㡣",me);
			}
			SendMenu(me);
		}
		return 1;
	}
	else if(me->query_temp("xy/renwu1_42") && !me->query_temp("xy/renwu1_43"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ�ʹ������֡���װ�ع�����Ҫ��", "zai",me);	
		}
		else if(!strcmp(ask, "zai") )
		{
			say("ʯ��¶��Ц������л��λ�������֮�����Ի����С�£����ɷ��Ľ����ҡ���",me);
			me->set_temp("xy/renwu1_43",1);//ʯ��¶��Ӧ�ֻ�
		}
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_7"))
	{
		say("ʯ��¶˵������Ҫ���������ã�����һ��ʱ�䡣��������ȴ�����ټ���������λʦ�ֵܡ���֪�����ɷ��æѰ�ң�������ߴ�ʦ�ֿ���ˮһ��������ʱ�������ң�֣����߱��롣��",me);
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		switch(me->query_temp("xy/renwu1_32"))
		{
		case 0:
			say("�Է���Ȼ�޷����㽲����", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 1:
			say("������������ʯ��¶��������˫Ŀ���գ�û�а�����ѹ�������˼��", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 2:
			say("ʯ��¶���ϵĶ����ƺ����ڲ�����ɢ�������ټ�ʱ���Σ���������֮�ǡ�", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 3:
			say("������һ��Īչ֮ʱ��ͻȻ������ң������λ��ҩ����������Ѧ��ҽ��Ҳ��֪���᲻����ʲô�취��", me);
			break;
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����") && EQUALSTR(ob->querystr("id"), "hua zhong")
		&& me->query_temp("xy/renwu1_43") && !me->query_temp("xy/renwu1_5") )
	{
		destruct(ob);
		say("ʯ��¶����ѯ�ʵ�������֪�����ú�ҩ���������֮������ ",me);
		say("����ʵ�ش�˵�ǡ��ⶾ�����衹�� ",me);
		say("ʯ��¶��һ����ѣ��ʧ��������ԭ����Ѧʦ�֣����ҡ����Ȱ��ѡ���ֻ��һ�������ѵ�ԭ�����ɢ���ء����ȴ��Ե�ɺϣ������Ƕ���δ����ʦ�־���һ������",me);
		say("ʯ��¶˵������Ҫ���������ã�����һ��ʱ�䡣��������ȴ�����ټ���������λʦ�ֵܡ���֪�����ɷ��æѰ�ң�������ߴ�ʦ�ֿ���ˮһ��������ʱ�������ң�֣����߱��롣��",me);
		SendMenu(me);
		me->set_temp("xy/renwu1_5",1);//��Ӧʯ��¶Ѱ�Һ��Ȱ���
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		if(!strcmp(comm, "fight") )
		{
			tell_object(me,"ʯ��¶�Ѿ��޷�ս���ˡ�");
			return 1;
		}
		else if(!strcmp(comm, "apprentice")  )
		{
			tell_object(me,"������Ȱ�ʯ��¶Ū�ѡ�");
			return 1;
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




