// pub_jianning.h �����
// �ز�	2002��12��25

NPC_BEGIN(CNpub_jianning);

virtual void create()
{
	set_name("�����", "jian ning" );
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	set("age", 17);
	set("per",36);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",5000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	add_money((1+random(5))*1000);
	call_out(do_die, 900);	
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query_temp("wei/renwu2_5"))
		{
			say("����������ĵ�˵��������֪���Ǹ����ı������С�������ڹ�����ô���ˣ���",me);
			SendMenu(me);
			return 1;
		}
		else if(me->query_temp("wei/renwu2_4"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				me->set_temp("wei/renwu2_5",1);//�������Ӧ�ؼ�
				tell_object(me,"\n��������˿��������˵�˵��������ô�ղŲ�˵��С����������ѽ����ʵ�������ȥ�ˣ���");
				tell_object(me,"$HIC�����������������ͷ��");
				tell_object(me,"$HIC����������������ж���\n");
				
				CChar * wei = load_npc("pub_jianning");
				wei->move(load_room("������¥"));
				wei->set("owner",me->id(1));
				wei->set_leader(me);
				destruct(this);
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