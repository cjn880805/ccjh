//zhang.h
//code by zwb
//12-16
//inherit F_MASTER;

ZUSHI_BEGIN(CNwudang_zhang);

virtual void create()
{
	set_name("������","zhang sanfeng");
	set("nickname", "��������" );
	set("long", "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ���һ���ۻ�Ļ�ɫ���ۣ����ޱ߷�����ĸߴ��������꣬������⣬��ü�԰ס�");
	set("gender", "����");
	set("age", 100);
	set("foolid",127);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	
	set("hp",30000);
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 70000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 400);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_huan",1);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}


virtual void attempt_apprentice(CChar * player)
{
	static char msg[255];

	if (player->query_skill("taiji_shengong",1) < 100)
	{
		say("���䵱�����ڼ��书���������ڹ��ķ���",player); 
		SendMenu(player);
		return;
	}
	if (player->query("repute") < 100000)
	{
		say("ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�",player);
		say(snprintf(msg,255," �ڵ��з��棬%s�Ƿ����ò�����",query_respect(player)),player);
		SendMenu(player);
		return;
	}
	if (player->query_int() < 30) 
	{
		say("���䵱���书ȫ�ӵ��������",player);
		say("Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�",player);
		say("������Ի�����Ǳ�����ڣ�������ذɡ�",player);
		SendMenu(player);
		return;
	}
	say(" ����������������");
	say("�벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()));
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "�䵱��԰С·8" ))
		return notify_fail("�����������");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;