//zhou.h
//Lanwood 2000-01-05

NPC_BEGIN(CNpub_yinling);

void create()
{
	set_name("����", "yinling");
	set("long", "һ������ȥ�����ĵ�Ů���ӡ�");
	set("icon", young_woman2);
	
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "fighter");
	
	set_inquiry("���ڵ�ʲô��", "������ҵ�����");
//	set_inquiry("��������ɱ��", do_apply);
	
	set("foolid",1000);	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 50);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hubo", 300);
	set_skill("literate", 100);
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 200);
	set_skill("lingxu_bu", 200);
	set_skill("wudu_xinfa", 200);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
	create_family("������", 4, "���ŵ���");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * do_apply(CNpc * npc, CChar * me)
{
	if(me->query("level") < 10)
		return "�������깦�ɡ�";
	
	npc->call_out(do_fight, 5, me->object_id());
	return "�ߺߣ�������PK�����ȹ�����أ�";
}

static void do_fight(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	if(! me) return;

	npc->set("hp", npc->query("max_hp"));
	npc->set("eff_hp", npc->query("max_hp"));
	npc->set("mp", npc->query("max_mp"));
	
	me->set_temp("fight_ok", 1);
	Do_BiShi(npc, me, "�����ս��", 20);
}

//���Խ���
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//��ʤ,���ñ��.�ӳٺ���,�Ա��ս��������.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		winner->set_temp("corps/joining", "freedom");
		me = winner;
	}
	
	remove_call_out(do_join);
	call_out(do_join, 2, me->object_id(), 30);
}

static void do_join(CContainer * ob, LONG param1, LONG step)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	if(! me) 
	{
		if(step > 0) npc->call_out(do_join, 2, param1, step - 1);
		return;
	}

	const char * corps = me->querystr_temp("corps/joining");

	if(corps[0])	//��ʤ�Ļ�
	{
		npc->say("����ֵúܺã���ϲ���ȡ������PKִ�ա�", me);
		npc->say("��ɲ�ȡ���ⷽʽ��������ҽ���ɱ¾����������һ����ɱ������ʧҲҪ�ӱ���ȫ���书��һ����", me);
		me->set("freedom/pks", me->query("pks"));	
		me->set("freedom/rank", "����ɱ��");	
		me->setup();
		me->UpdateMe();
		npc->SendMenu(me);
	}
	
}

int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "diablo2") || DIFFERSTR(ob->querystr("name"), "����" ))
	{	
		message_vision("$N������������", this);
		return 0;
	}

	DESTRUCT_OB(ob, "yinling");

	CContainer * obj = load_item("baozi");

	obj->set_name( "�����", "bao zi");

	message_vision("$N��������$n���ͷ����$pһ��������", this, who);
	obj->move(who);
	
	who->set_temp("����/��ʦ", obj->object_id());
	return 1;
}


NPC_END;
