//du_e.h
//Lanwood 2000-01-10

SHAOLINDU_BEGIN(CNshaolin_du_e);

virtual void create()
{
	set_name("�ն�",  "du e");
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",	"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�ݻƣ���ͬһ�ο�ľ��");
	set("icon",old_monk);
	set("foolid",87);
	set("attitude", "peaceful");
	set("combat_exp", 3000000);
	set("score", 200000);

	set("str", 40);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("hp", 8000);
	set("max_hp", 15000);
	set("mp", 7000);
	set("max_mp", 4000);
	set("mp_factor", 200);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);
	
	set_skill("force", 250);
	set_skill("whip", 250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("unarmed", 250);
	set_skill("buddhism", 250);
	set_skill("literate", 200);

	set_skill("hunyuan_yiqi", 250);
	set_skill("riyue_bian", 250);
	set_skill("shaolin_shenfa", 250);

	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");

	
	set("count", 1);

	set("chat_chance_combat", 10);
	    
	set_inquiry("лѷ", "��лʩ���͹����������棬��Ȼ���ܹ���ħȦ�Ϳ��Դ����ߡ�");
	carry_object("changbian")->wield();
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("whip chan", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

/*
virtual void init(CChar * me)
{
	CNpc::init(me);

	if( userp(me) && ! is_fighting() ) 
	{
		if ( me->querystr"family/family_name") == "������" 
			&& me->query("family/generation") == 36 ) return;

        if ( me->present("basket")) return;   

		if ( EQUALSTR(me->querystr("family/family_name"), "������") 
			&& me->query("family/generation") > 36 		
			&& me->query("hp") < 50 ) 
		{
			me->move("����������ƺ");
			me->unconcious();
			return;
		}

		Do_Attack(this, me, TYPE_QUICK);

		me->set_temp("fighter", 1);
		
		Do_BiShi(this, me, "���ɷ�ħȦ", 0);
		call_out(do_halt, 10);

		return;
	}

	return;
}

static void do_halt(CContainer * ob, LONG param1, LONG param2)
{
	command("say �ðɣ����ס�֣� ��Ȼ���ܴ�����ħȦ��лʩ����ʹ��߰ɣ�");
	command("halt");
}
*/
SHAOLINDU_END;
