//qing_wu.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_wu);

virtual void create()
{
	set_name("���ޱ���", "qingwu biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",99);
	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("blade", 30);
	set_skill("cibei_dao", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	create_family("������", 40, "����");

	carry_object("jiedao")->wield();
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( DIFFERSTR(me->querystr("gender"), "����") )
	{
		say("�����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����", me);
		SendMenu(me);
		return;
	}
	
	if ( EQUALSTR(me->querystr("family/family_name"), "������") 
		&& me->query("family/generation") <= query("family/generation") )
	{
		say("�⣬ƶɮ����ҵ� !", me);
		SendMenu(me);
		return;
	}

	if( DIFFERSTR(me->querystr("class"), "bonze") )
		say("�����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	else
		say("�����ӷ����գ����գ�");

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

NPC_END;
