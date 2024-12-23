// quanzhen_qiu.c �𴦻�

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_qiu);

virtual void create()
{
	set_name("���ڻ�", "qiu zaiji");
	set("gender", "����");
	set("age", 36);
	set("class", "taoist");
	set("nickname","������");
	set("long","�����ǽ������˳ơ������ӡ������ڻ������ˣ����������������⣬��ĿԲ����˫ü�絶����ò���ϣ�ƽ���������");
	set("attitude", "heroism");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",taoist);
	set("foolid",37);
	set("title","ȫ������֮��");
	
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("xiantian_qigong", 220);    //��������
	set_skill("sword", 250);
	set_skill("quanzhen_jian",250);  //ȫ�潣
	set_skill("dodge", 200);
	set_skill("jinyan_gong", 200);   //���㹦
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("haotian_zhang", 220);    //�����
	set_skill("literate",160);
	set_skill("strike",180);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 2, "����");
	
	set("book_count",1);
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void init(CChar * me)
{
	if(userp(me))
	{
		remove_call_out(do_kill);
		call_out(do_kill, 5, me->object_id());
	}
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];
	
	if(! who || (me->environment())->query("no_fight")) return;
	
	if (DIFFERSTR(who->querystr("family/family_name"), "ȫ���"))
	{
		if (who->query("repute") > -5000) 
		{
			me->say("�����Ǳ����صأ����߶�С��Щ��");
		}
		else 
		{
			me->say(" ����ħͷ�����Ҵ�����ȫ���صأ���һ��Ҫɱ���㣡");
			me->kill_ob(who);
		}
	}
	else 
	{
		me->command(snprintf(msg,255,"smile %ld", who->object_id() ));
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("xiantian_qigong",1) < 80 )
	{
		say("��ı����ڹ��ķ������,�������Ը�������书��", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<30000) 
	{
		say("�����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��", ob);
		SendMenu(ob);
		return;
	}

	say("�ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPCQUANZHEN_END;