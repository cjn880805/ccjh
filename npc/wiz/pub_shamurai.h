NPC_BEGIN(CNpub_shamurai);

void create()
{
	set_name( "������ߵĽ���");

	set("icon", young_man1);
	set("gender", "Ů��");
	set("age", 22);
	set("str", 40);
	set("dex", 40);
	set("con", 100);
	set("per", 31);
	set("long", "����һ����������ߣ�ȫ����װ�������佫������һƥ�����ؼ׵ľ������棬һ˫�߰����۾�͸���������ؿ����㡣");
	set("combat_exp", 1650000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("chat_chance_combat", 30);
        set_inquiry("����","����ʲô��������ͱ�����˵����");
        set_inquiry("����","������û�н�����ϰ�ߵģ������Ļ��ҵ��ǿ��Գ�ȫ�㡣");
	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("zhanjiang_jue", 180);
	set_skill("changquan", 300);
        set_skill("wudu_xinfa", 200);
        map_skill("parry", "zhanjiang_jue");
        map_skill("club", "zhanjiang_jue");
        map_skill("sword", "zhanjiang_jue");
        map_skill("force", "wudu_xinfa");
        map_skill("unarmed", "changquan");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("max_hp", 5800);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 100);
	set("score", 2000);

	carry_object("huaji")->Do_Action(DO_WIELD);
	carry_object("putongbishou")->Do_Action(DO_WIELD);
	carry_object("tiejia")->Do_Action(DO_WIELD);
	carry_object("tieshou")->wear();
	carry_object("doupeng")->wear();
	carry_object("cycle")->wear();
	carry_object("toukui")->wear();
	carry_object("tiehuyao")->wear();
	carry_object("tiehuwan")->wear();
	carry_object("pixue")->wear();
	carry_object("cuiyu")->wear();
	carry_object("mask")->wear();
	carry_object("huoqiang");
	carry_object("dadao");
}

char * chat_msg()
{
	switch(random(20))
	{
	case 0:
		return "������ߵĽ���˵�����������Ҫ����Ͷ���Ļ��ҵ��ǿ��Կ��ǡ�";
	case 1:
		return "������ߵĽ���˵�������������ȻҲ������������";
	}
	return 0;
}

int accept_fight(CChar * me)
{
	say("��ֻ��ɱ�ˣ�������䡣");
	kill_ob(me);
	return 1;
}

void die()
{
	message_vision("$N�³�һ�����Ѫ�������˵��ϣ�ժ��������ߣ�ԭ����һ����ò��Ů��ֻ����ǿ���Ŷ�������һ��Ц����Ц�����е��ѹ������������³�һ�����Ѫ���������ص�����ȥ", this);
	CNpc::die();
}

NPC_END;
