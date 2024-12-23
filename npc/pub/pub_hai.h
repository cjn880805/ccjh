// pub_hai.c ������
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_hai);

virtual void create()
{
	set_name("���Ϲ�", "hai gonggong");

	set("icon", tipstaff);
	set("title", "����ǧ��");
	set("long",	"���Ƕ�����̫�ຣ���ڹ꣬��װ�İ������ģ������Ѱ�����֣����ü�����ͷ������̫̫��");
 	set("gender", "����");
	set("rank_info/respect", "����");
 	set("attitude", "heroism");
	set("class", "eunach");
	
	set("age", 60);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 40);
	set("max_hp", 3500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 15000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("pixie_jian", 50);
	map_skill("dodge", "pixie_jian");
	map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
	set("chat_chance", 15);
	
	set_inquiry("�Թ�", ask_for_zigong);
	set_inquiry("����", ask_for_gongzi);

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(4000);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("pending/zigong"))
	{
		if(strcmp(ask, "ok") == 0)
		{
			me->delete_temp("pending/zigong");
			return do_decide(me);
		}

		AddMenuItem("�á����ɡ�", "ok", me);
		AddMenuItem("�����ҿ��ǿ��ǡ����ɡ�", "", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

static char * ask_for_zigong(CNpc *who, CChar *me)
{
 	if(  EQUALSTR(me->querystr("gender"), "����") )
		return "����ͬ�����ˣ��αؿ�������ĵ���Ц��";
	
	if(  EQUALSTR(me->querystr("gender"), "Ů��") )
		return "�����ѷϣ���һ�����Ը������С���˴������֣�Ҫ��Ҫ���ԣ�";

	if ( me->query_str() > 28 )
		return "��λ�ú����ڴ�׳���Թ��а���հ�����ף����ס�";
	
	me->set_temp("pending/zigong", 1);
	return "�Թ�����λ������ò���ã��α�... ����ϣ����������Ǹ����Թ�֮�󣬲��ɺ�ڣ����������Ѷ��������ҡ�";
}

int do_decide(CChar *me)
{
	message_vision("$Nһҧ�����������¡���Ů��ұ��ۣ���$n��������嵽$N����֮�䣬����һ�࣬����$N��ʱ�ҽ�һ�����˹�ȥ����",me, this);
	say("�ˡ���");
	command("hehe");
	me->set("gender","����");
	me->set("class", "eunach");
//	me->add("combat_exp", 1000);
	me->unconcious();
	return 1;
}

static char * ask_for_gongzi(CNpc *who, CChar *me)
{
	int paytimes;
	
	if(  DIFFERSTR(me->querystr("gender"), "����") ) return "�ߣ����Թ�����̸���ʰɣ�";
	paytimes =  (me->query("mud_age")/7200);
	if (me->query("paytimes") < paytimes)
	{
		CMoney::Pay_Player(me, 1000);
		me->add("paytimes", 1);
		return "�����㱾�µķݶ�պðɡ�";
	}

	return "�۸����Ϻ�Ϳ���㱾�¹����Ѿ���ȡ���ˣ�";
}

NPC_END;