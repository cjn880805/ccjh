//dao_xiang2.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_xiang2);

virtual void create()
{
	set_name("������ʦ", "daoxiang chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",118);
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
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry",  "banruo_zhang");

	prepare_skill("strike", "banruo_zhang");

	create_family("������", 39, "����");

	set_inquiry("��ҩ", ask_me_1);
	set_inquiry("С����", ask_me_2);
		
	set("jin_count", 2);
	set("xiao_count",1);
	set("da_count",  1);

	carry_object("xu_cloth")->wear();
};

static char * ask_me_1(CNpc * me, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "������"))
			return "���뱾��������������֪�˻��Ӻ�̸��";

	if ( who->query_condition("bonze_drug" ) > 0 )
		return "���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if ( who->PresentName("jinchuang_yao", IS_ITEM) )
		return "���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (me->query("jin_count") < 1) return "�Բ��𣬽�ҩ�Ѿ�������";

	load_item("jinchuang_yao")->move(who);
	me->add("jin_count", -1);

	message_vision("$N���һ����ҩ��", who);
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";
}

static char * ask_me_2(CNpc * me, CChar * who)
{
	if ( DIFFERSTR(who->querystr("family/family_name"), "������"))
		return 	"���뱾��������������֪�˻��Ӻ�̸��";

	if ( who->query_condition("bonze_drug" ) > 0 )
		return 	"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if ( who->PresentName("xiaohuan_dan", IS_ITEM) )
		return 	"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if ( me->query("xiao_count") < 1) return "�Բ���С�����Ѿ�������";

	load_item("xiaohuan_dan")->move(who);
	me->add("xiao_count", -1);

	message_vision("$N���һ��С������", who);
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";
}

NPC_END;
