//qing_fa.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_fa);

virtual void create()
{
	set_name("�巨����", "qingfa biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("foolid",109);
	set_inquiry("���", ask_for_join);
	set_inquiry("����", ask_for_join);
	set("icon",young_monk);
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_hp", 1450);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang_quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");

	prepare_skill("cuff", "jingang_quan");

	create_family("������", 40, "����");
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

static char * ask_for_join(CNpc * npc, CChar * me)
{
	if( EQUALSTR(me->querystr("class"), "bonze" ))
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��";

	if( DIFFERSTR(me->querystr("gender"), "����") )
		return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣";

	me->set_temp("pending/join_bonze", 1);

	npc->say("�����ӷ����գ����գ�ʩ������������ҷ�������ܽ䡣", me);
	npc->AddMenuItem("�����ܽ�", "$0kneel $1", me);
	npc->AddMenuItem("ת���뿪", "", me);
	npc->SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0 && me->query_temp("pending/join_bonze"))
	{
		me->delete_temp("pending/join_bonze");
		return do_kneel(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_kneel(CChar * me)
{
	static char prename[4][3] = {"��", "��", "��", "��" };
	char msg[255];

	message_vision(	"$N˫�ֺ�ʮ�����������ع���������$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��", me, this);
	
	char name[40], new_name[40];

	strncpy(name, me->name(1), 40);
	name[2] = 0;

	snprintf(new_name, 40, "%s%s", prename[random(4)], name);


	me->set("bonze/old_name",me->querystr("name"));
	me->set_name( new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("pks") + me->query("mks"));
	me->set("shen_record", me->query("repute"));
    me->set("repute", 0l);
	me->UpdateMe();

	say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s��", new_name), me);
	say(g_Channel.do_emote(this, 0, "smile", 1), me);
	SendMenu(me);

	return 1;
}

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
		&& me->query("family/generation") <= query("family/generation") 
		&& ! me->query("family/user"))	//��������ʦ���ĸ߼���Ұ�. lanwood 2001/05/27
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
