//yin.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_yin);

virtual void create()
{
	set_name("�����","yin liheng");
	set("nickname", "�䵱����");
	set("long","�����������������������ࡣ��������ʮ�꣬�����ܸɣ�������������һ�");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("foolid",133);	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 9600);
	set("mp", 4500);
	set("max_mp", 4500);
	set("mp_force", 150);
    set("combat_exp", 1800000);
	set("combat_exp", 1400000);
	set("score", 600000);

	set_skill("force", 150);
	set_skill("taiji_shengong", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 150);
	set_skill("taiji_quan", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("taiji_jian", 150);
	set_skill("taoism", 150);
	set_skill("literate", 160);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("�䵱��", 2, "����");
	set("chat_chance_combat", 40);

	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

virtual void init(CChar * player)
{
	CNpc::init(player);
	if(userp(player) && !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, player->object_id());
	}
}


static void do_greeting(CContainer * ob , LONG param1 ,  LONG param2)
{
	CChar * npc = (CChar *) ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);

	if( ! player) return;

	if (!(npc->environment())->query("no_fight"))
	{
		if(DIFFERSTR(player->querystr("family/family_name"), "�䵱��") ) 
		{
			if (player->query("repute")>-1000)      
			{
				npc->say("�������䵱�صأ���������Ϲ��ʲô��");				
			}
		   else
		   {
				npc->say("һ��Ҫɱ�����⽭�����࣡");
				npc->kill_ob(player); 
		   }
		}    
	}       
}


virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("repute") < 10000 )
	 {
		say("���䵱���������������ɣ��Ե���Ҫ���ϡ�",player);
		say("���ڵ��з����Ƿ����ò�����",player);
		SendMenu(player);
		return;
	 }
	if (player->query_skill("taiji_shengong",1) < 80 ||player->query_skill("force",1) < 80 )
	{
		say("���䵱����ע���ڹ��ķ���Ӧ�����ڹ��϶��µ㹦��?",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("taoism",1) < 80)
	{
		say("ϰ����Ϊ��ǿ����,һζ�������ǲ���ȡ��!",player);
		say("�ҿ��㻹��Ҫ���������Է�����������,�������ĵ����ķ�",player);
		SendMenu(player);
		return;
	}
	say("�ðɣ��Ҿ��������ˡ�",player);
	say("ϣ�����ܺú��ù�,�������䵱����!",player);
	SendMenu(player);

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	if(DIFFERSTR(player->querystr("class"), "taoist"))
		player->set("class", "taoist");
}


NPC_END;