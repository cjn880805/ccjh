// wei_fang.h ���
// �ز�	2002��12��25

NPC_BEGIN(CNwei_fang);

virtual void create()
{
	set_name("���", "fang yu" );
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	set("age", 20);
	set("per",31);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 170);
	set_skill("force", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("sword", 170);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",15000);
	set("mp", 1400); 
	set("max_mp", 1400);
	set("mp_factor", 10);

	carry_object("changjian")->wield();

	call_out(do_die, 900);	
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query_temp("wei/renwu6_1") && me->query_temp("wei/renwu6_10"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
				if(!me->query_temp("wei/renwu6_4"))
				{
					if(me->query_temp("wei/renwu6_7"))
					{
						AddMenuItem("ѯ�ʹ�������","yupei",me);
					}
					else
					{
						AddMenuItem("ѯ�ʹ�������Ů��","mengmian",me);
						AddMenuItem("ѯ�ʹ��ڳ��","chou",me);
					}
				}
				SendMenu(me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				if(!me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_8"))
				{
					me->set_temp("wei/renwu6_2",1);//��褲�ɱ�������ؼ�
					say("��褺޺޵�����ɱ�������������ǲ����ȥ�ģ���",me);	
					SendMenu(me);
				}
				else
				{
					me->set_temp("wei/renwu6_9",1);//��褴�Ӧ�ؼ�
					tell_object(me,"\n$HIC��褵�����лл�������������Ը��������ǣ����Ϳ��Զ���ȥ�ҷ���ˡ���");	
					tell_object(me,"$HIC��褾����������ж���\n");

					CChar * wei = load_npc("wei_fang");
					wei->move(load_room("����������"));
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_fang"));
				}
			}
			else if(!strcmp(ask, "yupei") )
			{
				if(!me->query_temp("wei/renwu6_4") && me->query_temp("wei/renwu6_7") && !me->query_temp("wei/renwu6_8"))
				{
					CContainer * env = load_room("����������");
					CContainer * wei1=env->present("zeng rou");
					if(wei1)
					{
						me->set_temp("wei/renwu6_8",1);//����������Ķ�Թ�˽�
						tell_object(me,"\n$HIC����������ȵؿ�����ѩ��������塣");	
						tell_object(me,"$HIC��ѩʹ������������ԭ�¡�");
						tell_object(me,"$HIC��ѩ��褽�������֮�¡�");
						tell_object(me,"$HIC��ѩȡ�¾��Ϲ��ŵ����彻���˷�褡�");
						tell_object(me,"$HIC��褾���һ��˼��������ԭ������ѩ��");
					}
					else
					{
						say("��褺޺޵����������������ҵ�һ�����塣��������˵���ϼ�ֵ���ǣ����Ͼ����Ҽ����洫֮���",me);		
						SendMenu(me);
					}
				}
			}
			else if(!strcmp(ask, "mengmian") )
			{
				say("��褺޺޵������������������Ҽ������ۣ���������������������С�����֪Ϊ��ʼ���Ҳ����˵أ�ֻ��˵���ں�����ʯ���6��������",me);			
				SendMenu(me);
			}
			else if(!strcmp(ask, "chou") )
			{
				say("��褺޺޵����������������ҵ�һ�����塣��������˵���ϼ�ֵ���ǣ����Ͼ����Ҽ����洫֮���",me);		
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;