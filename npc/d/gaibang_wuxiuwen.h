//wuxiuwen.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_wuxiuwen);

virtual void create()
{
	set_name("С��","wu xiu wen");

	set("title", "����������");
	set("gender", "����");
	set("age", 21);
	set("long", "���Ǿ����Ķ����ӣ�����ǿ�ɣ������绢Ϯ�ˣ�ר�Ÿ�����ڡ�\n");
 	set("attitude", "peaceful");
 	set("icon",young_man1);
	
	set("per", 23);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set_inquiry("�ض�","������ʦĸ��");
	set_inquiry("�����","������ʦ����");
	set_inquiry("����",do_select);

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);

	set("huju_count", 2);
	set("beixin_count", 2);
	 
	set_skill("force", 50);			// �����ڹ�
	set_skill("huntian_qigong", 50);	// ��������
	set_skill("unarmed", 50);		// ����ȭ��
	set_skill("xianglong_zhang", 50);	// ����ʮ����
	set_skill("dodge", 50);			// ��������
	set_skill("xiaoyaoyou", 50);		// ��ң��
	set_skill("parry", 50);			// �����м�

	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

virtual void init(CChar * player)
{
	player->set_temp("pending/what",0l);
}

static char * do_select(CNpc * npc , CChar * player)
{
	player->set_temp("pending/what",1);

	npc->say("������Ҫʲô������?",player);

	npc->AddMenuItem("������","tiebeixin",player);
	npc->AddMenuItem("������","tieshou",player);
	npc->AddMenuItem("����","tiejia",player);
	npc->AddMenuItem("������","tiehuyao",player);
	npc->AddMenuItem("������","tiehuwan",player);
	npc->AddMenuItem("��ָ��","tiezhitao",player);
	npc->SendMenu(player);
	return "";
}

virtual int do_talk(CChar * player ,char * ask = NULL)
{
	if(! strlen(ask)) return 0;

	if(player->query_temp("pending/what"))
		return do_get(player,ask);

	return CNpc::do_talk(player,ask);
}

int do_get(CChar * player , char * select)
{
	char msg[255];
	CContainer * obj;

	player->set_temp("pending/what",0l);

	if(player->present(select))
	{
		say(snprintf(msg,255,"%s���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�",query_respect(player)),player);
		SendMenu(player);
		return 0;
	}

	if(DIFFERSTR(select, "tiebeixin") && query("huju_count")<1)
	{
		say("��Ǹ�������ò���ʱ�򣬷����Ѿ������ˡ�",player);
		SendMenu(player);
		return 0;
	}

	if(EQUALSTR(select, "tiebeixin") && query("beixin_count")<1)
	{
		say("��Ǹ�������ò���ʱ�������Ѿ������ˡ�",player);
		SendMenu(player);
		return 0;
	}
	
	obj=load_item(select);
	obj->move(player);

	if(EQUALSTR(select, "tiebeixin"))
		add("beixin_count",-1);
	else 
		add("huju_count",-1);

	message_vision(snprintf(msg,255,"С���$Nһ��%s",obj->name()),player);
	
	say("��ȥ�ɡ�����Ҫ��ס���������Ƿ��������ƾ�˷������ˡ�",player);
	SendMenu(player);

	return 1;
}
NPC_END;
