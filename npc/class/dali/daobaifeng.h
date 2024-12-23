//daobaifeng.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_daobaifeng);

virtual void create()
{
	set_name("�����", "dao fenghuang");
	set("title",  "���������");
	set("nickname",  "����ɢ��");
	set("gender", "Ů��");
	set("long", "���Ǹ���ò������������ã��Ǹ�������Ů�ӣ�����Ӻ�����ʡ�");
	set("age", 35);
	set("icon", young_man3);

	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 1800);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	set("combat_exp", 500000);
	set("score", 200000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("cuff", 100);
	set_skill("strike", 100);
	set_skill("whip", 100);
	set_skill("kurong_changong", 100);
	set_skill("duanjia_sword", 100);
	set_skill("tiannan_step", 100);
	set_skill("jinyu_quan", 100);
	set_skill("wuluo_zhang", 100);
	set_skill("feifeng_whip", 100);
	set_skill("literate", 60);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "feifeng_whip");
	map_skill("sword", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set_inquiry("����","��Ϊ����һ��ָ�����Ҷ������ˡ���");

	carry_object("cynrobe")->wear();
	carry_object("fuchen")->wield();
	add_money(1000);

	create_family("����μ�",18,"����");
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char oldtitle[40];
	char msg[80];

	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;
	if (me->query_skill("kurong_changong",1) < 30 )
	{
		say("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�", me);
		SendMenu(me);
		return;
	}

	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
	{
		say("��ֻ��Ů���ӡ�", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  )
	{
		say("�Ҵ�����������������壬����ذɣ�", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "������������")) 
	{
		say("�ܺã���Ȼ���������͵�����Ϊū������ʹ��");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�", me);
		SendMenu(me);
		return;
	}
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "sun_book") || DIFFERSTR(ob->querystr("name"), "һ��ָ��"))
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "yuyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}



NPC_END;
