//dao_chen.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_chen);

virtual void create()
{
	set_name("������ʦ", "daochen chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",79);
	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "damo_jian");

	prepare_skill("strike", "banruo_zhang");
	create_family("������", 39, "����");

 	set("wuqi_count", 5);

    carry_object("xu_cloth")->wear();
	set("no_talk",1);

};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "������"))
	{
		if(strcmp(ask, "��ü��") == 0)
			return ask_me(me, "qimeigun");
		if(strcmp(ask, "�䵶") == 0)
			return ask_me(me, "jiedao");
		if(strcmp(ask, "����") == 0)
			return ask_me(me, "chanzhang");
		if(strcmp(ask, "����") == 0)
			return ask_me(me, "changjian");
		if(strcmp(ask, "Ƥ��") == 0)
			return ask_me(me, "changbian");
				
		AddMenuItem("�������ʦ��Ҫ��ü��", "��ü��", me);
		AddMenuItem("�������ʦ��Ҫ�䵶", "�䵶", me);
		AddMenuItem("�������ʦ��Ҫ����", "����", me);
		AddMenuItem("�������ʦ��Ҫ����", "����", me);
		AddMenuItem("�������ʦ��ҪƤ��", "Ƥ��", me);
		SendMenu(me);	
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int ask_me(CChar * me, char * wuqi)
{
    if ( me->PresentName(wuqi, IS_ITEM) )
	{
		say("���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�", me);
		SendMenu(me);
		return 1;
	}

	if (query("wuqi_count") < 1)
	{
		say("��Ǹ�������ò���ʱ�������Ѿ������ˡ�", me);
		SendMenu(me);
		return 1;
	}

	CContainer * ob = load_item(wuqi);
	ob->move(me);

	add("wuqi_count", -1);

	message_vision("������$Nһ��$n��", me, ob);

	say("��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ��ɱ�����顣", me);
	SendMenu(me);
	return 1;
}

NPC_END;
